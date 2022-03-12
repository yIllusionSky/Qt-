#include "mywidget.h"
#include<QPainter>
#include<QMouseEvent>
#include"widget.h"
#include<qrandom.h>
#include<QFileDialog>
#define SIZEOF_IMAGE 350
#define SIZEOF_IMAGE_SMALL 70

myWidget::myWidget(QWidget *parent)
    : QWidget{parent}
{
    isStart=false;
}

void myWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush(QColor(170, 170, 255));
    painter.fillRect(rect(),brush);
    if(isStart)
    {

        for(qsizetype y=0;y<5;y++)
        {
            for(qsizetype x=0;x<5;x++)
            {
                if(doArray[x+1][y+1]!=-1)
                {

                    painter.drawPixmap(x*SIZEOF_IMAGE_SMALL,y*SIZEOF_IMAGE_SMALL,pushArray[doArray[x+1][y+1]]);
                }
            }
        }
    }
    else
    {
        painter.drawPixmap(0,0,savePixMap);
    }
}

void myWidget::mousePressEvent(QMouseEvent *event)
{
if(isStart)
{

    if(changeIndex(event->x()/SIZEOF_IMAGE_SMALL+1,event->y()/SIZEOF_IMAGE_SMALL+1)==true)
    {
        qobject_cast<Widget*>(this->parent())->oneTick();
        if(isWin())
        {
            qobject_cast<Widget*>(this->parent())->isWin();
            return;
        }
        this->update();
    }
}
else
{
    QString path = QFileDialog::getOpenFileName(this, tr("选择图片"), ".", tr("Image Files(*.jpg *.png *.bmp *.jpeg)"));
    if(path.isEmpty()) return;
    else getImageArray(path);
    update();
}
}
bool myWidget::changeIndex(int x, int y)
{
    int t=0;

    //不在最左边
    if(doArray[x][y-1]==-1)
    {
        t=doArray[x][y];
        doArray[x][y]=doArray[x][y-1];
        doArray[x][y-1]=t;
        return true;
    }
    else if(doArray[x][y+1]==-1)
    {
        t=doArray[x][y];
        doArray[x][y]=doArray[x][y+1];
        doArray[x][y+1]=t;
        return true;
    }
    else if(doArray[x-1][y]==-1)
    {
        t=doArray[x][y];
        doArray[x][y]=doArray[x-1][y];
        doArray[x-1][y]=t;
        return true;
    }
    else if(doArray[x+1][y]==-1)
    {
        t=doArray[x][y];
        doArray[x][y]=doArray[x+1][y];
        doArray[x+1][y]=t;
        return true;
    }
    return false;
}
void myWidget::randomArray()
{
    std::array<int,25> myArray;
    for(qsizetype index=0;index<25;index++)
    {
        myArray[index]=index;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 g(seed);
    std::shuffle(myArray.begin(), myArray.end(), g);
    myArray[24]=-1;
   for(qsizetype y=0;y<7;y++)
    {
        for(qsizetype x=0;x<7;x++)
        {
            if(x==0||x==6||y==0||y==6) doArray[x][y]=-2;
            else doArray[x][y]=myArray[(x-1)+(y-1)*5];

        }
    }
}

void myWidget::getImageArray(QString imagePath)
{

    savePixMap=QPixmap::fromImage(QImage(imagePath)).scaled(SIZEOF_IMAGE,SIZEOF_IMAGE,Qt::IgnoreAspectRatio);
    if(savePixMap.isNull()){
       savePixMap=QPixmap::fromImage(QImage(":/Image/LHY.png")).scaled(SIZEOF_IMAGE,SIZEOF_IMAGE,Qt::IgnoreAspectRatio);
    }
    for(qsizetype y=0;y<5;y++)
    {
        for(qsizetype x=0;x<5;x++)
        {
            pushArray[x+y*5]=savePixMap.copy(SIZEOF_IMAGE/5*x,SIZEOF_IMAGE/5*y,SIZEOF_IMAGE/5,SIZEOF_IMAGE/5);
        }
    }

}

bool myWidget::isWin()
{
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {

            if(doArray[i][j]!=-1&&doArray[i][j]!=(i-1)+(j-1)*5) {
                return false;
            }
        }
    }
    return true;
}

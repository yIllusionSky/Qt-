#include "widget.h"
#include "ui_widget.h"
#include<QResource>
#include<QPixmap>
#include<qrandom.h>
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QResource::registerResource(QApplication::applicationDirPath()+"/pic.rcc");
    ui->setupUi(this);
    ui->startOrEnd->setIcon(QIcon(QPixmap::fromImage(QImage(":/Image/Image/start.png"))));
    ui->startOrEnd->setIconSize(QSize(64,64));
    this->isClick=false;
    ui->gameMain->getImageArray(":/Image/LHY.png");
    //让控件居中
    ui->label_5->setVisible(false);
    isStart = false;     //初始为还未计时
    timers=new QTimer;
    timers->setInterval(1000);
    connect(timers,&QTimer::timeout,this,&Widget::updateTime);

    steps=0;
}
void Widget::updateTime()
{
    steps++;
    ui->timeLabel->setText(QString::number(steps));
}
Widget::~Widget()
{
     QResource::unregisterResource(QApplication::applicationDirPath()+"/pic.rcc");
     delete ui;
}

void Widget::oneTick()
{
    clickCount++;
    ui->ClickLabel->setText(QString::number(clickCount));
}

void Widget::isWin()
{

    ui->startOrEnd->setIcon(QIcon(QPixmap::fromImage(QImage(":/Image/Image/start.png"))));
    this->timers->stop();
    ui->gameMain->isStart=false;
    ui->gameMain->update();
    isClick=false;
    ui->label_5->setVisible(true);
}


void Widget::on_startOrEnd_pressed()
{
    if(isClick==false)
    {
        ui->startOrEnd->setIcon(QIcon(QPixmap::fromImage(QImage(":/Image/Image/stop.png"))));
        ui->label_5->setVisible(false);
        this->clickCount=0;
        this->steps=0;
        ui->timeLabel->setText(QString::number(steps));
        ui->ClickLabel->setText(QString::number(clickCount));

       do
        {
            ui->gameMain->randomArray();
        }while(ui->gameMain->isWin());
        ui->gameMain->isStart=true;
        ui->gameMain->update();
        this->timers->start();

    }
    else
    {
        ui->startOrEnd->setIcon(QIcon(QPixmap::fromImage(QImage(":/Image/Image/start.png"))));
        this->timers->stop();
        ui->gameMain->isStart=false;
        ui->gameMain->update();

    }
    isClick=!isClick;
}






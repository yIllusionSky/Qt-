#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

typedef int* INTPTR;
class myWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = nullptr);
    bool isStart;
    void randomArray();
    void getImageArray(QString imagePath);
    bool isWin();

signals:


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

    int doArray[7][7];
    QPixmap pushArray[25];
    QPixmap savePixMap;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    bool changeIndex(int x,int y);
};

#endif // MYWIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void oneTick();
    qsizetype clickCount;
    void isWin();
private slots:
    void on_startOrEnd_pressed();
    void updateTime();


private:
    Ui::Widget *ui;
    bool isClick;
    QTimer * timers;
    int steps;
    bool isStart;


};
#endif // WIDGET_H

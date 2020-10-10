#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"dialog.h"
#include"dialog1.h"
#include"dialog2.h"
#include"dialogboss.h"
#include <QMainWindow>
#include<QFont>
#include<QLabel>
#include<QMediaPlayer>
#include<QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QFont font;
    Dialog w1;//第一关窗口
    Dialog w1_re;//第一关重新开始的窗口
    Dialog1 w2;//选择窗口
    Dialog2 w3;//第二关窗口
    DialogBoss w4;//boss关卡的窗口
    QMediaPlayer *player;//音乐
    void close1();//关闭第一关窗口
    void close2();//关闭选择窗口
    void close3();//关闭第二关窗口
    void close1_re();//关闭重新开始的窗口
    void secondopen();//第二关打开
    void restart1();//重新开始第一关
    void bossopen();//打开boss关卡
    void close4();//关闭boss关卡
signals:
    void signalstart();
private slots:
    void on_buttonstart_clicked();//开始游戏

    void on_buttonclose_clicked();//退出游戏

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player=new QMediaPlayer;
    setFixedSize(800,600);
    setWindowTitle("飞机大战");
    font.setPointSize(30);
    ui->label->setFont(font);
    connect(this,&MainWindow::signalstart,&w1,&Dialog::chushihuascene);//开始第一关
    connect(&w1,&Dialog::signal,this,&MainWindow::close1);//关闭第一关的窗口，打开新的窗口
    connect(&w2,&Dialog1::mysignal,this,&MainWindow::close2);//接收返回的信号，返回主窗口
    connect(&w2,&Dialog1::signalclose,this,&MainWindow::close2);//关闭选择窗口
    connect(&w2,&Dialog1::signalrestart,this,&MainWindow::restart1);//重新开始第一关
    connect(&w2,&Dialog1::signalrestart,&w1_re,&Dialog::chushihuascene);//开始新的第一关
    connect(&w1_re,&Dialog::signal,this,&MainWindow::close1_re);//关闭窗口，打开选择窗口
    connect(&w2,&Dialog1::signalcontinue,this,&MainWindow::secondopen);//打开第二关的窗口
    connect(&w2,&Dialog1::signalcontinue,&w3,&Dialog2::chushihuascene);//开始第二关
    connect(&w3,&Dialog2::signal2,this,&MainWindow::close3);//关闭第二关的窗口
    connect(&w3,&Dialog2::signalboss,this,&MainWindow::bossopen);//打开boss关卡的窗口
    connect(&w3,&Dialog2::signalboss,&w4,&DialogBoss::chushihuascene);//开始boss关卡
    connect(&w4,&DialogBoss::signal3,this,&MainWindow::close4);//关闭boss关卡
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonstart_clicked()
{
    w1.show();//第一关窗口打开
    //启动背景音乐
    player->setMedia(QUrl::fromLocalFile("D:\\Qt\\qt\\PlaneWar\\res\\background.mp3"));
    player->play();
    emit signalstart();
}

void MainWindow::on_buttonclose_clicked()
{
    qApp->quit();//退出游戏
}

void MainWindow::close1()
{
    w1.close();//第一关窗口关闭
    this->show();
    w2.show();//选择窗口打开
    player->pause();//音乐停止
}

void MainWindow::close2()
{
    w2.close();//选择窗口关闭
    this->show();
}

void MainWindow::close3()
{
    w3.close();//第二关窗口关闭
    this->show();
    player->pause();//音乐停止
}

void MainWindow::close1_re()
{
    w1_re.close();//新的第一关窗口关闭
    this->show();
    w2.show();//打开选择窗口
    player->pause();//音乐停止
}

void MainWindow::secondopen()
{
    w3.show();//第二关窗口打开
    //播放音乐
    player->setMedia(QUrl::fromLocalFile("D:\\Qt\\qt\\PlaneWar\\res\\background.mp3"));
    player->play();
}

void MainWindow::restart1()
{
    w1_re.show();//新的第一关打开
    //播放音乐
    player->setMedia(QUrl::fromLocalFile("D:\\Qt\\qt\\PlaneWar\\res\\background.mp3"));
    player->play();
}

void MainWindow::bossopen()
{
    w4.show();//boss关卡打开
    //播放音乐
    player->setMedia(QUrl::fromLocalFile("D:\\Qt\\qt\\PlaneWar\\res\\background.mp3"));
    player->play();
}

void MainWindow::close4()
{
    w4.close();//boss关卡关闭
    this->show();
    player->pause();//音乐停止
}

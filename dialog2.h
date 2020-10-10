#ifndef DIALOG2_H
#define DIALOG2_H

#include"map2.h"
#include"hostplane2.h"
#include"bullet2.h"
#include"bomb.h"
#include"enemyplane2.h"
#include"dialog.h"
#include <QDialog>
#include<QIcon>
#include<QPaintEvent>
#include<QPixmap>
#include<QPainter>
#include<time.h>
#include<QTimer>
#include<QSound>
#include<QPoint>
#include<QMessageBox>
#include<QDebug>
namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    void chushihuascene();//初始化场景
    void play();//启动游戏
    void updateposition();//更新坐标
    QTimer mtimer;//定时器
    void paintEvent(QPaintEvent *);//绘图事件
    void keyPressEvent(QKeyEvent *event);
    void PressUp();
    void PressDown();
    void PressLeft();
    void PressRight();
    void enemytoscene();//敌机出场
    void collision();//碰撞检测
    void judge();//判断游戏是否结束
    int score;//得分
    bool state;//判断状态
    Map2 map;//地图对象
    HostPlane2 hostplane;//飞机对象
    EnemyPlane2 enemys[20];//敌机数组
    int recorder;//敌机出场间隔记录
    int num;//敌机数量
    Bomb bombs[20];//爆炸数组
    bool flag=1;

private:
    Ui::Dialog2 *ui;
signals:
    void signal2();
    void signalboss();
};

#endif // DIALOG2_H

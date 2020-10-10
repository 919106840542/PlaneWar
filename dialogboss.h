#ifndef DIALOGBOSS_H
#define DIALOGBOSS_H

#include"bossplane.h"
#include"map2.h"
#include"hostplane2.h"
#include"bomb.h"
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
class DialogBoss;
}

class DialogBoss : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBoss(QWidget *parent = 0);
    ~DialogBoss();
    void chushihuascene();//初始化场景
    void updateposition();//更新坐标
    void keyPressEvent(QKeyEvent *event);
    void PressUp();
    void PressDown();
    void PressLeft();
    void PressRight();
    void paintEvent(QPaintEvent *);//绘图事件
    void bosstoscene();//开始游戏
    void bossposition();//设置坐标
    void bossshot();//发射子弹
    void bossjudge();//判断游戏是否结束
    Map2 map;//地图对象
    HostPlane2 hostplane;//飞机对象
    BossPlane bossplane;//boss敌机
    QTimer bosstimer;//boss敌机移动定时器
    int flag=1;//判断向左还是向右移动
    int life=0;//血条是满的
    Bomb bombs[20];//爆炸数组
signals:
    signal3();
private:
    Ui::DialogBoss *ui;
};

#endif // DIALOGBOSS_H

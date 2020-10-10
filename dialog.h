#ifndef DIALOG_H
#define DIALOG_H

#include"map.h"
#include"hostplane.h"
#include"bullet.h"
#include"bomb.h"
#include"enemyplane.h"
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
#include<QMutex>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void chushihuascene();//初始化场景
    QTimer mtimer;//定时器
    void play();//启动游戏
    void updateposition();//更新坐标
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
    Map map;//地图对象
    HostPlane hostplane;//飞机对象
    EnemyPlane enemys[20];//敌机数组
    int recorder;//敌机出场间隔记录
    int num;
    Bomb bombs[20];//爆炸数组
private:
    Ui::Dialog *ui;
    QMutex mutex;
signals:
    void signal();
};
#endif // DIALOG_H

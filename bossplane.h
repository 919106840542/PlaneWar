#ifndef BOSSPLANE_H
#define BOSSPLANE_H

#include"bossbullet.h"
#include<QPixmap>
#include<QRect>
class BossPlane
{
public:
    BossPlane();
    void setPosition(int x,int y);//更新坐标
    void shoot();
    QPixmap mboss;//创建第二关boss敌机对象
    //位置
    int X;
    int Y;
    QRect rect;//boss敌机的矩形边框
    int speed;//速度
    BossBullet mbullets[30];
    int recorder;
};

#endif // BOSSPLANE_H

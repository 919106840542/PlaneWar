#ifndef HOSTPLANE2_H
#define HOSTPLANE2_H

#include"bullet2.h"
#include<QPixmap>
#include<QRect>
class HostPlane2
{
public:
    HostPlane2();
    void shoot();//发射子弹
    void setPosition(int x,int y);//设置飞机位置
    QPixmap mplane2;
    int X;//飞机坐标
    int Y;
    QRect mrect;//飞机的矩形边框
    Bullet2 mbullets[30];//弹夹
    int recorder;//发射间隔记录
};

#endif // HOSTPLANE2_H

#ifndef HOSTPLANE_H
#define HOSTPLANE_H

#include"bullet.h"
#include<QPixmap>
#include<QRect>
class HostPlane
{
public:
    HostPlane();
    void shoot();//发射子弹
    void setPosition(int x,int y);//设置飞机位置
    QPixmap mplane;
    int X;//飞机坐标
    int Y;
    QRect mrect;//飞机的矩形边框
    Bullet mbullets[30];//弹夹
    int recorder;//发射间隔记录
};

#endif // HOSTPLANE_H

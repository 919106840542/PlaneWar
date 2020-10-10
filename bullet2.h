#ifndef BULLET2_H
#define BULLET2_H

#include<QPixmap>
#include<QRect>
class Bullet2
{
public:
    Bullet2();
    void updatePosition();//更新子弹坐标
    QPixmap bullet;//第二关子弹资源对象
    //子弹坐标
    int X;
    int Y;
    int speed;//子弹移动速度
    bool free;//子弹是否闲置
    QRect rect;//子弹的矩形边框（用于碰撞检测）
};

#endif // BULLET2_H

#ifndef BOSSBULLET_H
#define BOSSBULLET_H

#include<QPixmap>
#include<QRect>
class BossBullet
{
public:
    BossBullet();
    void updatePosition();//更新子弹坐标
    QPixmap bullet;//子弹资源对象
    //子弹坐标
    int X;
    int Y;
    int speed;//子弹移动速度
    bool free;//子弹是否闲置
    QRect rect;//子弹的矩形边框（用于碰撞检测）
};

#endif // BOSSBULLET_H

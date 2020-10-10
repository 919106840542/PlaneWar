#include "bullet.h"

Bullet::Bullet()
{
    bullet.load(":/res/smallbullet.png");//加载子弹资源
    X=500*0.5-bullet.width()*0.5;//子弹坐标
    Y=750;
    free=true;//子弹状态
    speed=20;//子弹速度
    rect.setWidth(bullet.width());//子弹矩形框
    rect.setHeight(bullet.height());
    rect.moveTo(X,Y);

}

void Bullet::updatePosition()
{
    //如果子弹是空闲状态，不需要进行坐标计算
    if(free)
    {
        return;
    }
    Y-=speed;//子弹向上移动
    rect.moveTo(X,Y);
    if(Y<=-rect.height())
    {
        free=true;
    }
}

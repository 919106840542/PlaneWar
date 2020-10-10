#include "enemyplane2.h"

EnemyPlane2::EnemyPlane2()
{
    enemy.load(":/res/enemy2.png");//加载第二关敌机资源
    //敌机位置
    X=0;
    Y=0;
    free=true;//敌机状态
    speed=5;//敌机速度
    //敌机矩形
    rect.setWidth(enemy.width());
    rect.setHeight(enemy.height());
    rect.moveTo(X,Y);
    recorder=0;
}

void EnemyPlane2::shoot()
{
    recorder++;
    if(recorder<20)
    {
        return;
    }
    recorder=0;
    for(int i=0;i<30;i++)
    {
        //如果是空闲子弹，进行发射
        if(mbullets[i].free)
        {
            mbullets[i].free=false;//将子弹空闲状态改为假
            //设置发射子弹坐标
            mbullets[i].X=X+rect.width()*0.5-10;
            mbullets[i].Y=Y+rect.height();
            break;
        }
    }
}

void EnemyPlane2::updatePosition()
{
    //空闲状态，不计算坐标
    if(free)
    {
        return;
    }
    Y+=speed;
    rect.moveTo(X,Y);
    if(Y>=750+rect.height())
    {
        free=true;
    }
}

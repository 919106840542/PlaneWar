#include "bossplane.h"

BossPlane::BossPlane()
{
    mboss.load(":/res/enemyboss.ico");//加载boss敌机资源
    //boss敌机位置
    X=500*0.5-mboss.width()*0.5;
    Y=0;
    speed=3;//boss敌机速度
    //boss敌机矩形
    rect.setWidth(mboss.width());
    rect.setHeight(mboss.height());
    rect.moveTo(X,Y);
    recorder=0;
}

void BossPlane::setPosition(int x,int y)
{
    X=x;
    Y=y;
    rect.moveTo(X,Y);
}

void BossPlane::shoot()
{
    recorder++;
    if(recorder<60)
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

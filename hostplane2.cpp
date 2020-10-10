#include "hostplane2.h"

HostPlane2::HostPlane2()
{
    mplane2.load(":/res/hostplane.png");//初始化加载飞机图片资源
    X=500*0.5-mplane2.width()*0.5;//初始化坐标
    Y=750-mplane2.height();
    mrect.setWidth(mplane2.width());//初始化矩形边框
    mrect.setHeight(mplane2.height());
    mrect.moveTo(X,Y);
    recorder=0;//初始化发射间隔记录
}

void HostPlane2::shoot()
{
    recorder++;//累加时间间隔记录
    //判断如果时间间隔未达到发射间隔，直接return
    if(recorder<20)
    {
        return;
    }
    recorder=0;//重置时间间隔发射记录
    //发射子弹
    for(int i=0;i<30;i++)
    {
        //如果是空闲子弹，进行发射
        if(mbullets[i].free)
        {
            mbullets[i].free=false;//将子弹空闲状态改为假
            //设置发射子弹坐标
            mbullets[i].X=X+mrect.width()*0.5-10;
            mbullets[i].Y=Y-25;
            break;
        }
    }
}

void HostPlane2::setPosition(int x,int y)
{
    X=x;
    Y=y;
    mrect.moveTo(X,Y);
}

#include "bomb2.h"

Bomb2::Bomb2()
{
    QString str=QString(":/res/bomb.png");//初始化爆炸图片数组
    pixarr.push_back(QPixmap(str));
    //初始化坐标
    X=0;
    Y=0;
    free=true;//初始化空闲状态
    index=0;//当前播放图片下标
    recorder2=0;//爆炸间隔记录

}

void Bomb2::updateInfo()
{
    if(free)
    {
        return;
    }
    recorder2++;
    if(recorder2<25)
    {
        //记录爆炸间隔未到，直接return，不需要切图
        return;
    }
    recorder2=0;//重置记录
    index++;//切换爆炸播放图片
    //如果计算的下标大于6，重置为0
    if(index>0)
    {
        index=0;
        free=true;
    }

}

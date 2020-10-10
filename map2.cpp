#include "map2.h"

Map2::Map2()
{
    map1.load(":/res/map2.jpg");//初始化加载第二关地图对象
    map2.load(":/res/map2.jpg");
    map1_y=-750;//设置地图起始y轴坐标
    map2_y=0;
    scroll=2;//设置地图滚动速度
}

void Map2::mapPosition()
{
    map1_y+=scroll;//处理第一张图片滚动
    if(map1_y>=0)
    {
        map1_y=-750;
    }
    map2_y+=scroll;//处理第二张图片滚动
    if(map2_y>=750)
    {
        map2_y=0;
    }
}

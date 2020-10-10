#ifndef MAP_H
#define MAP_H

#include<QPixmap>
#include<QPaintEvent>
class Map
{
public:
    Map();
    void mapPosition();//地图滚动坐标计算
    //地图图片对象
    QPixmap map1;
    QPixmap map2;
    //地图y轴坐标
    int map1_y;
    int map2_y;
    int scroll;//地图滚动幅度
};

#endif // MAP_H

#ifndef MAP2_H
#define MAP2_H

#include<QPixmap>
#include<QPaintEvent>
class Map2
{
public:
    Map2();
    void mapPosition();//地图滚动坐标计算
    //第二关地图图片对象
    QPixmap map1;
    QPixmap map2;
    //地图y轴坐标
    int map1_y;
    int map2_y;
    int scroll;//地图滚动幅度
};

#endif // MAP2_H

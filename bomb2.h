#ifndef BOMB2_H
#define BOMB2_H

#include<QPixmap>
#include<QVector>
#include<QString>
class Bomb2
{
public:
    Bomb2();
    void updateInfo();//更新信息
    QVector<QPixmap> pixarr;//爆炸资源数组
    //爆炸位置
    int X;
    int Y;
    bool free;//爆炸状态
    int recorder2;//爆炸切图的时间间隔
    int index;//爆炸时加载的图片下标
};

#endif // BOMB2_H

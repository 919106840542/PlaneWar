#ifndef BOMB_H
#define BOMB_H

#include<QPixmap>
#include<QVector>
#include<QString>
class Bomb
{
public:
    Bomb();
    void updateInfo();//更新信息
    QVector<QPixmap> pixarr;//爆炸资源数组
    //爆炸位置
    int X;
    int Y;
    bool free;//爆炸状态
    int recorder;//爆炸切图的时间间隔
    int index;//爆炸时加载的图片下标
};

#endif // BOMB_H

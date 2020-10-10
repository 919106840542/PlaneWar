#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include<QPixmap>
#include<QRect>
class EnemyPlane
{
public:
    EnemyPlane();
    void updatePosition();//更新坐标
    QPixmap enemy;//创建敌机对象
    //位置
    int X;
    int Y;
    QRect rect;//敌机的矩形边框
    bool free;//状态
    int speed;//速度
};

#endif // ENEMYPLANE_H

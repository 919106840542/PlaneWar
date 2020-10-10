#ifndef ENEMYPLANE2_H
#define ENEMYPLANE2_H

#include"enemybullet.h"
#include<QPixmap>
#include<QRect>
class EnemyPlane2
{
public:
    EnemyPlane2();
    void updatePosition();//更新坐标
    void shoot();
    QPixmap enemy;//创建第二关敌机对象
    //位置
    int X;
    int Y;
    QRect rect;//敌机的矩形边框
    bool free;//状态
    int speed;//速度
    EnemyBullet mbullets[30];
    int recorder;
};

#endif // ENEMYPLANE2_H

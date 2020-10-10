#include "enemyplane.h"

EnemyPlane::EnemyPlane()
{
    enemy.load(":/res/enemy1.png");//加载敌机资源
    //敌机位置
    X=0;
    Y=0;
    free=true;//敌机状态
    speed=3;//敌机速度
    //敌机矩形
    rect.setWidth(enemy.width());
    rect.setHeight(enemy.height());
    rect.moveTo(X,Y);

}

void EnemyPlane::updatePosition()
{
    //空闲状态，不计算坐标
    if(free)
    {
        return;
    }
    Y+=speed;
    rect.moveTo(X,Y);
    if(Y>=750+rect.height())
    {
        free=true;
    }

}

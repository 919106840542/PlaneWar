#include "dialogboss.h"
#include "ui_dialogboss.h"

DialogBoss::DialogBoss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBoss)
{
    ui->setupUi(this);

}

DialogBoss::~DialogBoss()
{
    delete ui;
}

void DialogBoss::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_W:
    PressUp();
    break;
    case Qt::Key_S:
    PressDown();
    break;
    case Qt::Key_A:
    PressLeft();
    break;
    case Qt::Key_D:
    PressRight();
    break;
    default:
        return;
    }
    update();
}

void DialogBoss::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,map.map1_y,map.map1);
    painter.drawPixmap(0,map.map2_y,map.map2);
    painter.drawPixmap(hostplane.X,hostplane.Y,hostplane.mplane2);//绘制飞机
    //绘制子弹
    for(int i=0;i<30;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!hostplane.mbullets[i].free)
        {
            painter.drawPixmap(hostplane.mbullets[i].X,hostplane.mbullets[i].Y,hostplane.mbullets[i].bullet);
        }
    }
    //绘制boss敌机
    painter.drawPixmap(bossplane.X,bossplane.Y,bossplane.mboss);
        for(int i=0;i<30;i++)
        {
            if(!bossplane.mbullets[i].free)
            {
                painter.drawPixmap(bossplane.mbullets[i].X,bossplane.mbullets[i].Y,bossplane.mbullets[i].bullet);
            }
        }
        //绘制爆炸图片
        for(int i=0;i<20;i++)
        {
            if(!bombs[i].free)
            {
                painter.drawPixmap(bombs[i].X,bombs[i].Y,bombs[i].pixarr[bombs[i].index]);
            }
        }
}

void DialogBoss::chushihuascene()
{
    setWindowTitle("boss");
    setFixedSize(500,750);
    setWindowIcon(QIcon(":/res/label.ico"));//设置图标
    bosstimer.setInterval(18);//设置boss敌机定时器
    bosstoscene();
}

void DialogBoss::bosstoscene()
{
    bosstimer.start();//boss敌机定时器开始
    connect(&bosstimer,&QTimer::timeout,[=](){
        updateposition();
        update();
        bossposition();
        bossshot();
        bossjudge();
    });
}

void DialogBoss::updateposition()
{
    map.mapPosition();//更新地图坐标
    hostplane.shoot();//发射子弹
    //计算子弹坐标
    for(int i=0;i<30;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!hostplane.mbullets[i].free)
        {
            hostplane.mbullets[i].updatePosition();
        }
    }
    //计算爆炸播放的图片
    for(int i=0;i<20;i++)
    {
        if(!bombs[i].free)
        {
            bombs[i].updateInfo();
        }
    }
}

void DialogBoss::PressUp()
{
    //向上移动
    hostplane.Y-=30;
    int x=hostplane.X;
    int y=hostplane.Y;
    //边界检测
    if(x<=0)
    {
        x=0;
    }
    if(x>=500-hostplane.mrect.width())
    {
        x=500-hostplane.mrect.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=750-hostplane.mrect.height())
    {
        y=750-hostplane.mrect.height();
    }
    hostplane.setPosition(x,y);
}

void DialogBoss::PressDown()
{
    //向下移动
    hostplane.Y+=30;
    int x=hostplane.X;
    int y=hostplane.Y;
    //边界检测
    if(x<=0)
    {
        x=0;
    }
    if(x>=500-hostplane.mrect.width())
    {
        x=500-hostplane.mrect.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=750-hostplane.mrect.height())
    {
        y=750-hostplane.mrect.height();
    }
    hostplane.setPosition(x,y);
}

void DialogBoss::PressLeft()
{
    //向左移动
    hostplane.X-=30;
    int x=hostplane.X;
    int y=hostplane.Y;
    //边界检测
    if(x<=0)
    {
        x=0;
    }
    if(x>=500-hostplane.mrect.width())
    {
        x=500-hostplane.mrect.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=750-hostplane.mrect.height())
    {
        y=750-hostplane.mrect.height();
    }
    hostplane.setPosition(x,y);
}

void DialogBoss::PressRight()
{
    //向右移动
    hostplane.X+=30;
    int x=hostplane.X;
    int y=hostplane.Y;
    //边界检测
    if(x<=0)
    {
        x=0;
    }
    if(x>=500-hostplane.mrect.width())
    {
        x=500-hostplane.mrect.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=750-hostplane.mrect.height())
    {
        y=750-hostplane.mrect.height();
    }
    hostplane.setPosition(x,y);
}

void DialogBoss::bossposition()
{
    //boss敌机坐标设置
    int x=bossplane.X;
    int y=bossplane.Y;
    //判断向左还是向右移动
    if(x>0&&(flag%2))
    {
        x-=bossplane.speed;
    }
    if(x<=0)
    {
        x=0;
        flag++;
    }
    if(!(flag%2))
    {
        x+=bossplane.speed;
    }
    if(x>=500-bossplane.rect.width())
    {
        x=500-bossplane.rect.width();
        flag++;
    }
    bossplane.setPosition(x,y);
}

void DialogBoss::bossshot()
{
    bossplane.shoot();//boss敌机发射子弹
    //设置boss敌机子弹坐标
    for(int i=0;i<30;i++)
    {
        if(!bossplane.mbullets[i].free)
        {
            bossplane.mbullets[i].updatePosition();
        }
    }
}

void DialogBoss::bossjudge()
{
    for(int i=0;i<30;i++)
    {
        if(bossplane.mbullets[i].free)
        {
            continue;
        }
        //如果boss敌机子弹碰撞到飞机，游戏结束
        if(bossplane.mbullets[i].rect.intersects(hostplane.mrect)&&life<100)
        {
            QSound::play(":/res/bomb.wav");//播放爆炸音效
            //播放爆炸效果
            for(int k=0;k<20;k++)
            {
               if(bombs[k].free)
               {
                bombs[k].free=false;//爆炸状态设置为非空闲
                //更新坐标
                bombs[k].X=hostplane.X;
                bombs[k].Y=hostplane.Y;
                break;
                }
            }
            QMessageBox::about(this,"游戏结束","挑战失败");//挑战失败
            emit signal3();//发出关闭窗口的信号
            bosstimer.stop();
        }
        //如果boss敌机碰撞到飞机，则游戏结束
        if(bossplane.rect.intersects(hostplane.mrect)&&life<100)
        {
            QSound::play(":/res/bomb.wav");//播放爆炸音效
            //播放爆炸效果
            for(int k=0;k<20;k++)
            {
               if(bombs[k].free)
               {
                bombs[k].free=false;//爆炸状态设置为非空闲
                //更新坐标
                bombs[k].X=hostplane.X;
                bombs[k].Y=hostplane.Y;
                break;
                }
            }
            QMessageBox::about(this,"游戏结束","挑战失败");//挑战失败
            emit signal3();//发出关闭窗口的信号
            bosstimer.stop();
        }
     }
    //每次飞机子弹碰撞到boss敌机，敌机血量下降
        for(int i=0;i<30;i++)
        {
            if(hostplane.mbullets[i].free)
            {
                continue;
            }
            if(hostplane.mbullets[i].rect.intersects(bossplane.rect))
            {
                life++;
                //播放爆炸效果
                for(int k=0;k<20;k++)
                {
                   if(bombs[k].free)
                   {
                    bombs[k].free=false;//爆炸状态设置为非空闲
                    //更新坐标
                    bombs[k].X=bossplane.X;
                    bombs[k].Y=bossplane.Y;
                    break;
                    }
                }
            }
        }
        //如果boss敌机血量下降100以上，则游戏结束并通关
        if(life>=200)
        {
            QMessageBox::about(this,"游戏结束","游戏通关");//输出游戏通关
            emit signal3();//发出关闭窗口的信号
            bosstimer.stop();
        }

}

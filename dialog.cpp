#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,map.map1_y,map.map1);
    painter.drawPixmap(0,map.map2_y,map.map2);
    painter.drawPixmap(hostplane.X,hostplane.Y,hostplane.mplane);//绘制飞机
    //绘制子弹
    for(int i=0;i<30;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!hostplane.mbullets[i].free)
        {
            painter.drawPixmap(hostplane.mbullets[i].X,hostplane.mbullets[i].Y,hostplane.mbullets[i].bullet);
        }
    }
    //绘制敌机
    for(int i=0;i<20;i++)
    {
        if(!enemys[i].free&&num<=21)
        {
            painter.drawPixmap(enemys[i].X,enemys[i].Y,enemys[i].enemy);
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
    painter.setFont(QFont("微软雅黑",20,700,false));
    painter.drawText(QPoint(20,60),"分数："+QString::number(score));
}

void Dialog::keyPressEvent(QKeyEvent *event)
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

void Dialog::chushihuascene()
{
    setWindowTitle("第一关");
    setFixedSize(500,750);
    setWindowIcon(QIcon(":/res/label.ico"));//设置图标
    score=0;
    state=true;
    num=0;
    mtimer.setInterval(18);//设置定时器刷新时间间隔
    play();
    judge();
    recorder=0;
    srand((unsigned int)time(NULL));//随机数种子
}

void Dialog::play()
{
    mtimer.start();//启动定时器
    //监听定时器
    connect(&mtimer,&QTimer::timeout,[=](){
       enemytoscene();//敌机出场
       updateposition();
       update();
       collision();//碰撞检测
       judge();
    });
}

void Dialog::updateposition()
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
    //计算敌机坐标
    for(int i=0;i<20;i++)
    {
        if(!enemys[i].free)
        {
            enemys[i].updatePosition();
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

void Dialog::PressUp()
{
    //向上移动
    hostplane.Y-=20;
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

void Dialog::PressDown()
{
    //向下移动
    hostplane.Y+=20;
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

void Dialog::PressLeft()
{
    //向左移动
    hostplane.X-=20;
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

void Dialog::PressRight()
{
    //向右移动
    hostplane.X+=20;
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

void Dialog::enemytoscene()
{
    recorder++;
    if(recorder<100)
    {
        return;
    }
    recorder=0;
    num++;
    for(int i=0;i<20;i++)
    {
        if(enemys[i].free)
        {
            enemys[i].free=false;//敌机空闲状态改为false
            //设置坐标
            enemys[i].X=rand()%(500-enemys[i].rect.width());
            enemys[i].Y=-enemys[i].rect.height();
            break;
        }
    }
}

void Dialog::collision()
{
    for(int i=0;i<20;i++)
    {
        //遍历所有非空闲的敌机
        if(enemys[i].free)
        {
            continue;
        }
        //如果敌机和飞机相撞，则游戏结束
        if((enemys[i].rect.intersects(hostplane.mrect))&&num<=21)
        {
            QSound::play(":/res/bomb.wav");//播放爆炸音效
            //播放爆炸效果
            for(int k=0;k<20;k++)
            {
               if(bombs[k].free)
               {
                bombs[k].free=false;//爆炸状态设置为非空闲
                //更新坐标
                bombs[k].X=enemys[i].X;
                bombs[k].Y=enemys[i].Y;
                break;
                }
            }
            enemys[i].free=true;
            num=22;
            state=true;
            break;
        }
        //遍历所有非空闲的子弹
        for(int j=0;j<30;j++)
        {
            if(hostplane.mbullets[j].free)
            {
                continue;
            }
            //如果子弹矩形框和飞机矩形框相交，发生碰撞，变为空闲状态
            if((enemys[i].rect.intersects(hostplane.mbullets[j].rect))&&num<=21)
            {
                QSound::play(":/res/bomb.wav");//播放爆炸音效
                enemys[i].free=true;
                hostplane.mbullets[j].free=true;
                score+=50;
                //播放爆炸效果
                for(int k=0;k<20;k++)
                {
                   if(bombs[k].free)
                   {
                    bombs[k].free=false;//爆炸状态设置为非空闲
                    //更新坐标
                    bombs[k].X=enemys[i].X;
                    bombs[k].Y=enemys[i].Y;
                    break;
                }
                }
            }
         }
    }
}

void Dialog::judge()
{
    //如果状态为真并且出现了20架飞机则结束
    if(state&&num>=21)
    {
        QMessageBox::about(this,"游戏结束","分数为："+QString::number(score)+" ");//输出分数
        state=false;
        emit signal();//发出关闭窗口的信号
    }
    update();
}

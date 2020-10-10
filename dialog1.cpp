#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    setWindowTitle("飞机大战");
    connect(ui->buttoncontinue,&QPushButton::clicked,this,second);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::second()
{
    emit signalclose();
    emit signalcontinue();
}

void Dialog1::on_buttonreturn_clicked()
{
    emit mysignal();
}

void Dialog1::on_buttonrestart_clicked()
{
    emit signalclose();
    emit signalrestart();
}

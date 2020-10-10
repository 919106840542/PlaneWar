#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();
    void second();//第二关

signals:
    void mysignal();
    void signalrestart();
    void signalclose();
    void signalcontinue();


private slots:
    void on_buttonreturn_clicked();

    void on_buttonrestart_clicked();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H

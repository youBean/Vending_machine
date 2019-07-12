#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    ui->pbTea->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
        money+=n;
        ui->lcdNumber->display(QString::number(money));
        if(money>=100){
            ui->pbCoffee->setEnabled(true);
        }else {
            ui->pbCoffee->setEnabled(false);
        }
        if(money>=150){
            ui->pbTea->setEnabled(true);
        }else {
            ui->pbTea->setEnabled(false);
        }
        if(money>=200){
            ui->pbMilk->setEnabled(true);
        }else {
            ui->pbMilk->setEnabled(false);
        }
}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
}
void Widget::on_pb50_clicked()
{
    changeMoney(50);
}
void Widget::on_pb100_clicked()
{
    changeMoney(100);
}
void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbRet_clicked()
{
    QMessageBox msg;
    int m10;
    int m50;
    int m100;
    int m500;
    m500=money/500;
    money%=500;
    m100=money/100;
    money%=100;
    m50=money/50;
    money%=50;
    m10=money;
    QString s1 = QString::number(m10);
    QString s2 = QString::number(m50);
    QString s3 = QString::number(m100);
    QString s4 = QString::number(m500);

    msg.information(nullptr,"CHANGE","10won: "
                    +s1+"\n50won: "+s2+
                    "\n100won: "+s3+"\n500won: "+s4);
    if(msg.Ok){
        ui->lcdNumber->display(QString::number(0));
    }
}

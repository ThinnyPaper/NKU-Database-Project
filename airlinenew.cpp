#include "airlinenew.h"
#include "ui_airlinenew.h"
#include <QSqlQuery>
#include <QMessageBox>

#include <iostream>
using namespace std;
airlinenew::airlinenew(QWidget *parent,QSqlDatabase* org) :
    QWidget(parent),
    ui(new Ui::airlinenew)
{
    nldb=org;
    ui->setupUi(this);
}

airlinenew::~airlinenew()
{
    delete ui;
}

void airlinenew::on_pushButton_clicked()
{
    QString num=ui->lineEdit->text(),
            start=ui->lineEdit_2->text(),
            end=ui->lineEdit_3->text();





    QString cmd="select `是否为机场` from `中转站` where `中转站名`='"+start+"'";

    QSqlQuery qry(cmd,*nldb);
    qry.next();

    int value = qry.value(0).toInt();
    if(value!=1){
        QMessageBox::information(this,"警告","起始站点名有误，请重新输入");
    }
    else if(start==end){
        QMessageBox::information(this,"警告","站点名相同，请重新输入");
    }
    else{
        cmd="select `是否为机场` from `中转站` where `中转站名`='"+end+"'";
        QSqlQuery qry2(cmd,*nldb);
        //qry2.first();
        qry2.next();

        int value2 = qry2.value(0).toInt();

        if(value2 !=1){
            QMessageBox::information(this,"警告","到达站点名有误，请重新输入");
        }
        else{

            cmd=QString("insert into `航班` values('%1','%2','%3',null,null,0)").arg(num).arg(start).arg(end);
            QSqlQuery qry3(*nldb);
            if(qry.exec(cmd)){
                QMessageBox::information(this, "成功","航班添加成功");
            }
            else{
                QMessageBox::information(this,"失败",cmd+"中转站不存在");
            }
        }

    }
}



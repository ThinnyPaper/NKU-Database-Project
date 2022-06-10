#include "collect.h"
#include "ui_collect.h"
#include <QDateTime>
#include <QSqlQuery>
#include <QMessageBox>
#include <iostream>
using namespace std;
collect::collect(QWidget *parent,QSqlDatabase *org,QString postmanname) :
    QWidget(parent),
    ui(new Ui::collect)
{
    colldb=org;
    collname=postmanname;
    ui->setupUi(this);

}

collect::~collect()
{
    delete ui;
}




void collect::on_pushButton_clicked()
{
    QString s_name=ui->lineEdit->text(),
            r_name=ui->lineEdit_2->text(),
            s_add=ui->textEdit->toPlainText(),
            r_add=ui->textEdit_2->toPlainText(),
            weight=ui->lineEdit_3->text();
    //insert into `订单` values('002','小王','南开','小刘','河北','2022/6/10-18:24',12.1,12.1,0,'小李','已揽收')
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy/MM/dd-hh:mm:ss");

    QString ordernum=current_date_time.toString("yyyyMMddhhmmss");
    double price=weight.toDouble();

    bool ifair=ui->checkBox->isChecked();
    QString air;
    if(ifair){
        air="1";
        if(price<=1)
            price=12;
        else
            price=(price-1)*3.2+12;
    }
    else{
        air="0";

        if(price<=1)
            price=10;
        else
            price=(price-1)*2.1+10;

    }
    //QString cost=QString::number(price)


    QString cmd=QString("insert into `订单` values('%1','%2','%3','%4','%5','%6',%7,%8,%9,'%10','已揽收')")
            .arg(ordernum).arg(s_name).arg(s_add).arg(r_name).arg(r_add).arg(current_date).arg(weight).arg(price).arg(air).arg(collname);
    QSqlQuery qry(*colldb);
    if(qry.exec(cmd)){
        QMessageBox::information(this, "成功",QString("揽收成功，运费：%1 元").arg(price));
    }
    else{
        QMessageBox::information(this,"失败",cmd+"插入失败");
    }

}


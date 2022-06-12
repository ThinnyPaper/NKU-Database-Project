#include "airupdate.h"
#include "ui_airupdate.h"
#include <QSqlQuery>
#include <QDateTime>
#include <QMessageBox>

airupdate::airupdate(QWidget *parent,QSqlDatabase* org) :
    QWidget(parent),
    ui(new Ui::airupdate)
{
    aupdb=org;
    ui->setupUi(this);
}

airupdate::~airupdate()
{
    delete ui;
}

void airupdate::on_pushButton_clicked()
{
    //起飞
    QString anum=ui->lineEdit->text();
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy/MM/dd-hh:mm:ss");

    QString cmd0=QString("select * from `航班` where `航班号`='%1'").arg(anum);
    QSqlQuery qry(cmd0,*aupdb);
    qry.next();
    if(qry.value(0).toString()==""){
        QMessageBox::information(this,"失败","更新失败");
    }
    else{
        QString cmd=QString("call takeoff('%1','%2`')").arg(anum).arg(current_date);
        //QSqlQuery qry(*aupdb);

        if(qry.exec(cmd)){
            QMessageBox::information(this,"成功","更新成功");
        }
        else{
            QMessageBox::information(this,"失败","更新失败");
        }
    }

}


void airupdate::on_pushButton_2_clicked()
{
    //降落
    QString anum=ui->lineEdit->text();
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy/MM/dd-hh:mm:ss");

    QString cmd0=QString("select `起飞时间` from `航班` where `航班号`='%1'").arg(anum);
    QSqlQuery qry(cmd0,*aupdb);
    qry.next();
    if(qry.value(0).toString()==""){
        QMessageBox::information(this,"失败","航班尚未起飞");
    }
    else{
        QString cmd=QString("update `航班` set `到达时间`= '%1' where `航班号`='%2'").arg(current_date).arg(anum);

        QString cmd2=QString("update `订单`NATURAL JOIN`空运订单` SET `当前状态`='飞机已降落' where `航班号`='%1'").arg(anum);

        if(qry.exec(cmd)&&qry.exec(cmd2)){
            QMessageBox::information(this,"成功","更新成功");
        }
        else{
            QMessageBox::information(this,"失败","更新失败");
        }
    }
}


void airupdate::on_pushButton_3_clicked()
{
    //航班取消
    QString anum=ui->lineEdit->text();

    QString cmd0=QString("select `起飞时间` from `航班` where `航班号`='%1'").arg(anum);
    QSqlQuery qry(cmd0,*aupdb);
    qry.next();
    if(qry.value(0).toString()==""){

        QString cmd=QString("delete from `航班` where `航班号`='%1'").arg(anum);


        if(qry.exec(cmd)){
            QMessageBox::information(this,"成功","航班取消成功");
        }
        else{
            QMessageBox::information(this,"失败","更新失败");
        }
    }
    else{
        QMessageBox::information(this,"失败","航班已起飞");
    }
}


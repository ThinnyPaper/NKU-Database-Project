#include "choose.h"
#include "ui_choose.h"
#include "postman.h"
#include "airmanager.h"
#include "mainwindow.h"
#include "landmanager.h"
#include <QSqlQuery>
#include<QMessageBox>
#include<iostream>
using namespace std;
//#include "dbconnect.h"
choose::choose(QWidget *parent,QSqlDatabase* org) :
    QWidget(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
    this->setWindowTitle("选择职员类型");
    cdb=org;
}

choose::~choose()
{
    delete ui;
}




//返回上一页
void choose::on_pushButton_5_clicked()
{
    MainWindow *m=new MainWindow;
    m->show();
    this->~choose();
}


//登录
void choose::on_pushButton_6_clicked()
{
    //快递员
    if(ui->radioButton->isChecked()){
        QString acc=ui->lineEdit->text();
        QString pw=ui->lineEdit_2->text();
        QString checkpw="select `密码` from `快递员` where `工号`= '"+acc+"'";
        QSqlQuery qry(checkpw,*cdb);
        qry.first();
        QString truepw = qry.value(0).toString();

        if(truepw!=""&&pw==truepw){
            QString search_name="select `姓名` from `快递员` where `工号`= '"+acc+"'";
            QSqlQuery qry2(search_name,*cdb);
            qry2.first();
            QString sname = qry2.value(0).toString();
            postman* p=new postman(nullptr,cdb,sname);
            p->show();
            this->~choose();
        }
        else{
            QMessageBox::information(this,"密码错误","账号或密码错误，请重试  ");
        }
    }

    //航空管理
    else if(ui->radioButton_2->isChecked()){
        QString acc=ui->lineEdit->text();
        QString pw=ui->lineEdit_2->text();
        QString checkpw="select `密码` from `航空管理账号` where `账号`= '"+acc+"'";
        QSqlQuery qry(checkpw,*cdb);
        qry.first();
        QString truepw = qry.value(0).toString();

        if(truepw!=""&&pw==truepw){

            airmanager* am=new airmanager(nullptr,cdb);
            am->show();
            this->~choose();
        }
        else{
            QMessageBox::information(this,"密码错误","账号或密码错误，请重试  ");
        }
    }

    //陆运管理
    else if(ui->radioButton_3->isChecked()){
        QString acc=ui->lineEdit->text();
        QString pw=ui->lineEdit_2->text();
        QString checkpw="select `密码` from `陆运管理账号` where `账号`= '"+acc+"'";
        QSqlQuery qry(checkpw,*cdb);
        qry.first();
        QString truepw = qry.value(0).toString();

        if(truepw!=""&&pw==truepw){

            landmanager* lm=new landmanager(nullptr,cdb);
            lm->show();
            this->~choose();
        }
        else{
            QMessageBox::information(this,"密码错误","账号或密码错误，请重试  ");
        }
    }



    else{
        QMessageBox::information(this,"职位为空"," 请选择您的职位 ");
    }
}


void choose::on_radioButton_2_clicked()
{

}



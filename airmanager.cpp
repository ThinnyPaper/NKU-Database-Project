#include "airmanager.h"
#include "ui_airmanager.h"
#include "airlinenew.h"
#include "airload.h"
#include "airupdate.h"
airmanager::airmanager(QWidget *parent,QSqlDatabase* org) :
    QWidget(parent),
    ui(new Ui::airmanager)
{
    amdb=org;
    ui->setupUi(this);
}

airmanager::~airmanager()
{
    delete ui;
}

void airmanager::on_pushButton_clicked()
{
    //新增航班
    airlinenew* aln=new airlinenew(nullptr,amdb);
    aln->show();
}


void airmanager::on_pushButton_2_clicked()
{
    //航班状态更新
    //更新快递状态
    airupdate* aup=new airupdate(nullptr,amdb);
    aup->show();
}


void airmanager::on_pushButton_3_clicked()
{
    //货物装载
    airload* al=new airload(nullptr,amdb);
    al->show();

}


#include "airload.h"
#include "ui_airload.h"
#include<QSqlQuery>
#include <QMessageBox>
airload::airload(QWidget *parent,QSqlDatabase* org) :
    QWidget(parent),
    ui(new Ui::airload)
{
    aldb=org;
    ui->setupUi(this);

}

airload::~airload()
{
    delete ui;
}

void airload::on_pushButton_clicked()
{
    QString airnum=ui->lineEdit->text();
    QString order=ui->lineEdit_2->text();

    QString cmd=QString("insert into `空运订单` values('%1','%2')").arg(airnum).arg(order);

    QSqlQuery qry(*aldb);

    if(qry.exec(cmd)){
        QMessageBox::information(this,"成功","成功");
    }
    else{
        QMessageBox::information(this,"失败","请检查输入是否正确");
    }
}


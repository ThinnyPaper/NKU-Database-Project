#include "landload.h"
#include "ui_landload.h"
#include <QSqlQuery>
#include <QMessageBox>
landload::landload(QWidget *parent,QSqlDatabase *org,QString linenum,QString carnum,QString pretime) :
    QWidget(parent),
    ui(new Ui::landload)
{
    lldb=org;
    lnum=linenum;
    cnum=carnum;
    ptime=pretime;
    ui->setupUi(this);
}

landload::~landload()
{
    delete ui;
}

void landload::on_pushButton_clicked()
{
    QString order=ui->lineEdit->text();

    QString cmd=QString("insert into `陆运订单` values('%1','%2','%3','%4')").arg(order).arg(lnum).arg(cnum).arg(ptime);

    QSqlQuery qry(*lldb);

    if(qry.exec(cmd)){
        QMessageBox::information(this,"成功","成功");
    }
    else{
        QMessageBox::information(this,"失败",QString("请检查单号是否正确 values('%1','%2','%3','%4')").arg(order).arg(lnum).arg(cnum).arg(ptime));
    }
}


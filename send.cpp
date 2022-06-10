#include "send.h"
#include "ui_send.h"
#include <QSqlQuery>
#include <QMessageBox>
send::send(QWidget *parent,QSqlDatabase* org) :
    QWidget(parent),
    ui(new Ui::send)
{
    senddb = org;
    ui->setupUi(this);
}

send::~send()
{
    delete ui;
}

void send::on_pushButton_clicked()
{
    QString ordernum=ui->lineEdit->text();
    QString cmd="update `订单` set `当前状态`= '派送中' where `订单号`='"+ordernum+"'";

    QSqlQuery qry(*senddb);

    if(qry.exec(cmd)){
        QMessageBox::information(this,"成功","成功");
    }
    else{
        QMessageBox::information(this,"失败","未查询到该快件，请检查单号是否正确");
    }

}


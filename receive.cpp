#include "receive.h"
#include "ui_receive.h"
#include "QSqlQuery"
#include <QMessageBox>
receive::receive(QWidget *parent,QSqlDatabase* org) :
    QWidget(parent),
    ui(new Ui::receive)
{
    redb=org;
    ui->setupUi(this);
}

receive::~receive()
{
    delete ui;
}

void receive::on_pushButton_clicked()
{
    QString ordernum=ui->lineEdit->text();
    QString cmd="update `订单` set `当前状态`= '已签收' where `订单号`='"+ordernum+"'";

    QSqlQuery qry(*redb);

    if(qry.exec(cmd)){
        QMessageBox::information(this,"成功","成功");
    }
    else{
        QMessageBox::information(this,"失败","未查询到该快件，请检查单号是否正确");
    }
}


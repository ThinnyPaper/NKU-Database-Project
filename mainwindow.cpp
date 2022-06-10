#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include<QMessageBox>
#include<QSqlDatabase>

//#include "dbconnect.h"
#include "choose.h"

MainWindow::MainWindow(QWidget *parent,QSqlDatabase* org)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    //数据库连接
    //mydbconnect(db);
    db=org;
////UI is Here
    ui->setupUi(this);

    this->setWindowTitle("快递系统");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString order=ui->lineEdit->text();
    order="select `当前状态` from `订单` where `订单号`= '"+order+"'";
    //cout<<"中文测试"<<endl;

    QSqlQuery qry(order,*db);
    qry.first();
    QString value = qry.value(0).toString();
    if(value !=""){
        QMessageBox::information(this,"查询结果","快件当前状态："+value);
    }
    else{
        QMessageBox::information(this,"查询结果","未查询到该快件，请检查单号是否正确");
    }
}


void MainWindow::on_pushButton_clicked()
{
    choose *c=new choose(nullptr,db);
    c->show();
    this->close();
}


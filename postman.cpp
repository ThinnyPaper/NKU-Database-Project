#include "postman.h"
#include "ui_postman.h"
#include "collect.h"
#include "send.h"
#include "receive.h"
postman::postman(QWidget *parent, QSqlDatabase* org, QString iname) :
    QWidget(parent),
    ui(new Ui::postman)
{
    ui->setupUi(this);
    name=iname;
    this->setWindowTitle(name+"的工作台");
    pdb=org;
}

postman::~postman()
{
    delete ui;
}

void postman::on_pushButton_clicked()
{
//揽收
    collect *coll=new collect(nullptr,pdb,name);
    coll->show();
}


void postman::on_pushButton_2_clicked()
{
//派送
    send *sen=new send(nullptr,pdb);
    sen->show();
}


void postman::on_pushButton_3_clicked()
{
    receive* rece=new receive(nullptr,pdb);
    rece->show();
}


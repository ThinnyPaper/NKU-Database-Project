#include "loadedit.h"
#include "ui_loadedit.h"
#include <QMessageBox>
#include <QSqlQuery>
loadedit::loadedit(QWidget *parent,QSqlDatabase *org,QString linenum) :
    QWidget(parent),
    ui(new Ui::loadedit)
{
    ledb=org;
    lnum=linenum;
    ui->setupUi(this);


    model=new QSqlQueryModel;
    model->setQuery(QString("select `订单号`,`重量`,`货车车次`.`路线号`,`货车车次`.`车牌照`,\
        `货车车次`.`预计出发时间` from `订单` natural join `陆运订单` join `货车车次` \
         on `陆运订单`.`车牌照`=`货车车次`.`车牌照` and `陆运订单`.`路线号`=`货车车次`.`路线号` \
         and `陆运订单`.`预计出发时间`=`货车车次`.`预计出发时间` where `货车车次`.`路线号`='%1'").arg(lnum));

    ui->tableView->setModel(model);
  //  ui->tableView->setColumnHidden(0,true);
}

loadedit::~loadedit()
{
    delete ui;
}

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

    /*
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT name, salary FROM employee");
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Salary"));

    */

    model=new QSqlQueryModel;
    model->setQuery("select `订单号`,`重量`,`货车车次`.`路线号`,`货车车次`.`车牌照`,`货车车次`.`预计出发时间` from `订单` natural join `陆运订单` join `货车车次` on `陆运订单`.`车牌照`=`货车车次`.`车牌照` and `陆运订单`.`路线号`=`货车车次`.`路线号` and `陆运订单`.`预计出发时间`=`货车车次`.`预计出发时间`");
          /*
    QSqlQuery qry = model->query();
    //qry.
    qry.exec("select `订单号` from `订单` natural join `陆运订单` join `货车车次` on `陆运订单`.`车牌照`=`货车车次`.`车牌照` and `陆运订单`.`路线号`=`货车车次`.`路线号` and `陆运订单`.`预计出发时间`=`货车车次`.`预计出发时间`");
    model->query().next();

    //model->selectStatement();
   // model->setTable("订单");
  //  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  //  model->setFilter(tr("路线号='%1'").arg(linenum));
  */
    //model->
   // model->select();
    ui->tableView->setModel(model);
  //  ui->tableView->setColumnHidden(0,true);
}

loadedit::~loadedit()
{
    delete ui;
}

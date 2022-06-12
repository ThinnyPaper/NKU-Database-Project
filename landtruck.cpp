#include "landtruck.h"
#include "ui_landtruck.h"
#include <QMessageBox>
#include "loadedit.h"
#include "landload.h"
#include <QDateTime>
#include <QModelIndex>
landtruck::landtruck(QWidget *parent,QSqlDatabase *org,QString linenum) :
    QWidget(parent),
    ui(new Ui::landtruck)
{
    ltdb=org;
    lnum=linenum;
    ui->setupUi(this);

    model=new QSqlTableModel(this,*ltdb);

    model->setTable("货车车次");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setFilter(tr("路线号='%1'").arg(linenum));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
}

landtruck::~landtruck()
{
    delete ui;
}

void landtruck::on_pushButton_clicked()
{
    //新增车次
    if(ui->pushButton->text()=="新增车次"){

        ui->pushButton->setText("提交新增");
        int row = model->rowCount();
        //添加一行
        model->insertRow(row);
        model->setData(model->index(row, 0), lnum);

    }
    else if(ui->pushButton->text()=="提交新增"){

        if(model->submitAll()){
            ui->pushButton->setText("新增车次");

            QMessageBox::information(this,"成功","新增车次成功");
        }
        else{
            QMessageBox::information(this,"错误","输入有误，请重新输入");
        }
    }
}


void landtruck::on_pushButton_2_clicked()
{
    //查询车内货物
    loadedit* le=new loadedit(nullptr,ltdb,lnum);
    le->show();


}


void landtruck::on_pushButton_3_clicked()
{
    //出发
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy/MM/dd-hh:mm:ss");


    int curRow = ui->tableView->currentIndex().row();
    model->setData(model->index(curRow, 3), "已出发");
    model->setData(model->index(curRow, 4), current_date);
    if(!model->submitAll()){
        QMessageBox::information(this,"失败","出现错误");
    }

}


void landtruck::on_pushButton_4_clicked()
{
    //到达
    QModelIndex i=model->index(ui->tableView->currentIndex().row(),3);
    if(model->data(i,0).toString()==""){
        QMessageBox::information(this,"失败","货车尚未出发");
    }
    else{

        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy/MM/dd-hh:mm:ss");
        int curRow = ui->tableView->currentIndex().row();
        model->setData(model->index(curRow, 3), "已到达");
        model->setData(model->index(curRow, 5), current_date);
        if(!model->submitAll()){
            QMessageBox::information(this,"失败","出现错误");
        }
    }
}


void landtruck::on_pushButton_5_clicked()
{
    //int row=ui->tableView->currentIndex().row();
    QModelIndex i=model->index(ui->tableView->currentIndex().row(),1);
    QModelIndex j=model->index(ui->tableView->currentIndex().row(),2);

   //model->data()
    QString carnum=model->data(i,0).toString();
    QString pretime=model->data(j,0).toString();


    landload *ll=new landload(nullptr,ltdb,lnum,carnum,pretime);
    ll->show();

}


#include "zzzmanager.h"
#include "ui_zzzmanager.h"
#include <QMessageBox>

zzzmanager::zzzmanager(QWidget *parent,QSqlDatabase* org) :
    QWidget(parent),
    ui(new Ui::zzzmanager)
{
    zzzdb=org;
    ui->setupUi(this);

    model=new QSqlTableModel(this,*zzzdb);
    model->setTable("中转站");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
}

zzzmanager::~zzzmanager()
{
    delete ui;
}

void zzzmanager::on_pushButton_clicked()
{
    //新增
       if(ui->pushButton->text()=="新增"){

           ui->pushButton->setText("提交");
           int row = model->rowCount();
           //添加一行
           model->insertRow(row);


       }
       else if(ui->pushButton->text()=="提交"){
           if(model->submitAll()){
               ui->pushButton->setText("新增");
               QMessageBox::information(this,"成功","新增成功");
           }
           else{
               QMessageBox::information(this,"错误","输入有误，请重新输入");
           }
       }
}


void zzzmanager::on_pushButton_2_clicked()
{

      //删除该行
      int curRow = ui->tableView->currentIndex().row();
      int ret = QMessageBox::warning(this, tr("删除"), tr("你确定要删除当前线路吗？"), QMessageBox::Yes | QMessageBox::No);
      if (ret == QMessageBox::Yes)
      {
         //删除该行 提交到数据库
         model->removeRow(curRow);
         model->submitAll();
      }

}


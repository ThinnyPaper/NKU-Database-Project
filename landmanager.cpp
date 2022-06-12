#include "landmanager.h"
#include "ui_landmanager.h"
#include <QMessageBox>
#include "landtruck.h"
landmanager::landmanager(QWidget *parent,QSqlDatabase* org) :
    QWidget(parent),
    ui(new Ui::landmanager)
{
    ldb=org;
    ui->setupUi(this);

    model=new QSqlTableModel(this,*ldb);
    model->setTable("陆运货车线路");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);

}

landmanager::~landmanager()
{
    delete ui;
}

void landmanager::on_pushButton_clicked()
{
    //新增线
    if(ui->pushButton->text()=="新增线路"){

        ui->pushButton->setText("提交");
        int row = model->rowCount();
        //添加一行
        model->insertRow(row);


    }
    else if(ui->pushButton->text()=="提交"){
        if(model->submitAll()){
            ui->pushButton->setText("新增线路");
            QMessageBox::information(this,"成功","新增成功");
        }
        else{
            QMessageBox::information(this,"错误","中转站输入有误，请重新输入");
        }
    }
}


void landmanager::on_pushButton_2_clicked()
{
    //获取选中的行
    int curRow = ui->tableView->currentIndex().row();
    //删除该行

    int ret = QMessageBox::warning(this, tr("删除"), tr("你确定要删除当前线路吗？"), QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes)
    {
       //删除该行 提交到数据库
       model->removeRow(curRow);
       model->submitAll();
    }

}



void landmanager::on_pushButton_3_clicked()
{
    //编辑车次


    //
    QString linenum=model->data(ui->tableView->currentIndex(),0).toString();
    //QMessageBox::information(this,"row",QString("%1").arg(linenum));
    landtruck * lt=new landtruck(nullptr,ldb,linenum);
    lt->show();
}






#ifndef DBCONNECT_H
#define DBCONNECT_H
#include<QSqlDatabase>
#include<iostream>
using namespace std;

void mydbconnect(QSqlDatabase &x){

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("localmysql");
    db.setUserName("root");
    db.setPassword("yourpassword");//运行前记得改密码！！
    bool ok = db.open();

    if (ok){
        cout<<"yes"<<endl;
       // QMessageBox::information(this, "infor", "link success");
    }
    else {
        cout<<"no"<<endl;
        //QMessageBox::information(this, "infor", "link failed");
        //qDebug()<<"error open database because"<<db.lastError().text();
    }
    x=db;
}

#endif // DBCONNECT_H

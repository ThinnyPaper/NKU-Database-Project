#ifndef LANDLOAD_H
#define LANDLOAD_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class landload;
}

class landload : public QWidget
{
    Q_OBJECT

public:
    explicit landload(QWidget *parent = nullptr,QSqlDatabase *org=nullptr,QString linenum="",QString carnum="",QString pretime="");
    ~landload();

private slots:
    void on_pushButton_clicked();

private:
    Ui::landload *ui;
    QSqlDatabase *lldb;
    QString lnum;
    QString cnum;
    QString ptime;
};

#endif // LANDLOAD_H

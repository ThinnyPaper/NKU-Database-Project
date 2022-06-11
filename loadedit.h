#ifndef LOADEDIT_H
#define LOADEDIT_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class loadedit;
}

class loadedit : public QWidget
{
    Q_OBJECT

public:
    explicit loadedit(QWidget *parent = nullptr,QSqlDatabase* org= nullptr,QString linenum="");
    ~loadedit();

private:
    Ui::loadedit *ui;
    QSqlDatabase *ledb;
    QSqlQueryModel *model;
    QString lnum;

};

#endif // LOADEDIT_H

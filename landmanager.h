#ifndef LANDMANAGER_H
#define LANDMANAGER_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class landmanager;
}

class landmanager : public QWidget
{
    Q_OBJECT

public:
    explicit landmanager(QWidget *parent = nullptr,QSqlDatabase* org= nullptr);
    ~landmanager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::landmanager *ui;
    QSqlDatabase* ldb;
    QSqlTableModel *model;
};

#endif // LANDMANAGER_H

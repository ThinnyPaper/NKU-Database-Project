#ifndef ZZZMANAGER_H
#define ZZZMANAGER_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>


namespace Ui {
class zzzmanager;
}

class zzzmanager : public QWidget
{
    Q_OBJECT

public:
    explicit zzzmanager(QWidget *parent = nullptr,QSqlDatabase* org= nullptr);
    ~zzzmanager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::zzzmanager *ui;
    QSqlDatabase* zzzdb;
    QSqlTableModel *model;
};

#endif // ZZZMANAGER_H

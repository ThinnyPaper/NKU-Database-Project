#ifndef AIRMANAGER_H
#define AIRMANAGER_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class airmanager;
}

class airmanager : public QWidget
{
    Q_OBJECT

public:
    explicit airmanager(QWidget *parent = nullptr,QSqlDatabase* org=nullptr);
    ~airmanager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::airmanager *ui;
    QSqlDatabase* amdb;
};

#endif // AIRMANAGER_H

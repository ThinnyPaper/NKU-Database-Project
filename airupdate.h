#ifndef AIRUPDATE_H
#define AIRUPDATE_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class airupdate;
}

class airupdate : public QWidget
{
    Q_OBJECT

public:
    explicit airupdate(QWidget *parent = nullptr,QSqlDatabase* org=nullptr);
    ~airupdate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::airupdate *ui;
    QSqlDatabase* aupdb;
};

#endif // AIRUPDATE_H

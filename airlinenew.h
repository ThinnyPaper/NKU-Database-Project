#ifndef AIRLINENEW_H
#define AIRLINENEW_H

#include <QWidget>
#include <QSqldatabase>

namespace Ui {
class airlinenew;
}

class airlinenew : public QWidget
{
    Q_OBJECT

public:
    explicit airlinenew(QWidget *parent = nullptr,QSqlDatabase* org=nullptr);
    ~airlinenew();

private slots:
    void on_pushButton_clicked();

private:
    Ui::airlinenew *ui;
    QSqlDatabase* nldb;

};

#endif // AIRLINENEW_H

#ifndef COLLECT_H
#define COLLECT_H

#include <QWidget>
#include<QSqlDatabase>
namespace Ui {
class collect;
}

class collect : public QWidget
{
    Q_OBJECT

public:
    explicit collect(QWidget *parent = nullptr,QSqlDatabase* org=nullptr,QString postmanname="");
    ~collect();

private slots:

    void on_pushButton_clicked();

private:
    Ui::collect *ui;
    QSqlDatabase* colldb;
    QString collname;
};
#endif // COLLECT_H

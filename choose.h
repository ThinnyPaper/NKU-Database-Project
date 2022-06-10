#ifndef CHOOSE_H
#define CHOOSE_H
//登陆界面
#include <QWidget>
#include<QSqlDatabase>
namespace Ui {
class choose;
}

class choose : public QWidget
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = nullptr,QSqlDatabase* org=nullptr);
    ~choose();

private slots:


    void on_pushButton_5_clicked();



    void on_pushButton_6_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::choose *ui;
    QString account;
    QString passwd;
    QSqlDatabase *cdb;

};

#endif // CHOOSE_H

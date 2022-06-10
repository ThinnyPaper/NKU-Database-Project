#ifndef POSTMAN_H
#define POSTMAN_H

#include <QWidget>
#include<QSqlDatabase>
namespace Ui {
class postman;
}

class postman : public QWidget
{
    Q_OBJECT

public:
    explicit postman(QWidget *parent = nullptr,QSqlDatabase* org =nullptr, QString iname="");
    ~postman();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::postman *ui;
    QSqlDatabase* pdb;
    QString name;
};

#endif // POSTMAN_H

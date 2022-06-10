#ifndef SEND_H
#define SEND_H

#include <QWidget>
#include <QSqlDatabase>
namespace Ui {
class send;
}

class send : public QWidget
{
    Q_OBJECT

public:
    explicit send(QWidget *parent = nullptr,QSqlDatabase* org=nullptr);
    ~send();

private slots:
    void on_pushButton_clicked();

private:
    Ui::send *ui;
    QSqlDatabase* senddb;
};

#endif // SEND_H

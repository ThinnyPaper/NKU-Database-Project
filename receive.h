#ifndef RECEIVE_H
#define RECEIVE_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class receive;
}

class receive : public QWidget
{
    Q_OBJECT

public:
    explicit receive(QWidget *parent = nullptr, QSqlDatabase* org=nullptr);
    ~receive();

private slots:
    void on_pushButton_clicked();

private:
    Ui::receive *ui;
    QSqlDatabase* redb;
};

#endif // RECEIVE_H

#ifndef AIRLOAD_H
#define AIRLOAD_H

#include <QWidget>
#include <QSqlDatabase>
namespace Ui {
class airload;
}

class airload : public QWidget
{
    Q_OBJECT

public:
    explicit airload(QWidget *parent = nullptr, QSqlDatabase* org=nullptr);
    ~airload();

private slots:
    void on_pushButton_clicked();


private:
    Ui::airload *ui;
    QSqlDatabase *aldb;
};

#endif // AIRLOAD_H

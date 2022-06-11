#ifndef LANDTRUCK_H
#define LANDTRUCK_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class landtruck;
}

class landtruck : public QWidget
{
    Q_OBJECT

public:
    explicit landtruck(QWidget *parent = nullptr,QSqlDatabase* org= nullptr,QString linenum="");
    ~landtruck();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::landtruck *ui;
    QSqlDatabase *ltdb;
    QSqlTableModel *model;
    QString lnum;

};


/*
class CMachSqlTableModel : public QSqlTableModel
{
public:
    CMachSqlTableModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
protected:
    virtual QString selectStatement() const override;
};*/

#endif // LANDTRUCK_H

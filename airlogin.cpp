#include "airlogin.h"
#include "ui_airlogin.h"

airlogin::airlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::airlogin)
{
    ui->setupUi(this);
}

airlogin::~airlogin()
{
    delete ui;
}

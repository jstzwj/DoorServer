#include "dialoguser.h"
#include "ui_dialoguser.h"

DialogUser::DialogUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUser)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() |Qt::WindowMinMaxButtonsHint);
    this->setWindowTitle("用户管理");
}

DialogUser::~DialogUser()
{
    delete ui;
}

#include "dialogdepartment.h"
#include "ui_dialogdepartment.h"

DialogDepartment::DialogDepartment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDepartment)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() |Qt::WindowMinMaxButtonsHint);
    this->setWindowTitle("部门管理");
}

DialogDepartment::~DialogDepartment()
{
    delete ui;
}

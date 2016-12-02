#include "dialogcontroller.h"
#include "ui_dialogcontroller.h"

DialogController::DialogController(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogController)
{
    ui->setupUi(this);
}

DialogController::~DialogController()
{
    delete ui;
}

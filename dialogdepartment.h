#ifndef DIALOGDEPARTMENT_H
#define DIALOGDEPARTMENT_H

#include <QDialog>

namespace Ui {
class DialogDepartment;
}

class DialogDepartment : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDepartment(QWidget *parent = 0);
    ~DialogDepartment();

private:
    Ui::DialogDepartment *ui;
};

#endif // DIALOGDEPARTMENT_H

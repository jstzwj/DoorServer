#ifndef DIALOGCONTROLLER_H
#define DIALOGCONTROLLER_H

#include <QDialog>

namespace Ui {
class DialogController;
}

class DialogController : public QDialog
{
    Q_OBJECT

public:
    explicit DialogController(QWidget *parent = 0);
    ~DialogController();

private:
    Ui::DialogController *ui;
};

#endif // DIALOGCONTROLLER_H

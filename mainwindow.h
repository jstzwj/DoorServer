#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include<QMessageBox>
#include<QVector>
#include<QDebug>

#include"dialogabout.h"
#include"dialoguser.h"
#include"dialogdepartment.h"
#include"dialogcontroller.h"

#include"netconnection.h"
#include"message.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void refreshMessageList(const QVector<Message>& list);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_action_2_triggered();

    void on_action_about_triggered();

    void on_action_user_triggered();

    void on_action_department_triggered();

    void on_action_controller_triggered();

private:
    Ui::MainWindow *ui;
    DialogAbout * about_dialog;
    DialogUser * user_dialog;
    DialogDepartment * department_dialog;
    DialogController *controller_dialog;
    NetConnection * udp_connection;
};

#endif // MAINWINDOW_H


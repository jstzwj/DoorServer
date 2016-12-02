#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //关于对话框
    about_dialog=new DialogAbout(this);
    about_dialog->hide();
    user_dialog=new DialogUser(this);
    user_dialog->hide();
    department_dialog=new DialogDepartment(this);
    department_dialog->hide();
    controller_dialog=new DialogController(this);
    controller_dialog->hide();
    //监听初始化
    udp_connection=new NetConnection(this);
    udp_connection->initSocket();
    //消息框和房间信息框列的宽度设置
    ui->tableWidget_MessageTable->setColumnWidth(4,300);
    //用于刷新显示列表
    connect(udp_connection, SIGNAL(refreshMessageList(const QVector<Message>&)),
            this, SLOT(refreshMessageList(const QVector<Message>&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshMessageList(const QVector<Message> &list)
{
    ui->tableWidget_MessageTable->setRowCount(list.size());
    for(int i=0;i<list.size();++i)
    {
        ui->tableWidget_MessageTable->setItem(i,1,new QTableWidgetItem(list[i].devSn));
        ui->tableWidget_MessageTable->setItem(i,2,new QTableWidgetItem(list[i].time.toString("yyyy-MM-dd hh:mm:ss")));
        ui->tableWidget_MessageTable->setItem(i,3,new QTableWidgetItem(list[i].sequenceId));
        ui->tableWidget_MessageTable->setItem(i,4,new QTableWidgetItem(list[i].data));
    }
}
/**
 * @brief MainWindow::closeEvent
 * @param event
 * 关闭前提醒用户是否真的要关闭
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("退出程序"),
                                   QString(tr("确认退出程序?")),
                                   QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::No) {
          event->ignore();  //忽略退出信号，程序继续运行
    }
    else if (button == QMessageBox::Yes) {
          event->accept();  //接受退出信号，程序退出
    }
}
/**
 * @brief MainWindow::on_action_2_triggered
 * 菜单栏的退出操作的信号
 */
void MainWindow::on_action_2_triggered()
{
    this->close();
}

void MainWindow::on_action_about_triggered()
{
    about_dialog->show();
}

void MainWindow::on_action_user_triggered()
{
    user_dialog->show();
}

void MainWindow::on_action_department_triggered()
{
    department_dialog->show();
}

void MainWindow::on_action_controller_triggered()
{
    controller_dialog->show();
}

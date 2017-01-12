#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pSecDialog = new SecDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->login->text() == "test" && ui->password->text() == "test") {
        QMessageBox::information(this, "Password confirmed", "Your password is proper");
        pSecDialog->show();
    }
    else {
        QMessageBox::warning(this, "Wrong password", "Your password is wrong!!!");
    }
}

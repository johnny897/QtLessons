#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <secdialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->login->text() == "user7" && ui->password->text() == "8976") {
        QMessageBox::information(this, "Password confirmed", "Your password is proper");
    }
    else {
        QMessageBox::warning(this, "Wrong password", "Your password is wrong!!!");
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/images/screen.png");
    ui->label_pic->setPixmap(pix);

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

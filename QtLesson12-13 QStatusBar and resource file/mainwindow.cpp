#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/pictures/display.png");
    ui->label_pic->setPixmap(pix);

    ui->statusBar->addPermanentWidget(ui->label_status, 1);
    ui->statusBar->addPermanentWidget(ui->progressBar, 5);

    pSecDialog = new SecDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->login->text() == "test" && ui->password->text() == "test") {
 //       QMessageBox::information(this, "Password confirmed", "Your password is proper");
 //       pSecDialog->show();
        ui->statusBar->showMessage("Your password is right!!!", 5000);
        ui->label_status->setText("Your password is right!!!");
    }
    else {
//        QMessageBox::warning(this, "Wrong password", "Your password is wrong!!!");
        ui->statusBar->showMessage("Your password is wrong!!!", 5000);
        ui->label_status->setText("Your password is wrong!!!");
    }
}

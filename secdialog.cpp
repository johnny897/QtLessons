#include "secdialog.h"
#include "ui_secdialog.h"
#include <QMainWindow>
#include <QCloseEvent>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::closeEvent(QCloseEvent * event) {
    QMainWindow* pMainWnd = (QMainWindow*)parent();
    pMainWnd->show();
    event->accept();
}

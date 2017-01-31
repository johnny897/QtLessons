#include "secdialog.h"
#include "ui_secdialog.h"
#include <QMainWindow>
#include <QShowEvent>
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

void SecDialog::showEvent(QShowEvent * event) {
    QMainWindow* pMainWnd = (QMainWindow*)parent();

    pos = pMainWnd->pos();
    pMainWnd->hide();

    event->accept();
}

void SecDialog::closeEvent(QCloseEvent * event) {
    QMainWindow* pMainWnd = (QMainWindow*)parent();
    pMainWnd->move(pos.x(), pos.y());
    pMainWnd->show();

    event->accept();
}

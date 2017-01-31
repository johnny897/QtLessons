#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QPoint>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = 0);
    ~SecDialog();

protected:
    virtual void showEvent(QShowEvent * event);
    virtual void closeEvent(QCloseEvent * event);

private:
    Ui::SecDialog *ui;
    QPoint pos;
};

#endif // SECDIALOG_H

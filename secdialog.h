#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

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
    virtual void closeEvent(QCloseEvent * event);

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H

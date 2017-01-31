#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QDialog>
#include "user.h"

namespace Ui {
class CreateUser;
}

class CreateUser : public QDialog
{
    Q_OBJECT

public:
    explicit CreateUser(QWidget *parent = 0);
    ~CreateUser();

    // get new created user
    User getData() const;
    void setData(const User& user);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::CreateUser *ui;
};

#endif // CREATEUSER_H

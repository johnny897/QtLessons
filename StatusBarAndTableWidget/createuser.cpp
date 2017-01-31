#include "createuser.h"
#include "ui_createuser.h"

#include <QMessageBox>

CreateUser::CreateUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateUser)
{
    ui->setupUi(this);
    setWindowTitle("Create user");
}

CreateUser::~CreateUser()
{
    delete ui;
}

User CreateUser::getData() const
{
    User user(ui->nameLe->text(), ui->surnameLe->text(), ui->nationLe->text());

    return user;
}

void CreateUser::setData(const User& user)
{
    ui->nameLe->setText(user.name);
    ui->surnameLe->setText(user.surname);
    ui->nationLe->setText(user.nation);
}

void CreateUser::on_buttonBox_accepted()
{
}

void CreateUser::on_buttonBox_rejected()
{

}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createuser.h"

namespace Ui {
class MainWindow;
}

typedef std::vector<User>   Users;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_user_triggered();
    void on_actionEdit_triggered();
    void on_actionRemove_triggered();

    virtual void resizeEvent(QResizeEvent * event);

private:
    bool appendUser(const User& user);
    void processReject();

private:
    Ui::MainWindow *ui;
    CreateUser createUser;
    Users   users;
};

#endif // MAINWINDOW_H

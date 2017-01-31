#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QResizeEvent>


#include "user.h"

const int MaxCount = 2;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    createUser(this)
{
    ui->setupUi(this);

    QTableWidget* pTable = ui->usersTable;
    pTable->setColumnCount(3);

    pTable->setHorizontalHeaderItem( 0, new QTableWidgetItem("Name"));
    pTable->setHorizontalHeaderItem( 1, new QTableWidgetItem("Surname"));
    pTable->setHorizontalHeaderItem( 2, new QTableWidgetItem("Nation"));

    pTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    pTable->setSelectionMode(QAbstractItemView::SingleSelection);
    pTable->setStyleSheet("QTableWidget {selection-background-color: orange;}");

    ui->statusBar->addPermanentWidget(ui->progressBar);
    ui->progressBar->setRange(0, MaxCount);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_user_triggered()
{
    if(int(users.size()) < MaxCount) {
        if(QDialog::Rejected == createUser.exec()) {
            processReject();
            return;
        }

        User user = createUser.getData();
        appendUser(user);
    }
    else {
        QMessageBox::warning(this, "Max user count", "A user count has the maximum value. Please, remove some users to append new.");
    }
}

void MainWindow::on_actionEdit_triggered()
{
    QList<QTableWidgetItem*> items = ui->usersTable->selectedItems();
    if(items.empty())
        return;

    QString name = items.at(0)->text();
    QString surname = items.at(1)->text();
    QString nation = items.at(2)->text();

    QString oldTitle = createUser.windowTitle();
    createUser.setWindowTitle("Edit user");

    User oldData = createUser.getData();
    User editData(name, surname, nation);

    createUser.setData(editData);
    if(QDialog::Rejected != createUser.exec()) {
        User editedUser = createUser.getData();

        items.at(0)->setText(editedUser.name);
        items.at(1)->setText(editedUser.surname);
        items.at(2)->setText(editedUser.nation);

        QList<QTableWidgetSelectionRange> ranges = ui->usersTable->selectedRanges();
        const QTableWidgetSelectionRange& range = ranges.at(0);

        User& storedUser = users[range.topRow()];
        storedUser = editedUser;
    }

    // restore old data
    createUser.setWindowTitle(oldTitle);
    createUser.setData(oldData);
}

void MainWindow::on_actionRemove_triggered()
{
    QList<QTableWidgetSelectionRange> ranges = ui->usersTable->selectedRanges();
    if(ranges.empty()) {
        ui->statusBar->showMessage("Thre's no items selected to remove.", 2000);
        return;
    }

    const QTableWidgetSelectionRange& range = ranges.at(0);

    int removeIndex = range.topRow();
    ui->usersTable->removeRow(removeIndex);

    Users::iterator eraseIt = users.begin();
    std::advance(eraseIt, removeIndex);
    users.erase(eraseIt);
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    QMainWindow::resizeEvent(event);

    const QSize& oldSize = event->oldSize();

    QTableWidget* pTable = ui->usersTable;
    int tableWidth = oldSize.height() == -1 ? 380 : pTable->width();

    // set column widthes
    pTable->setColumnWidth(0, tableWidth / 3);
    pTable->setColumnWidth(1, tableWidth / 3);
    pTable->setColumnWidth(2, tableWidth / 3);
}

bool MainWindow::appendUser(const User& user)
{
    if(int(users.size()) >= MaxCount)
        return false;

    users.push_back(user);

    QTableWidget* pTable = ui->usersTable;
    pTable->insertRow(pTable->rowCount());

    pTable->setItem(pTable->rowCount() - 1, 0, new QTableWidgetItem(user.name));
    pTable->setItem(pTable->rowCount() - 1, 1, new QTableWidgetItem(user.surname));
    pTable->setItem(pTable->rowCount() - 1, 2, new QTableWidgetItem(user.nation));

    ui->statusBar->showMessage("New user appended.", 2000);

    ui->progressBar->setValue(ui->progressBar->value() + 1);

    return true;
}

void MainWindow::processReject()
{
    ui->statusBar->showMessage("New user creation has cancelled.", 2000);
}

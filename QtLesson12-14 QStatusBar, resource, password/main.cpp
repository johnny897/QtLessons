#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

bool compare(int vecVal, int foundVal) {
    return vecVal < foundVal;
}

int main(int argc, char *argv[])
{
    typedef std::vector<int> Ints;
    Ints digitVec = { 4, 7, 10, 3, 2, 11, 3, 5, 8, 22, 34};
    std::sort(digitVec.begin(), digitVec.end());

    auto found = std::lower_bound(digitVec.begin(), digitVec.end(), 22, compare);
    if(found == digitVec.end()) {
        qDebug() << "Value is not found!!!";
    }
    else {
        qDebug() << "Value is found!!!";
    }


    std::list<int> digitList;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

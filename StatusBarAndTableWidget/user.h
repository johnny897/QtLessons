#ifndef USER_H
#define USER_H

#include <QString>

struct User {
    User(const QString& name, const QString& surname, const QString& nation);

    QString name;
    QString surname;
    QString nation;
};

#endif // USER_H

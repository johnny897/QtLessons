/********************************************************************************
** Form generated from reading UI file 'createuser.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSER_H
#define UI_CREATEUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateUser
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLe;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *surnameLe;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *nationLe;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateUser)
    {
        if (CreateUser->objectName().isEmpty())
            CreateUser->setObjectName(QString::fromUtf8("CreateUser"));
        CreateUser->resize(305, 216);
        verticalLayout_2 = new QVBoxLayout(CreateUser);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CreateUser);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setBaseSize(QSize(370, 0));

        horizontalLayout->addWidget(label);

        nameLe = new QLineEdit(groupBox);
        nameLe->setObjectName(QString::fromUtf8("nameLe"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(nameLe->sizePolicy().hasHeightForWidth());
        nameLe->setSizePolicy(sizePolicy);
        nameLe->setMinimumSize(QSize(219, 25));
        nameLe->setBaseSize(QSize(170, 0));

        horizontalLayout->addWidget(nameLe);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        surnameLe = new QLineEdit(groupBox);
        surnameLe->setObjectName(QString::fromUtf8("surnameLe"));
        surnameLe->setMinimumSize(QSize(200, 25));

        horizontalLayout_2->addWidget(surnameLe);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        nationLe = new QLineEdit(groupBox);
        nationLe->setObjectName(QString::fromUtf8("nationLe"));
        nationLe->setMinimumSize(QSize(215, 25));

        horizontalLayout_3->addWidget(nationLe);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(CreateUser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

        nameLe->raise();
        label->raise();
        surnameLe->raise();
        groupBox->raise();
        buttonBox->raise();

        retranslateUi(CreateUser);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateUser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateUser, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateUser);
    } // setupUi

    void retranslateUi(QDialog *CreateUser)
    {
        CreateUser->setWindowTitle(QApplication::translate("CreateUser", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CreateUser", "User", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateUser", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateUser", "Surname", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateUser", "Nation", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateUser: public Ui_CreateUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H

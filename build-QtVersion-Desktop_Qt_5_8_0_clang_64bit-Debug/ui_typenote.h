/********************************************************************************
** Form generated from reading UI file 'typenote.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYPENOTE_H
#define UI_TYPENOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>

#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

#include <QtWidgets/QPushButton>

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_typeNote
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    QLabel *label;
    QListWidget *type;

    QListWidget *listWidget;
    QPushButton *validate;


    void setupUi(QWidget *typeNote)
    {
        if (typeNote->objectName().isEmpty())
            typeNote->setObjectName(QStringLiteral("typeNote"));
        typeNote->resize(275, 269);
        verticalLayoutWidget = new QWidget(typeNote);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(39, 30, 181, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        type = new QListWidget(verticalLayoutWidget);
        type->setObjectName(QStringLiteral("type"));

        verticalLayout->addWidget(type);

        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        validate = new QPushButton(verticalLayoutWidget);
        validate->setObjectName(QStringLiteral("validate"));

        verticalLayout->addWidget(validate);



        retranslateUi(typeNote);

        QMetaObject::connectSlotsByName(typeNote);
    } // setupUi

    void retranslateUi(QWidget *typeNote)
    {
        typeNote->setWindowTitle(QApplication::translate("typeNote", "Form", Q_NULLPTR));

        label->setText(QApplication::translate("typeNote", "Cliquez sur un type de note:", Q_NULLPTR));

        validate->setText(QApplication::translate("typeNote", "Valider", Q_NULLPTR));

    } // retranslateUi

};

namespace Ui {
    class typeNote: public Ui_typeNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYPENOTE_H

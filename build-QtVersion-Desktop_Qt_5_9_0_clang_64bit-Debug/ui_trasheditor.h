/********************************************************************************
** Form generated from reading UI file 'trasheditor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRASHEDITOR_H
#define UI_TRASHEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrashEditor
{
public:
    QListWidget *trashedNotes;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *supp;
    QPushButton *save;

    void setupUi(QDialog *TrashEditor)
    {
        if (TrashEditor->objectName().isEmpty())
            TrashEditor->setObjectName(QStringLiteral("TrashEditor"));
        TrashEditor->resize(361, 283);
        trashedNotes = new QListWidget(TrashEditor);
        trashedNotes->setObjectName(QStringLiteral("trashedNotes"));
        trashedNotes->setGeometry(QRect(40, 30, 281, 201));
        label = new QLabel(TrashEditor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 6, 61, 20));
        horizontalLayoutWidget = new QWidget(TrashEditor);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(90, 240, 228, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        supp = new QPushButton(horizontalLayoutWidget);
        supp->setObjectName(QStringLiteral("supp"));

        horizontalLayout->addWidget(supp);

        save = new QPushButton(horizontalLayoutWidget);
        save->setObjectName(QStringLiteral("save"));

        horizontalLayout->addWidget(save);


        retranslateUi(TrashEditor);

        QMetaObject::connectSlotsByName(TrashEditor);
    } // setupUi

    void retranslateUi(QDialog *TrashEditor)
    {
        TrashEditor->setWindowTitle(QApplication::translate("TrashEditor", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("TrashEditor", "Corbeille", Q_NULLPTR));
        supp->setText(QApplication::translate("TrashEditor", "Supprimer", Q_NULLPTR));
        save->setText(QApplication::translate("TrashEditor", "Sauver", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrashEditor: public Ui_TrashEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRASHEDITOR_H

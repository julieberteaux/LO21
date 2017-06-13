/********************************************************************************
** Form generated from reading UI file 'formnote.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMNOTE_H
#define UI_FORMNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormNote
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *idNoteLabel;
    QLineEdit *idNoteLineEdit;
    QLabel *dateCreaLabel;
    QDateEdit *dateCreaDateEdit;
    QLabel *idVersionLabel;
    QLineEdit *idVersionLineEdit;
    QLabel *titleLabel;
    QLabel *dateEditLabel;
    QDateEdit *dateEditDateEdit;
    QLineEdit *titleLineEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *versionLayout;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *save;
    QPushButton *supp;

    void setupUi(QWidget *FormNote)
    {
        if (FormNote->objectName().isEmpty())
            FormNote->setObjectName(QStringLiteral("FormNote"));
        FormNote->resize(415, 484);
        formLayoutWidget = new QWidget(FormNote);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(8, 2, 381, 179));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        idNoteLabel = new QLabel(formLayoutWidget);
        idNoteLabel->setObjectName(QStringLiteral("idNoteLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, idNoteLabel);

        idNoteLineEdit = new QLineEdit(formLayoutWidget);
        idNoteLineEdit->setObjectName(QStringLiteral("idNoteLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, idNoteLineEdit);

        dateCreaLabel = new QLabel(formLayoutWidget);
        dateCreaLabel->setObjectName(QStringLiteral("dateCreaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, dateCreaLabel);

        dateCreaDateEdit = new QDateEdit(formLayoutWidget);
        dateCreaDateEdit->setObjectName(QStringLiteral("dateCreaDateEdit"));
        dateCreaDateEdit->setCurrentSection(QDateTimeEdit::DaySection);

        formLayout->setWidget(1, QFormLayout::FieldRole, dateCreaDateEdit);

        idVersionLabel = new QLabel(formLayoutWidget);
        idVersionLabel->setObjectName(QStringLiteral("idVersionLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, idVersionLabel);

        idVersionLineEdit = new QLineEdit(formLayoutWidget);
        idVersionLineEdit->setObjectName(QStringLiteral("idVersionLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, idVersionLineEdit);

        titleLabel = new QLabel(formLayoutWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, titleLabel);

        dateEditLabel = new QLabel(formLayoutWidget);
        dateEditLabel->setObjectName(QStringLiteral("dateEditLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, dateEditLabel);

        dateEditDateEdit = new QDateEdit(formLayoutWidget);
        dateEditDateEdit->setObjectName(QStringLiteral("dateEditDateEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, dateEditDateEdit);

        titleLineEdit = new QLineEdit(formLayoutWidget);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, titleLineEdit);

        verticalLayoutWidget = new QWidget(FormNote);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 189, 381, 121));
        versionLayout = new QVBoxLayout(verticalLayoutWidget);
        versionLayout->setObjectName(QStringLiteral("versionLayout"));
        versionLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget = new QWidget(FormNote);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(160, 350, 231, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        save = new QPushButton(horizontalLayoutWidget);
        save->setObjectName(QStringLiteral("save"));
        save->setAutoDefault(false);
        save->setFlat(false);

        horizontalLayout->addWidget(save);

        supp = new QPushButton(horizontalLayoutWidget);
        supp->setObjectName(QStringLiteral("supp"));

        horizontalLayout->addWidget(supp);


        retranslateUi(FormNote);

        save->setDefault(false);


        QMetaObject::connectSlotsByName(FormNote);
    } // setupUi

    void retranslateUi(QWidget *FormNote)
    {
        FormNote->setWindowTitle(QApplication::translate("FormNote", "Form", Q_NULLPTR));
        idNoteLabel->setText(QApplication::translate("FormNote", "idNote", Q_NULLPTR));
        dateCreaLabel->setText(QApplication::translate("FormNote", "Date de creation", Q_NULLPTR));
        dateCreaDateEdit->setDisplayFormat(QApplication::translate("FormNote", "dd/MM/yyyy", Q_NULLPTR));
        idVersionLabel->setText(QApplication::translate("FormNote", "idVersion", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("FormNote", "Titre", Q_NULLPTR));
        dateEditLabel->setText(QApplication::translate("FormNote", "Date d'\303\251dition", Q_NULLPTR));
        save->setText(QApplication::translate("FormNote", "Sauver", Q_NULLPTR));
        supp->setText(QApplication::translate("FormNote", "Supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormNote: public Ui_FormNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNOTE_H

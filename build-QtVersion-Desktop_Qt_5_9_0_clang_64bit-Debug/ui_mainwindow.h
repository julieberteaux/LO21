/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Notes;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QListWidget *activenotes;
    QVBoxLayout *verticalLayout_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_7;
    QFormLayout *formLayout;
    QLabel *idNoteLabel;
    QLineEdit *idNoteLineEdit;
    QLabel *dateCreaLabel;
    QDateEdit *dateCreaDateEdit;
    QLineEdit *idVersionLineEdit;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *dateEditLabel;
    QDateEdit *dateEditDateEdit;
    QLabel *idVersionLabel;
    QFormLayout *formLayout_3;
    QWidget *Relations;
    QGroupBox *groupBox_2;
    QLabel *label;
    QFrame *line;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(551, 413);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 551, 411));
        Notes = new QWidget();
        Notes->setObjectName(QStringLiteral("Notes"));
        verticalLayoutWidget = new QWidget(Notes);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 161, 361));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_6->addWidget(label_2);

        activenotes = new QListWidget(verticalLayoutWidget);
        activenotes->setObjectName(QStringLiteral("activenotes"));

        verticalLayout_6->addWidget(activenotes);


        verticalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayoutWidget_2 = new QWidget(Notes);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(172, 0, 341, 361));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        idNoteLabel = new QLabel(verticalLayoutWidget_2);
        idNoteLabel->setObjectName(QStringLiteral("idNoteLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, idNoteLabel);

        idNoteLineEdit = new QLineEdit(verticalLayoutWidget_2);
        idNoteLineEdit->setObjectName(QStringLiteral("idNoteLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, idNoteLineEdit);

        dateCreaLabel = new QLabel(verticalLayoutWidget_2);
        dateCreaLabel->setObjectName(QStringLiteral("dateCreaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, dateCreaLabel);

        dateCreaDateEdit = new QDateEdit(verticalLayoutWidget_2);
        dateCreaDateEdit->setObjectName(QStringLiteral("dateCreaDateEdit"));
        dateCreaDateEdit->setCurrentSection(QDateTimeEdit::DaySection);

        formLayout->setWidget(1, QFormLayout::FieldRole, dateCreaDateEdit);

        idVersionLineEdit = new QLineEdit(verticalLayoutWidget_2);
        idVersionLineEdit->setObjectName(QStringLiteral("idVersionLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, idVersionLineEdit);

        titleLabel = new QLabel(verticalLayoutWidget_2);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, titleLabel);

        titleLineEdit = new QLineEdit(verticalLayoutWidget_2);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, titleLineEdit);

        dateEditLabel = new QLabel(verticalLayoutWidget_2);
        dateEditLabel->setObjectName(QStringLiteral("dateEditLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, dateEditLabel);

        dateEditDateEdit = new QDateEdit(verticalLayoutWidget_2);
        dateEditDateEdit->setObjectName(QStringLiteral("dateEditDateEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, dateEditDateEdit);

        idVersionLabel = new QLabel(verticalLayoutWidget_2);
        idVersionLabel->setObjectName(QStringLiteral("idVersionLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, idVersionLabel);


        verticalLayout_7->addLayout(formLayout);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));

        verticalLayout_7->addLayout(formLayout_3);

        tabWidget->addTab(Notes, QString());
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        activenotes->raise();
        Relations = new QWidget();
        Relations->setObjectName(QStringLiteral("Relations"));
        groupBox_2 = new QGroupBox(Relations);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, -20, 171, 411));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 101, 16));
        line = new QFrame(groupBox_2);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(160, 20, 20, 401));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(Relations, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Notes actives", Q_NULLPTR));
        idNoteLabel->setText(QApplication::translate("MainWindow", "idNote", Q_NULLPTR));
        dateCreaLabel->setText(QApplication::translate("MainWindow", "Date de creation", Q_NULLPTR));
        dateCreaDateEdit->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM/yyyy", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("MainWindow", "Titre", Q_NULLPTR));
        dateEditLabel->setText(QApplication::translate("MainWindow", "Date d'\303\251dition", Q_NULLPTR));
        idVersionLabel->setText(QApplication::translate("MainWindow", "idVersion", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Notes), QApplication::translate("MainWindow", "Notes", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Relations :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Relations), QApplication::translate("MainWindow", "Relations", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

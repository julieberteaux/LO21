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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenTrash;
    QAction *actiontest;
    QAction *exit;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Notes;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QListWidget *activenotes;
    QPushButton *createNote;
    QVBoxLayout *verticalLayout_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *centre;
    QWidget *Corbeille;
    QListWidget *trashedNotes;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *supp;
    QPushButton *restore;
    QWidget *Relations;
    QGroupBox *groupBox_2;
    QLabel *label;
    QFrame *line;
    QListWidget *activerelations;
    QPushButton *createRelation;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *centreRelation;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(833, 597);
        actionOpenTrash = new QAction(MainWindow);
        actionOpenTrash->setObjectName(QStringLiteral("actionOpenTrash"));
        actiontest = new QAction(MainWindow);
        actiontest->setObjectName(QStringLiteral("actiontest"));
        exit = new QAction(MainWindow);
        exit->setObjectName(QStringLiteral("exit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 30, 651, 481));
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

        createNote = new QPushButton(verticalLayoutWidget);
        createNote->setObjectName(QStringLiteral("createNote"));

        verticalLayout_4->addWidget(createNote);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayoutWidget_2 = new QWidget(Notes);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(172, 0, 391, 401));
        centre = new QVBoxLayout(verticalLayoutWidget_2);
        centre->setObjectName(QStringLiteral("centre"));
        centre->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(Notes, QString());
        Corbeille = new QWidget();
        Corbeille->setObjectName(QStringLiteral("Corbeille"));
        trashedNotes = new QListWidget(Corbeille);
        trashedNotes->setObjectName(QStringLiteral("trashedNotes"));
        trashedNotes->setGeometry(QRect(190, 20, 281, 201));
        horizontalLayoutWidget = new QWidget(Corbeille);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(240, 250, 228, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        supp = new QPushButton(horizontalLayoutWidget);
        supp->setObjectName(QStringLiteral("supp"));

        horizontalLayout->addWidget(supp);

        restore = new QPushButton(horizontalLayoutWidget);
        restore->setObjectName(QStringLiteral("restore"));

        horizontalLayout->addWidget(restore);

        tabWidget->addTab(Corbeille, QString());
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
        activerelations = new QListWidget(groupBox_2);
        activerelations->setObjectName(QStringLiteral("activerelations"));
        activerelations->setGeometry(QRect(10, 70, 147, 283));
        createRelation = new QPushButton(groupBox_2);
        createRelation->setObjectName(QStringLiteral("createRelation"));
        createRelation->setGeometry(QRect(10, 370, 161, 32));
        verticalLayoutWidget_3 = new QWidget(Relations);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(190, 10, 391, 401));
        centreRelation = new QVBoxLayout(verticalLayoutWidget_3);
        centreRelation->setObjectName(QStringLiteral("centreRelation"));
        centreRelation->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(Relations, QString());
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 833, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(activenotes, tabWidget);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(exit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpenTrash->setText(QApplication::translate("MainWindow", "Afficher le contenu", Q_NULLPTR));
        actiontest->setText(QApplication::translate("MainWindow", "test", Q_NULLPTR));
        exit->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Notes actives", Q_NULLPTR));
        createNote->setText(QApplication::translate("MainWindow", "Nouvelle note", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Notes), QApplication::translate("MainWindow", "Notes", Q_NULLPTR));
        supp->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        restore->setText(QApplication::translate("MainWindow", "Restaurer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Corbeille), QApplication::translate("MainWindow", "Corbeille", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Relations :", Q_NULLPTR));
        createRelation->setText(QApplication::translate("MainWindow", "Nouvelle relation", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Relations), QApplication::translate("MainWindow", "Relations", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

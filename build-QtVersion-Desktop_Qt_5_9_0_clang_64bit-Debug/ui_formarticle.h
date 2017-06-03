/********************************************************************************
** Form generated from reading UI file 'formarticle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMARTICLE_H
#define UI_FORMARTICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormArticle
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *articleLayout;
    QLabel *textLabel;
    QTextEdit *textTextEdit;

    void setupUi(QWidget *FormArticle)
    {
        if (FormArticle->objectName().isEmpty())
            FormArticle->setObjectName(QStringLiteral("FormArticle"));
        FormArticle->resize(370, 179);
        horizontalLayoutWidget = new QWidget(FormArticle);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 0, 339, 171));
        articleLayout = new QHBoxLayout(horizontalLayoutWidget);
        articleLayout->setObjectName(QStringLiteral("articleLayout"));
        articleLayout->setContentsMargins(0, 0, 0, 0);
        textLabel = new QLabel(horizontalLayoutWidget);
        textLabel->setObjectName(QStringLiteral("textLabel"));

        articleLayout->addWidget(textLabel);

        textTextEdit = new QTextEdit(horizontalLayoutWidget);
        textTextEdit->setObjectName(QStringLiteral("textTextEdit"));

        articleLayout->addWidget(textTextEdit);


        retranslateUi(FormArticle);

        QMetaObject::connectSlotsByName(FormArticle);
    } // setupUi

    void retranslateUi(QWidget *FormArticle)
    {
        FormArticle->setWindowTitle(QApplication::translate("FormArticle", "Form", Q_NULLPTR));
        textLabel->setText(QApplication::translate("FormArticle", "Texte", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormArticle: public Ui_FormArticle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMARTICLE_H

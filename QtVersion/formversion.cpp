#include "formversion.h"

FormVersion::FormVersion(QWidget *parent): QWidget(parent){}
FormVersion::~FormVersion(){}

FormArticle::FormArticle(Article* a, QWidget *parent): FormVersion(parent), article(a){
    textLabel=new QLabel("Texte:");
    text=new QTextEdit();
    textHbox=new QHBoxLayout();
    //text->setText(a->getText());
    textHbox->addWidget(textLabel);
    textHbox->addWidget(text);
    this->setLayout(textHbox);

}
FormArticle::~FormArticle(){
    delete textLabel;
    delete text;
    delete textHbox;
}

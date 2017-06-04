#include "formversion.h"

FormVersion::FormVersion(QWidget *parent): QWidget(parent){}
FormVersion::~FormVersion(){}

/***********************ARTICLE***********************/

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

/***********************IMAGE***********************/

FormImage::FormImage(Image *a, QWidget *parent): FormVersion(parent), image(a){
    imageLabel=new QLabel();
    imageHbox=new QHBoxLayout();
    imageLabel->setPixmap(QPixmap("../../../Images/vacances.jpeg").scaled(250,250,Qt::KeepAspectRatio));

    imageHbox->addWidget(imageLabel);
    this->setLayout(imageHbox);
}

FormImage::~FormImage(){
    delete imageLabel;
    delete imageHbox;
}

#include "formarticle.h"
#include "ui_formarticle.h"

FormArticle::FormArticle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormArticle)
{
    ui->setupUi(this);
}

FormArticle::~FormArticle()
{
    delete ui;
}

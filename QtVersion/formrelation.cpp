#include "formrelation.h"
#include "ui_formrelation.h"

FormRelation::FormRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormRelation)
{
    ui->setupUi(this);
}

FormRelation::~FormRelation()
{
    delete ui;
}

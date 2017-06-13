#ifndef FORMRELATION_H
#define FORMRELATION_H

#include <QDialog>

namespace Ui {
class FormRelation;
}

class FormRelation : public QDialog
{
    Q_OBJECT

public:
    explicit FormRelation(QWidget *parent = 0);
    ~FormRelation();

private:
    Ui::FormRelation *ui;
};

#endif // FORMRELATION_H

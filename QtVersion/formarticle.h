#ifndef FORMARTICLE_H
#define FORMARTICLE_H

#include <QWidget>

namespace Ui {
class FormArticle;
}

class FormArticle : public QWidget
{
    Q_OBJECT

public:
    explicit FormArticle(QWidget *parent = 0);
    ~FormArticle();

private:
    Ui::FormArticle *ui;
};

#endif // FORMARTICLE_H

#ifndef FORMVERSION_H
#define FORMVERSION_H
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QTextEdit>
class Article;
class Image;

class FormVersion : public QWidget{
        Q_OBJECT
public:
    FormVersion(QWidget *parent = 0);
    virtual ~FormVersion();
};

class FormArticle : public FormVersion{
    Article *article;
    QLabel *textLabel;
    QTextEdit *text;
    //QPushButton *save;
    QHBoxLayout *textHbox;
public:
    FormArticle(Article* a, QWidget *parent = 0);
    ~FormArticle();

};

class FormImage : public FormVersion{
    Image *image;
    QLabel *imageLabel;
    QHBoxLayout *imageHbox;
public:
    FormImage(Image* a, QWidget *parent = 0);
    ~FormImage();

};

#endif // FORMVERSION_H

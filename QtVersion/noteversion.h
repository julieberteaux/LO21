#ifndef NOTEVERSION_H
#define NOTEVERSION_H

#include <iostream>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <vector>
#include<QDebug>
#include "date.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QTextEdit>
#include <QWidget>
#include <QXmlStreamWriter>

class FormVersion;

class NoteVersion{
    friend class Note;
protected:
    unsigned int idVersion;
    Date dateEdit;

private:
    QString title;
    //template<typename T> static DerivedRegister<T> reg;

    void saveNoteVersion(QXmlStreamWriter* stream) const;
    void loadNoteVersion(QXmlStreamReader& stream);

    virtual void saveNoteVersionType(QXmlStreamWriter& stream) const=0;
    virtual void loadNoteVersionType(QXmlStreamReader& stream)=0;


public :

    NoteVersion(unsigned int v, const QString& t);
    const QString& getTitle() const ;
    void setTitle(const QString& str);
    const Date& getDateEdit() const;
    void setDateEdit(const Date& d);
    virtual ~NoteVersion();
    unsigned int getIdVersion() const;

    virtual NoteVersion* clone(unsigned int id) const=0;
    virtual QString type() const =0;
    //A mettre en virtuelle pure
    virtual FormVersion* formVersion()=0;

/*
 addNoteVersion :
    copyLatest : copie de la dernière version
    demande les parametre a changer
    modifie la copie de note: changer dateEdit, id version, title...
    ajout dans la liste des versions de copyLatest :
    Incremente latestVersion

 changeVersion : restaurer une ancienne version en tant que version actuelle (design pattern : memento?)

*/

};

/*********************************NoteVersionFactory***********************/
//used for load method
template<typename T> NoteVersion * createT() { return new T;}

class NoteVersionFactory {
public:
    typedef std::map<QString, NoteVersion*(*)()> map_type;

private:
    static map_type * map;
public:
    static map_type * getMap();
    static NoteVersion * createInstance(const QString & s) ;

};

template<typename T>
struct DerivedRegister :public NoteVersionFactory {
    DerivedRegister(QString const& s) {
        getMap()->insert(std::make_pair(s, &createT<T>));
    }
};

/********************************** Article ****************************/

class Article : public NoteVersion {
    friend class Note;

    QString text;
    static DerivedRegister<Article> reg;

    void saveNoteVersionType(QXmlStreamWriter &stream) const;
    void loadNoteVersionType(QXmlStreamReader &xml);

public :
    Article (const QString& t=QString(), const QString& te=QString());

    const QString& getText() const;
    void setText(const QString& str);

    Article* clone(unsigned int id) const;
    QString type() const;
    FormVersion* formVersion();
};


/********************************** Task ****************************/

class Task : public NoteVersion {
    friend class Note;

    QString action;
    unsigned int priority;
    Date deadline;
    enum Status {waiting, ended, in_progress};
    Status status;
    static DerivedRegister<Task> reg;

    void saveNoteVersionType(QXmlStreamWriter &stream) const;
    void loadNoteVersionType(QXmlStreamReader &stream);

public :

    Task (const QString& t=QString(),const QString& a=QString(), unsigned int p=0, const Date d=Date(1,1,2100), const Status s=Status());

    const QString& getAction() const ;
    unsigned int getPriority() const ;
    const Date& getDeadline() const ;
    const Status& getStatus() const ;
    Task* clone(unsigned int id) const;
    QString type() const ;
    FormVersion* formVersion();

};
/********************************** Image ****************************/

class Image : public NoteVersion {
    friend class Note;

    QString description;
    QString file;
    static DerivedRegister<Image> reg;

    void saveNoteVersionType(QXmlStreamWriter &stream) const;
    void loadNoteVersionType(QXmlStreamReader &xml);


public :

    Image(const QString& t=QString(), const QString& d=QString(), const QString& f=QString());
    const QString& getDescription() const;
    const QString& getFile() const ;
    Image* clone(unsigned int id) const;
    QString type() const ;
    FormVersion* formVersion();
};


/********************************** Audio ****************************/

class Audio : public NoteVersion {
    friend class Note;

    QString description;
    QString file;

    void saveNoteVersionType(QXmlStreamWriter& stream) const;
    void loadNoteVersionType(QXmlStreamReader& xml);

public :

    Audio (const QString& t, const QString& d, const QString& f);

    const QString& getDescription() const;
    const QString& getFile() const;
    Audio* clone(unsigned int id) const;
    QString type() const;
    FormVersion* formVersion();
};


/********************************** Video ****************************/

class Video : public NoteVersion {
    friend class Note;

    QString description;
    QString file;

    void saveNoteVersionType(QXmlStreamWriter& stream) const;
    void loadNoteVersionType(QXmlStreamReader& xml);

public :

    Video (const QString& t, const QString& d, const QString& f);

    const QString& getDescription() const;
    const QString& getFile() const;
    Video* clone(unsigned int id) const;
    QString type() const;
    FormVersion* formVersion();
};

/*************************INTERFACE NOTEVERSION************************/
class FormVersion : public QWidget{
        Q_OBJECT
public:
    FormVersion(QWidget *parent = 0);
    virtual void saveVersion(NoteVersion*)=0;
    virtual ~FormVersion()=0;
};

class FormArticle : public FormVersion{
    Article *article;
    QLabel *textLabel;
    QTextEdit *text;
    QHBoxLayout *textHbox;
public:
    FormArticle(Article *a, QWidget *parent = 0);
    void saveVersion(NoteVersion*ver);
    ~FormArticle();
};

class FormImage : public FormVersion{
    Image *image;
    QLabel *imageLabel;
    QHBoxLayout *imageHbox;
public:
    FormImage(Image* a, QWidget *parent = 0);
    void saveVersion(NoteVersion*){};
    ~FormImage();

};
#endif // NOTEVERSION_H

#ifndef NOTEVERSION_H
#define NOTEVERSION_H

#include <iostream>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <vector>
#include "date.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QXmlStreamWriter>


class NoteVersion{
    friend class Note;
protected:
    unsigned int idVersion;

private:
    QString title;
    Date dateEdit;

    void saveNoteVersion(QXmlStreamWriter* stream) const;
    virtual void saveNoteVersionType(QXmlStreamWriter* stream) const=0;
public :

    NoteVersion(unsigned int v, const QString& t): idVersion(v), title(t), dateEdit(){dateEdit.today();}
    const QString& getTitle() const {return title;}
    void setTitle(const QString& str) {title=str;}
    virtual ~NoteVersion(){};
    unsigned int getIdVersion() const{return idVersion;}

    //NoteVersion(NoteVersion &){}
    virtual NoteVersion* clone(unsigned int id) const=0;
    virtual QString type() const =0;
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

template<typename T> NoteVersion * createT() { return new T;}

class NoteVersionFactory {
public:
    typedef std::map<QString, NoteVersion*(*)()> map_type;

private:
    static map_type * map;

protected:
    static map_type * getMap() {
        // never delete'ed. (exist until program termination)
        // because we can't guarantee correct destruction order
        if(!map) { map = new map_type; }
        return map;
    }

public:

    static NoteVersion * createInstance(const QString & s) {
        map_type::iterator it = getMap()->find(s);
        if(it == getMap()->end())
            return 0;
        return it->second();
    }
};

template<typename T>
struct DerivedRegister : NoteVersionFactory {
    DerivedRegister(QString const& s) {
        getMap()->insert(std::make_pair(s, &createT<T>));
    }
};

/********************************** Article ****************************/

class Article : public NoteVersion {
    friend class Note;

    QString text;
    void saveNoteVersionType(QXmlStreamWriter* stream) const;

    static DerivedRegister<Article> reg;

public :
    //Article():NoteVersion(0, QString()), text(QString()){}
    Article (const QString& t=QString(), const QString& te=QString()): NoteVersion(0, t), text(te){}

    const QString& getText() const {return text;}
    void setText(const QString& str) {text=str;}

    Article* clone(unsigned int id) const;
    QString type() const {return "Article";}

};


/********************************** Task ****************************/

class Task : public NoteVersion {
    friend class Note;

    QString action;
    unsigned int priority;
    Date deadline;
    enum Status {waiting, ended, in_progress};
    Status status;

    void saveNoteVersionType(QXmlStreamWriter* stream) const;
public :

    Task (const QString& t,const QString& a, unsigned int p, const Date d, const Status s): NoteVersion(0, t), action(a), priority(p), deadline(d), status(s){}

    const QString& getAction() const {return action;}
    unsigned int getPriority() const {return priority;}
    const Date& getDeadline() const {return deadline;}
    const Status& getStatus() const {return status;}
    Task* clone(unsigned int id) const;
    QString type() const {return "Task";}

};
/********************************** Image ****************************/

class Image : public NoteVersion {
    friend class Note;

    QString description;
    QString file;

    void saveNoteVersionType(QXmlStreamWriter* stream) const;


public :

    Image(const QString& t, const QString& d, const QString& f): NoteVersion(0, t), description(d), file(f){}

    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file;}
    Image* clone(unsigned int id) const;
    QString type() const {return "Image";}

};


/********************************** Audio ****************************/

class Audio : public NoteVersion {
    friend class Note;

    QString description;
    QString file;

    void saveNoteVersionType(QXmlStreamWriter* stream) const;

public :

    Audio (const QString& t, const QString& d, const QString& f): NoteVersion(0, t), description(d), file(f){}

    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file;}
    Audio* clone(unsigned int id) const;
    QString type() const {return "Audio";}

};


/********************************** Video ****************************/

class Video : public NoteVersion {
    friend class Note;

    QString description;
    QString file;

    void saveNoteVersionType(QXmlStreamWriter* stream) const;

public :

    Video (const QString& t, const QString& d, const QString& f): NoteVersion(0, t), description(d), file(f){}

    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file;}
    Video* clone(unsigned int id) const;
    QString type() const {return "Video";}

};


#endif // NOTEVERSION_H

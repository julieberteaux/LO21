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
    //unsigned int idNote;
protected:
    unsigned int idVersion;

private:
    QString title;
    Date dateEdit;
    //Date dateCrea;

    virtual void saveNoteVersion(QXmlStreamWriter* stream) const=0;
public :

    NoteVersion(unsigned int v, const QString& t): idVersion(v), title(t), dateEdit(){dateEdit.today();}
    const QString& getTitle() const {
        return title;
    }
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


/********************************** Article ****************************/

class Article : public NoteVersion {
    friend class Note;

    QString text;
    void saveNoteVersion(QXmlStreamWriter* stream) const;

public :

    Article (const QString& t, const QString& te): NoteVersion(0, t), text(te){}

    const QString& getText() const {return text;}
    void setText(const QString& str) {text=str;}

    Article* clone(unsigned int id) const;
    QString type() const {return "Article";}

};


/********************************** Task ****************************/

class Task : public NoteVersion {
    QString action;
    unsigned int priority;
    Date deadline;
    enum Status {waiting, ended, in_progress};
    Status status;

public :

    Task (const QString& t,const QString& a, unsigned int p, const Date d, const Status s): NoteVersion(0, t), action(a), priority(p), deadline(d), status(s){}

    const QString& getAction() const {return action;}
    unsigned int getPriority() const {return priority;}
    const Date& getDeadline() const {return deadline;}
    const Status& getStatus() const {return status;}
    Task* clone(unsigned int id) const;

};
/********************************** Image ****************************/

class Image : public NoteVersion {
    QString description;
    QString file;


public :

    Image(const QString& t, const QString& d, const QString& f): NoteVersion(0, t), description(d), file(f){}

    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file;}
    Image* clone(unsigned int id) const;

};


/********************************** Audio ****************************/

class Audio : public NoteVersion {
    QString description;
    QString file;


public :

    Audio (const QString& t, const QString& d, const QString& f): NoteVersion(0, t), description(d), file(f){}

    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file;}
    Audio* clone(unsigned int id) const;

};


/********************************** Video ****************************/

class Video : public NoteVersion {
    QString description;
    QString file;


public :

    Video (const QString& t, const QString& d, const QString& f): NoteVersion(0, t), description(d), file(f){}

    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file;}
    Video* clone(unsigned int id) const;

};


#endif // NOTEVERSION_H

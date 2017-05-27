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


class NoteVersion{
    unsigned int idNote;
    unsigned int idVersion;
    QString title;
    Date dateEdit;
    Date dateCrea;


public :

    NoteVersion( unsigned int n, unsigned int v, const QString& t, const Date& de, const Date& dc): idNote(n), idVersion(v), title(t), dateEdit(de),dateCrea(dc){}
    const QString& getTitle() const {return title;}
    NoteVersion(NoteVersion &){}
    void addNoteVersion(unsigned int id);

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
    QString text;


public :

    Article (unsigned int n, unsigned int v, const QString& t, const Date& de, const Date& dc, const QString& te): NoteVersion(n, v, t, de, dc), text(te){}

    const QString& getText() const {return text;}


};


/********************************** Task ****************************/

class Task : public NoteVersion {
    QString action;
    unsigned int priority;
    Date deadline;
    enum Status {waiting, ended, in_progress};
    Status status;

public :

    Task (unsigned int n, unsigned int v, const QString& t, const Date& de, const Date& dc, const QString& a, unsigned int p, const Date d, const Status s): NoteVersion(n, v, t, de, dc), action(a), priority(p), deadline(d), status(s){}

    const QString& getAction() const {return action;}
    unsigned int getPriority() const {return priority;}
    const Date& getDeadline() const {return deadline;}
    const Status& getStatus() const {return status;}


};


/********************************** Image ****************************/

class Image : public NoteVersion {
    QString description;
    QString file;


public :

    Image(unsigned int n, unsigned int v, const QString& t, const Date& de, const Date& dc, const QString& d, const QString& f): NoteVersion(n, v, t, de, dc), description(d), file(f){}

    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file;}


};


/********************************** Audio ****************************/

class Audio : public NoteVersion {
    QString description;
    QString file;


public :

    Audio (unsigned int n, unsigned int v, const QString& t, const Date& de, const Date& dc, const QString& d, const QString& f): NoteVersion(n, v, t, de, dc), description(d), file(f){}

    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file;}


};


/********************************** Video ****************************/

class Video : public NoteVersion {
    QString description;
    QString file;


public :

    Video (unsigned int n, unsigned int v, const QString& t, const Date& de, const Date& dc, const QString& d, const QString& f): NoteVersion(n, v, t, de, dc), description(d), file(f){}

    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file;}


};



#endif // NOTEVERSION_H

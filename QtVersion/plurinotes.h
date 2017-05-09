
#ifndef PLURINOTES_H
#define PLURINOTES_H
#include <iostream>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <vector>

class Exception{
    QString info;
public:
    Exception(const QString& str): info(str){}
    const QString & getInfo() const{return info;}
};

class Date{
    int day;
    int month;
    int year;
public:
    int getDay(){return day;}
    int getMonth(){return month;}
    int getYear(){return year;}
    void setDay(const int & d){
        if ((d>=1) && (d<=31))
            day=d;
        else throw Exception("Jour incorrect");
    }
    void setMonth(const int & m){
        if ((m>=1) && (m<=12))
            month=m;
        else throw Exception("Mois incorrect");
    }
    void setYear(const int & y){year=y;}
    Date(int d, int m, int y){
        setDay(d);
        setMonth(m);
        setYear(y);
    }
};



class Note{
    unsigned int idNote;
public:
    Note(const int& id): idNote(id){}//used by addNote in NotesManager
    unsigned int getidNote(){return idNote;}
/*
     changeState
     getLatestVersion
*/
};

class NotesManager{
    //singleton
    //we use a vector of Notes
    //notes are sorted by idNote
    std::vector<Note*>* notes;

    NotesManager(): notes(nullptr){}
    ~NotesManager(){}

public:
    static NotesManager& getInstance(){
        static NotesManager instance;
        return instance;
    }
    //addNote adds a note with a new id which is greatest id(=id of latest note) + 1
    Note& addNote();
    Note& getNote(unsigned int id);
/*
    modifyNote (va appeler addNoteVersion ou copyVersion)
    deleteNote
    getNote (appelle getLatestVersion)
    listNotes (voir toutes les notes active?)
*/
};


class NoteVersion{
    int idNote;
    QString title;
    Date dateCrea;
    Date dateEdit;
    int idVersion;
    
public :
    const string& getTitle() const {return title;}
    NoteVersion( const int& n, const int& v, const string& t, const date& de, const date& dc): idNote(n), idVersion(v), title(t), dateEdit(de),dateCrea(dc){}
    NoteVersion(NoteVersion &)
    
/*
 addNoteVersion :
    copyLatest : copie de la dernière version
    ajout dans la liste des versions de copyLatest
    Incremente latestVersion
 changeVersion : restaurer une ancienne version en tant que version actuelle (design pattern : memento?)

*/

};

class Article : public NoteVersion {
    QString text;
    
    
public :
    Article (const int& n, const int& v, const string& t, const date& de, const date& dc, const string& te): NoteVersion(n, v, t, de, dc), text(te){}
    
    const string& getText() const {return text;}
























#endif // PLURINOTES_H

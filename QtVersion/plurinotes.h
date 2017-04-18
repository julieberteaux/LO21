
#ifndef PLURINOTES_H
#define PLURINOTES_H

#include <QString>
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
        else throw Exception("Wrong day");
    }
    void setMonth(const int & m){
        if ((m>=1) && (m<=12))
            month=m;
        else throw Exception("Wrong month");
    }
    void setYear(const int & y){year=y;}
    Date(int d, int m, int y){
        setDay(d);
        setMonth(m);
        setYear(y);
    }
};



class Note{
    int idNote;
public:
    Note(const int& id): idNote(id){}
    int getidNote(){return idNote;}
};

class NotesManager{
    //singleton
    //we use a vector of Notes
    std::vector<Note*> notes;

    NotesManager();
    ~NotesManager();

public:
    static NotesManager& getInstance(){
        static NotesManager instance;
        return instance;
    }
    Note& addNote();
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
};
#endif // PLURINOTES_H

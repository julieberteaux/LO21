
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

/********************************** Note & co ****************************/

class Note{
    unsigned int idNote;
    Date dateCrea;
    std::vector<NoteVersion*>* listVersion;
    NoteVersion* latestVersion;

public:
    Note(const int& id): idNote(id){}     //used by addNote in NotesManager
    unsigned int getidNote(){return idNote;}
    ~Note(){}
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
    const Qstring& getTitle() const {return title;}
    NoteVersion( const int& n, const int& v, const Qstring& t, const date& de, const date& dc): idNote(n), idVersion(v), title(t), dateEdit(de),dateCrea(dc){}
    NoteVersion(NoteVersion &)
    
/*
 addNoteVersion :
    copyLatest : copie de la dernière version
    ajout dans la liste des versions de copyLatest
    Incremente latestVersion
 changeVersion : restaurer une ancienne version en tant que version actuelle (design pattern : memento?)

*/

};

/********************************** Article ****************************/

class Article : public NoteVersion {
    QString text;
    
    
public :
    Article (const int& n, const int& v, const Qstring& t, const date& de, const date& dc, const Qstring& te): NoteVersion(n, v, t, de, dc), text(te){}
    
    const Qstring& getText() const {return text;}

};

/********************************** Couple ****************************/

class Couple{
    Qstring label;
    Note& n1;
    Note& n2;
public:
    Couple(const Qstring& l="", const Note& id1,const Note& id2): label(l), n1(id1), n2(id2){}
};


/********************************** Relation & co ****************************/

class Relation {
    Qstring title;
    Qstring description;
    Couple** listCouples;
    unsigned int nbCouples;
    unsigned int nbMaxCouples;
    bool oriented;
public:
    Relation(const string& t, const Qstring& d, bool o, unsigned int nb): title(t), description(d), listCouples(new Couple**[10]), oriented(o), nbCouples(nb),nbMaxCouples(10){}
    const string& getTitle() {return title;}
    const string& getDescription() {return description;}

    //pour accéder/parcourir les couples d'une relation faire un iterator ?

    bool getOrientation() {return oriented;}

    //addCouple : aggrégation de Couples
    Relation& operator<<(Couple& c);

    //getArborescence()
};

class RelationsManager{
    //singleton
    //we use a vector of Relation
    //Relation are sorted by Title
    std::vector<Relation*>* relations;

    RelationsManager(): relations(nullptr){}
    ~RelationsManager(){}
public:
    static RelationsManager& getInstance(){
        static RelationsManager instance;
        return instance;
    }

    Relation& addRelation();
    Relation& getRelation(const string& t);
/*
    deleteRelation
    getRelation (appelle listCouples)
    listRelations (voir toutes les relations)
*/
};



#endif // PLURINOTES_H


#ifndef PLURINOTES_H
#define PLURINOTES_H
#include <iostream>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <vector>
#include "date.h"

class Exception{
    QString info;
public:
    Exception(const QString& str): info(str){}
    const QString & getInfo() const{return info;}
};

/********************************** Note & co ****************************/
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

class Note{
    friend class NotesManager;
    unsigned int idNote;
    Date dateCrea;
    std::vector<NoteVersion*> listVersion;


    //the constructor is private because only NotesManager can use it
    //used by addNote in NotesManager
    Note(unsigned int id): idNote(id), dateCrea(), listVersion(){
        dateCrea.today();
    }
    //only NotesManager can delete a Note or duplicate a Note
    const Note& operator =(const Note&);
    Note(const Note&);
    ~Note();
public:
    unsigned int getIdNote() const{return idNote;}
    const Date& getDateCrea() const {return dateCrea;}

    /*
     changeState
     getLatestVersion
     */
};

class NotesManager{
    //singleton
    //we use a vector of Notes
    //notes are sorted by idNote
    //composition between NotesManager and Note
    std::vector<Note*> listNotes;
    
    const NotesManager& operator =(const NotesManager&);
    NotesManager(const NotesManager&);
    NotesManager(): listNotes(){}
    ~NotesManager();
    
public:
    static NotesManager& getInstance(){
        static NotesManager instance;
        return instance;
    }
    //addNote adds a note with a new id which is greatest id(=id of latest note) + 1, the new note is empty
    Note& addNote();
    Note& getNote(unsigned int id) const;
    void deleteNote(unsigned int id);
    
    /*
     modifyNote (va appeler addNoteVersion ou copyVersion)
     listNotes (voir toutes les notes active?) avec un iterator??
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






/********************************** Couple ****************************/

class Couple{

    QString label;
    Note& n1;
    Note& n2;
public:
    Couple(Note& id1, Note& id2, const QString& l=""): label(l), n1(id1), n2(id2){}
};


/********************************** Relation & co ****************************/

class Relation {

    QString title;
    QString description;
    Couple** listCouples;
    bool oriented;
    unsigned int nbCouples;
    unsigned int nbMaxCouples;

public:

    Relation(const QString& t, const QString& d, bool o, unsigned int nb): title(t), description(d), listCouples(new Couple*[10]), oriented(o), nbCouples(nb),nbMaxCouples(10){}
    const QString& getTitle() {return title;}
    const QString& getDescription() {return description;}


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
    std::vector<Relation*>* listRelations;

    const RelationsManager& operator =(const RelationsManager&);
    RelationsManager(const RelationsManager&);

    RelationsManager(): listRelations(nullptr){}
    ~RelationsManager(){
        //composition: we delete every objects pointed by the vector
                for(std::vector<Relation*>::iterator it=listRelations->begin(); it!=listRelations->end(); ++it)
                    delete *it;
                delete listRelations;
    }

public:
    static RelationsManager& getInstance(){
        static RelationsManager instance;
        return instance;
    }

    Relation& addRelation();
    Relation& getRelation(const QString& t) const;
/*
    deleteRelation
    getRelation (appelle listCouples)
    listRelations (voir toutes les relations)
*/
};



#endif // PLURINOTES_H

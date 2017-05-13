
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

class Date {
    public:
        //! Constructeur ‡ partir d'un jour, mois, annÈe
        /*! \param j jour avec 1<=j<=31
            \param m mois avec 1<=m<=12
            \param a annÈe avec a>=0
            */
        Date(unsigned int short j=1, unsigned int short m=1, unsigned int a=0):jour(1),mois(1),annee(0){ setDate(j,m,a); }
        // mÈthodes
        unsigned short int  getJour() const { return jour; } //<! Retourne le jour de la date
        unsigned short int  getMois() const { return mois; } //<! Retourne le mois de la date
        unsigned int getAnnee() const { return annee; } //<! Retourne l'annÈe de la date
        void setDate(unsigned short int j, unsigned short int m, unsigned int a); //!< initialisation de la date
        void afficher(std::ostream& f=std::cout) const; //!< affiche le date sous le format JJ/MM/AAAA
        bool operator==(const Date& d) const; //<! d1==d2 retourne vrai si les deux dates sont Ègales
        bool operator<(const Date& d) const; //<! Compare deux dates dans le temps : d1<d2 retourne true si d1 est avant d2
        int operator-(const Date& d) const; //<! Retourne le nombre de jours sÈparant les deux dates
        Date demain() const; //<! Retourne la date du lendemain
        Date operator+(unsigned int nb) const; //<!Retourne la date de dans nb jours
    private:
        // attributs
        unsigned short int jour; // jour entre 1 et 31
        unsigned short int mois; // mois entre 1 et 12
        unsigned int annee;
    };

/********************************** Note & co ****************************/
class NoteVersion{
    int idNote;
    QString title;
    Date dateCrea;
    Date dateEdit;
    int idVersion;

public :
    const QString& getTitle() const {return title;}
    NoteVersion( const int& n, const int& v, const QString& t, const Date& de, const Date& dc): idNote(n), idVersion(v), title(t), dateEdit(de),dateCrea(dc){}
    NoteVersion(NoteVersion &){}

/*
 addNoteVersion :
    copyLatest : copie de la dernière version
    ajout dans la liste des versions de copyLatest
    Incremente latestVersion
 changeVersion : restaurer une ancienne version en tant que version actuelle (design pattern : memento?)

*/

};

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
    //composition between NotesManager and Note
    std::vector<Note*>* listNotes;

    const NotesManager& operator =(const NotesManager&);
    NotesManager(const NotesManager&) const;
    NotesManager(): listNotes(nullptr){}

public:
    ~NotesManager(){//composition: we delete every objects pointed by the vector
        for(std::vector<Note*>::iterator it=listNotes->begin(); it!=listNotes->end(); ++it)
            delete *it;
        delete listNotes;
    }

    static NotesManager& getInstance(){
        static NotesManager instance;
        return instance;
    }
    //addNote adds a note with a new id which is greatest id(=id of latest note) + 1, the new note is empty
    Note& addNote();
    Note& getNote(unsigned int id) const;
/*
    modifyNote (va appeler addNoteVersion ou copyVersion)
    deleteNote
    getNote (appelle getLatestVersion)
    listNotes (voir toutes les notes active?)
*/
};



/*class NoteVersion{
    int idNote;
    QString title;
    Date dateCrea;
    Date dateEdit;
    int idVersion;
    
public :
    const QString& getTitle() const {return title;}
    NoteVersion( const int& n, const int& v, const QString& t, const date& de, const date& dc): idNote(n), idVersion(v), title(t), dateEdit(de),dateCrea(dc){}
    NoteVersion(NoteVersion &)
*/
/*
 addNoteVersion :
    copyLatest : copie de la dernière version
    ajout dans la liste des versions de copyLatest
    Incremente latestVersion
 changeVersion : restaurer une ancienne version en tant que version actuelle (design pattern : memento?)



/********************************** Article ****************************/

class Article : public NoteVersion {
    QString text;
    
    
public :

    Article (const int& n, const int& v, const QString& t, const Date& de, const Date& dc, const QString& te): NoteVersion(n, v, t, de, dc), text(te){}
    
    const QString& getText() const {return text;}


};
    

/********************************** Task ****************************/
    
class Task : public NoteVersion {
    QString action;
    int priority;
    date deadline;
    enum status {waiting, ended, in_progress};
        
        
public :
        
    Task (const int& n, const int& v, const QString& t, const Date& de, const Date& dc, const QString& a, const int p, const date d, const enum s): NoteVersion(n, v, t, de, dc), action(a), priority(p), deadline(d), status(s){}
        
    const QString& getAction() const {return action;}
    const int& getPriority() const {return priority;}
    const date& getDeadline() const {return deadline;}
    const enum& getStatus() const {return status;}
        
        
};
    
    
/********************************** Image ****************************/
    
class Image : public NoteVersion {
    QString description;
    QString file;
        
        
public :
        
    Article (const int& n, const int& v, const QString& t, const Date& de, const Date& dc, const QString& d, const QString& f): NoteVersion(n, v, t, de, dc), description(d), fichier(f){}
        
    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file};
        
        
};
    
    
/********************************** Image ****************************/
    
class Audio : public NoteVersion {
    QString description;
    QString file;
        
        
public :
        
    Audio (const int& n, const int& v, const QString& t, const Date& de, const Date& dc, const QString& d, const QString& f): NoteVersion(n, v, t, de, dc), description(d), fichier(f){}
        
    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file};
        
        
};
    

/********************************** Image ****************************/
    
class video : public NoteVersion {
    QString description;
    QString file;
        
        
public :
        
    video (const int& n, const int& v, const QString& t, const Date& de, const Date& dc, const QString& d, const QString& f): NoteVersion(n, v, t, de, dc), description(d), fichier(f){}
        
    const QString& getDescription() const {return description;}
    const QString& getFile() const {return file};
        
        
};






/********************************** Couple ****************************/

class Couple{

    QString label;
    Note& n1;
    Note& n2;
public:
    Couple(const Note& id1,const Note& id2, const QString& l=""): label(l), n1(id1), n2(id2){}

};


/********************************** Relation & co ****************************/

class Relation {

    QString title;
    QString description;
    Couple** listCouples;
    unsigned int nbCouples;
    unsigned int nbMaxCouples;
    bool oriented;
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
    RelationsManager(const RelationsManager&) const;

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

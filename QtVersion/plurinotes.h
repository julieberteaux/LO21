
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

class Note{
    unsigned int idNote;
    Date dateCrea;
    std::vector<NoteVersion*>* listVersion;
    NoteVersion* latestVersion;

public:
    Note(const int& id): idNote(id){}//used by addNote in NotesManager
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

/********************************** Article ****************************/

class Article : public NoteVersion {
    QString text;
    
    
public :
    Article (const int& n, const int& v, const string& t, const date& de, const date& dc, const string& te): NoteVersion(n, v, t, de, dc), text(te){}
    
    const string& getText() const {return text;}

};

/********************************** Couple ****************************/

class Couple{
    string label;
    Note& n1;
    Note& n2;
public:
    Couple(const string& l="", const Note& id1,const Note& id2): label(l), n1(id1), n2(id2){}
};


/********************************** Relation & co ****************************/

class Relation {
    string title;
    string description;
    Couple** listCouples;
    unsigned int nbCouples;
    unsigned int nbMaxCouples;
    bool oriented;
public:
    Relation(const string& t, const string& d, bool o, unsigned int nb): title(t), description(d), listCouples(new Couple**[10]), oriented(o), nbCouples(nb),nbMaxCouples(10){}
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

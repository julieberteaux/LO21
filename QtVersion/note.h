/**
 * \file	note.h
 * \brief	Définition de la classe Note
 * \details La classe note est une amie de la classe NotesManager, on y définit les différents attributs et méthodes qui caractérise une notes en général.
 */

#ifndef NOTE_H
#define NOTE_H


#include "noteversion.h"

#include <QXmlStreamWriter>

/**
* \brief		Création du type state
* \details  Nous avons créer une enumération state afin de définir l'état d'une note, 1 -> la note est active, 0 -> la note est supprimée par l'utilisateur mais comme elle est en relation avec une autre elle est dans un état archivée, -1 -> la note est dans la corbeille en attendant d'être supprimée définitivement lorsque la corbeille sera vidée.
*/
enum state { active=1, archived=0, trashed=-1 };

/**
* \class Note note.h
*/
class Note{
    friend class NotesManager;
    friend class Trash;
    unsigned int idNote;
    Date dateCrea;
    state noteState;
    std::vector<NoteVersion*> listVersion;

    /**
    * \brief		Constructeur privé car seul NotesManager peut l'utiliser
    * \details  Il est utilisé par addNote dans NotesManager
    * \param    id  Id d'une note il est unique
    */

    Note(unsigned int id=0): idNote(id), dateCrea(), noteState(active), listVersion(){dateCrea.today();}
    //Note(unsigned int id, Date date): idNote(id), dateCrea(date), noteState(active), listVersion(){}

    /**
    * \brief		Constructeur d'affectation
    * \details  Il est privé car seul NotesManager peut l'utiliser
    * \param    Note&  Référence sur la note à affecter
    */
    const Note& operator =(const Note&);

    /**
    * \brief		Constructeur de recopie
    * \details  Il est privé car seul NotesManager peut l'utiliser
    * \param    Note&  Référence sur la note à recopier
    */
    Note(const Note&);

    /**
    * \brief		Destructeur de la classe Notes
    * \details  Il est privé car seul NotesManager peut l'utiliser
    */
    ~Note();

    /**
    * \brief		Méthode pour sauvegarder une note
    * \details  Elle permet de sauvegarder les notes dans un fichier xml lors d'un enregistrement
    * \param    stream  Fichier QXmlStreamWriter qui permet de sauver les notes
    */
    void saveNote(QXmlStreamWriter* stream) const;

    /**
    * \brief		Méthode pour charger une note
    * \details  Elle permet de charger les notes à partir d'un fichier xml
    * \param    &xml  Référence vers le fichier xml d'où on va charger les notes
    */
    void loadNote(QXmlStreamReader &xml);

public:

    /**
    * \brief		Accesseur pour obtenir l'id d'une note
    */
    unsigned int getIdNote() const{return idNote;}

    /**
    * \brief		Accesseur pour obtenir la date d'une note
    */
    const Date& getDateCrea() const {return dateCrea;}

    /**
    * \brief		Accesseur pour obtenir l'état d'une note
    */
    state getNoteState() {return noteState;}

    /**
    * \brief		Méthode pour ajouter une version à une note
    * \param    n   Référence sur une version d'une note
    */
    int addNoteVersion(const NoteVersion& n);

    /**
    * \brief    Méthode pour avoir l'id de la dernière version d'une note
    */
    int copyLatestVersion();

    /**
    * \brief    Méthode pour avoir la version d'une note à partir de son id
    * \param    id  Id de la version de la note
    */
    NoteVersion& getNoteVersion(unsigned int id) const;

    /**
    * \brief    Méthode pour avoir la liste des versions d'une note
    */
    std::vector<NoteVersion*> getListVersions() const{return listVersion;}

    /**
    * \brief    Méthode pour avoir la version actuelle d'une note
    */
    NoteVersion& getLatestNoteVersion(){return *(listVersion.back());}

};


/********************************** Exception ****************************/

/**
* \class Exception note.h
*/
class Exception{
    QString info;
public:
    Exception(const QString& str): info(str){}
    const QString & getInfo() const{return info;}
};


#endif // NOTE_H

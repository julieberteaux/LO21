/**
 * \file	notesmanager.h
 * \brief	Définition de la classe NotesManager
 * \details La classe NotesManager, on y définit les différents attributs et méthodes qui caractérise la gestion des notes au sein de l'application pluriNotes.
 * \details La relation entre les classes NotesManager et Note est une composition
 */

#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H

#include "note.h"
#include "trash.h"
//fusion


/**
* \class Note note.h
* \details La classe NotesManager est un singleton car il ne peut exister qu'une seule instance.
*/
class NotesManager{


    /**
    * \brief Pour stocker les différentes notes nous utilisons un vecteur de Notes.
    * \details Les notes sont triées au sein du vecteur par leur id
    */
    std::vector<Note*> listNotes;

    mutable QString filename;

    /**
    * \brief		Constructeur d'affectation
    * \details  Il est privé car c'est un singleton donc pas d'affectation possible
    * \param    NoteManager&  Référence sur l'instance de NotesManager à affecter
    */
    const NotesManager& operator =(const NotesManager&);

    /**
    * \brief		Constructeur de recopie
    * \details  Il est privé car c'est un singleton donc pas de recopie possible
    * \param    NoteManager&  Référence sur l'instance de NotesManager à recopier
    */
    NotesManager(const NotesManager&);

    /**
    * \brief		Constructeur privé
    * \details  Il est privé car c'est un singleton
    */
    NotesManager(): listNotes(), filename(""){}

    /**
    * \brief		Destructeur privé
    * \details  Il est privé car c'est un singleton
    */
    ~NotesManager();

public:

    /**
    * \brief		Constructeur de l'unique instance du singleton
    * \details  c'est une méthode statique
    */
    static NotesManager& getInstance(){
        static NotesManager instance;
        return instance;
    }

    /**
    * \brief		Défini le nom de l'instance NotesManager
    * \param    std   Nom de l'instance
    */
    void setFilename(const QString& str){filename=str;}

    /**
    * \brief		Ajoute une Note
    * \details  La nouvelle note possède un nouvel identifiant qui est celui de la dernière note + 1. La nouvelle note est vide à sa création
    */
    int addNote();

    /**
    * \brief  Ajoute une note déjà existante
    * \param  n   Pointeur sur la note à ajouter
    */
    void addExistingNote (Note* n);

    /**
    * \brief	Obtenir une note à partir de son id
    * \param  id    Id de la note que l'on souhaite obtenir
    */
    Note &getNote(unsigned int id);

    /**
    * \brief  Obtenir la list de toutes les notes
    * \details  Cette méthode retourne la liste de toutes les notes stockées dans le vecteur
    */
    const std::vector<Note*>& getListNotes() const{return listNotes;}

    /**
    * \brief  Mettre une note à la corbeille
    * \details  Cette méthode permet de mettre une note qui est supprimée à la corbeille. Si nous avons le temps cette méthode verifiera que la note en question n'est pas dans un couple de la relation référence. Le cas échéant elle serait alors archivée et non mise à la corbeille tant qu'elle est dans ce couple. Si la deuxième note qui forme le couple avec la première venait elle aussi à être supprimée elle serait alors toutes les deux mises à la corbeille.
    * \param  id    Id de la note que l'on souhaite mettre à la corbeille
    */
    void putToTrash(unsigned int id);

    /**
    * \brief  Sauvegarder la liste de Notes
    * \details  Cette méthode sauvegarde le vecteur de notes dans un fichier xml à la fermeture de l'application
    */
    void save() const;

    /**
    * \brief  Charger la liste de Notes
    * \details  Cette méthode charge le vecteur de notes à partir d'un fichier xml à l'ouverture de l'application
    */
    void load();

    /*
     modifyNote (va appeler addNoteVersion ou copyVersion)
     listNotes (voir toutes les notes active?) à faire avec l'interface
     void deleteNote(Note* n);
     */
};


#endif // NOTESMANAGER_H

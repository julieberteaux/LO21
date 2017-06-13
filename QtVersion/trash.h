/**
 * \file	trash.h
 * \brief	Définition de la classe Trash
 * \details La classe Trash permet de gérer la corbeille des notes.
 */

#ifndef TRASH_H
#define TRASH_H

#include "notesmanager.h"

/**
* \class Trash trash.h
* \details La classe Trash est un singleton car il ne peut exister qu'une seule instance.
*/
class Trash
{

  /**
  * \brief Pour stocker les différentes notes nous utilisons un vecteur de Notes.
  * \details Les notes sont triées au sein du vecteur par leur id
  */
    std::vector<Note*> listTrashedNotes;

    /**
    * \brief		Constructeur privé
    * \details  Il est privé car c'est un singleton
    */
    Trash();

    /**
    * \brief		Constructeur de recopie
    * \details  Il est privé car c'est un singleton donc pas de recopie possible
    * \param    Trash&  Référence sur l'instance de Trash à recopier
    */
    Trash(const Trash& c);

    /**
    * \brief		Constructeur d'affectation
    * \details  Il est privé car c'est un singleton donc pas d'affectation possible
    * \param    Trash&  Référence sur l'instance de Trash à affecter
    */
    Trash& operator=(const Trash& c);

    static Trash* instance;

    /**
    * \brief		Destructeur privé
    * \details  Il est privé car c'est un singleton
    */
    ~Trash(){}
//    Note* getNoteId(int id);
public:

    /**
     * \brief		Fonction qui cree une instance de Trash s'il n'en existe pas une (Trash est une classe singleton)
     */
        static Trash& getInstance();

      /**
     * \brief		Fonction qui supprime une instance de Trash s'il en existe une.
     */
        static void deleteInstance(){if(instance) delete instance;}

        const std::vector<Note*>& getListTrashedNotes() const{return listTrashedNotes;}

        /**
     * \brief		Fonction qui vide Trash
     */
        void emptyTrash(){listTrashedNotes.clear();}



        /**
     * \brief		Fonction qui supprime une note de la Trash
    * \param		n		note a retirer de la Trash
     */
        void addNote(Note*n);

        /**
     * \brief		Fonction qui remet la note dans les notes actives (dans le tableau de notes de NotesManager)
    * \param		n		note a restaurer
     */
        void putBackNote(unsigned int id);

        void deleteNote(unsigned int id);

};

#endif // TRASH_H

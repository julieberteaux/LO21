#ifndef TRASH_H
#define TRASH_H


class Trash
{
    std::vector<Note*> listTrashedNotes;
    Trash();
    Trash(const Trash& c);
    Trash& operator=(const Trash& c);
    static Trash* instance;
    ~Trash(){}
    Note* getNoteId(int id);
public:
    Trash();
    /**
     * \brief		Fonction qui cree une instance de Trash s'il n'en existe pas une (Trash est une classe singleton)
     */
        static Trash& getInstance();

        /**
     * \brief		Fonction qui supprime une instance de Trash s'il en existe une.
     */
        static void deleteInstance(){if(instance) delete instance;}

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
        void putBackNote(Note* n);

};

#endif // TRASH_H



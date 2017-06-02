#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H

#include "note.h"
//fusion
class NotesManager{
    //singleton
    //we use a vector of Notes
    //notes are sorted by idNote
    //composition between NotesManager and Note
    std::vector<Note*> listNotes;
    mutable QString filename;

    const NotesManager& operator =(const NotesManager&);
    NotesManager(const NotesManager&);
    NotesManager(): listNotes(), filename(""){}
    ~NotesManager();

public:
    static NotesManager& getInstance(){
        static NotesManager instance;
        return instance;
    }
    void setFilename(const QString& str){filename=str;}
    //addNote adds a note with a new id which is greatest id(=id of latest note) + 1, the new note is empty
    int addNote();
    Note& getNote(unsigned int id) const;
    const std::vector<Note*>& getListNotes() const{return listNotes;}

    void deleteNote(unsigned int id);
    void save() const;
    void load();
    /*
     modifyNote (va appeler addNoteVersion ou copyVersion)
     listNotes (voir toutes les notes active?) à faire avec l'interface
     */
};


#endif // NOTESMANAGER_H

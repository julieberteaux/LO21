#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H

#include "note.h"

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


#endif // NOTESMANAGER_H

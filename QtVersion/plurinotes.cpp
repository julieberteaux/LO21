#include "plurinotes.h"

Note& NotesManager::addNote(){
    if(notes.size()==0){
        notes.push_back(new Note(0));
    }else {
        notes.push_back(new Note((*(notes.end()))->getidNote()+1));
    }
    return **(notes.end());
}

#include "notesmanager.h"


NotesManager::~NotesManager(){//composition: we delete every objects pointed by the vector
    for(std::vector<Note*>::iterator it=listNotes.begin(); it!=listNotes.end(); ++it)
        delete *it;
}

Note& NotesManager::addNote(){
    if(listNotes.size()==0){
        Note* n=new Note(0);
        listNotes.push_back(n);
    }else {
        listNotes.push_back(new Note((listNotes.back())->getIdNote()+1));
    }
    return *(listNotes.back());
}

Note& NotesManager::getNote(unsigned int id) const{
    if(listNotes.size()==0)
        throw Exception("Il n'y a pas de notes!");
    auto it = find_if(listNotes.begin(), listNotes.end(), [&id](Note* obj) {return obj->getIdNote() == id;});
    if(it==listNotes.end())
        throw Exception("Il n'y a pas de note correspondant à l'id");
    return **it;
}
void NotesManager::deleteNote(unsigned int id){
    if(listNotes.size()==0)
        throw Exception("Il n'y a pas de notes!");
    auto it = find_if(listNotes.begin(), listNotes.end(), [&id](Note* obj) {return obj->getIdNote() == id;});
    if(it==listNotes.end())
        throw Exception("Il n'y a pas de note correspondant à l'id");
    delete *it;
    listNotes.erase(it);
}

#include "trash.h"



Trash* Trash::instance = 0;
Trash::Trash(){}

Trash& Trash::getInstance(){if (!instance) instance= new Trash(); return *instance;}

//Note* Trash::getNoteId(int id)
//{
//    if(listTrashedNotes.size()==0)
//        throw Exception("Il n'y a pas de notes!");
//    auto it = find_if(listTrashedNotes.begin(), listTrashedNotes.end(), [&id](Note* obj) {return obj->getIdNote() == id;});
//    if(it==listTrashedNotes.end())
//        throw Exception("Il n'y a pas de note correspondant à l'id");
//    return **it;
//}



void Trash::addNote(Note* n)
{
    listTrashedNotes.push_back(n);
}

void Trash::putBackNote(unsigned int id)

{
    if(listTrashedNotes.size()==0)
        throw Exception("Il n'y a pas de notes!");
    auto it = find_if(listTrashedNotes.begin(), listTrashedNotes.end(), [&id](Note* obj) {return obj->getIdNote() == id;});
    if(it==listTrashedNotes.end())
        throw Exception("Cette note n'est pas présente dans la Corbeille");
    //la remttre au bon endroit : respecter l'ordre croissant
    NotesManager::getInstance().addExistingNote(*it);
    listTrashedNotes.erase(it);

}

//ne supprime pas vraiment ..
void Trash::deleteNote(unsigned int id){
    if(listTrashedNotes.size()==0)
        throw Exception("Il n'y a pas de notes!");
    auto it = find_if(listTrashedNotes.begin(), listTrashedNotes.end(), [&id](Note* obj) {return obj->getIdNote() == id;});
    if(it==listTrashedNotes.end())
        throw Exception("Cette note n'est pas présente dans la Corbeille");

    listTrashedNotes.erase(it);
    delete *it;
}










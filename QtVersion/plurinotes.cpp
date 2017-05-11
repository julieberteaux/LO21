#include "plurinotes.h"
/********************************** NotesManager ****************************/

Note& NotesManager::addNote(){
    if(notes.size()==0){
        notes.push_back(new Note(0));
    }else {
        notes.push_back(new Note((notes.back())->getidNote()+1));
    }
    return *(notes.back());
}

Note& NotesManager::getNote(unsigned int id){
    if(notes.size()==0)
        throw Exception("Il n'y a pas de notes!");
    auto it = find_if(notes.begin(), notes.end(), [&id](Note* obj) {return obj->getidNote() == id;});
    if(it==notes.end())
        throw Exception("Il n'y a pas de note correspondant à l'id");
    return **it;
}

/********************************** Note ****************************/

~Note::Note(){
    for(int unsigned i=0;i<vect.size();i++){
        delete listVersion[i];
    }
    delete[] listversion;
}

/********************************** Relation ****************************/

Relation& Relation::operator<<(Couple& c){
    if (nbCouples==nbMaxCouples)
        //faire l'agrandissement sauf si on utilise une autre structure que le tableau
    listCouples[nbCouples++]= &c;
}

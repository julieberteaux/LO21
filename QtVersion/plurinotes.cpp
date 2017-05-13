#include "plurinotes.h"
/********************************** NotesManager ****************************/
NotesManager::~NotesManager(){//composition: we delete every objects pointed by the vector
    if(listNotes!=nullptr){
        for(std::vector<Note*>::iterator it=listNotes->begin(); it!=listNotes->end(); ++it)
            delete *it;
        delete listNotes;
    }
    std::cout<<"destruction de l'objet NotesManager"<<std::endl;
}

Note& NotesManager::addNote(){
    if(listNotes==nullptr){
        listNotes=new std::vector<Note*>;
    }
    if(listNotes->size()==0){
        Note* n=new Note(0);
        listNotes->push_back(n);
    }/*else {
        listNotes->push_back(new Note((listNotes->back())->getidNote()+1));
    }
    return *(listNotes->back());*/
}

Note& NotesManager::getNote(unsigned int id) const{
    if((listNotes==nullptr) || (listNotes->size()==0))
        throw Exception("Il n'y a pas de notes!");
    auto it = find_if(listNotes->begin(), listNotes->end(), [&id](Note* obj) {return obj->getidNote() == id;});
    if(it==listNotes->end())
        throw Exception("Il n'y a pas de note correspondant à l'id");
    return **it;
}

/********************************** Note ****************************/

Note::~Note(){
    for(std::vector<NoteVersion*>::iterator it=listVersion->begin(); it!=listVersion->end(); ++it)
        delete *it;
    delete[] listVersion;
}

/********************************** Relation ****************************/

Relation& Relation::operator<<(Couple& c){
    if (nbCouples==nbMaxCouples)
        //faire l'agrandissement sauf si on utilise une autre structure que le tableau
    listCouples[nbCouples++]= &c;
}

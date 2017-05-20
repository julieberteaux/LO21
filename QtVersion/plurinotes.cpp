#include "plurinotes.h"
/********************************** NotesManager ****************************/
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

/********************************** Note ****************************/

Note::~Note(){
    for(std::vector<NoteVersion*>::iterator it=listVersion.begin(); it!=listVersion.end(); ++it)
        delete *it;
    //std::cout<<"suppression de la note d'id"<<idNote<<std::endl;
}

/********************************** NotesVersion ****************************/

//void addNoteVersion(unsigned int id){
//    Note& n = getNote(id);
//    NotesVersion& latestVersion = n.listVersion.back();
//    NotesVersion newVersion = latestVersion;
//    newVersion.dateEdit.today();
//    newVersion.idVersion++;
//    //cout<<
//    n.listVersion.push_back(newVersion);
    
    
//}

/********************************** Relation ****************************/

void Relation::addCouple(Couple& c){
    listCouples.push_back(&c);
}

/********************************** RelationsManager ****************************/

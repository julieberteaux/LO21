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

NoteVersion& Note::addNoteVersion(const NoteVersion& n){
    if(listVersion.size()==0){
        listVersion.push_back(n.clone(0));
    }else {
        listVersion.push_back(n.clone((listVersion.back())->getIdVersion()+1));
    }
    return *(listVersion.back());
}

/********************************** NotesVersion ****************************/



/********************************** Relation ****************************/

Relation& Relation::operator<<(Couple& c){
    if (nbCouples==nbMaxCouples)
        //faire l'agrandissement sauf si on utilise une autre structure que le tableau
    listCouples[nbCouples++]= &c;
}

/********************************** Article ****************************/

Article* Article::clone(unsigned int id) const{
    Article* art=new Article(*this);
    art->idVersion=id;
    return art;
}
/********************************** Task ****************************/

Task* Task::clone(unsigned int id) const{
    Task* tsk=new Task(*this);
    tsk->idVersion=id;
    return tsk;
}
/********************************** Image ****************************/

Image* Image::clone(unsigned int id) const{
    Image* img=new Image(*this);
    img->idVersion=id;
    return img;
}
/********************************** Audio ****************************/

Audio* Audio::clone(unsigned int id) const{
    Audio* aud=new Audio(*this);
    aud->idVersion=id;
    return aud;
}

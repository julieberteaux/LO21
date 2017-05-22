#include "plurinotes.h"
/********************************** NotesManager ****************************/
NotesManager::~NotesManager(){//composition: we delete every objects pointed by the vector
    for(std::vector<Note*>::iterator it=listNotes.begin(); it!=listNotes.end(); ++it)
        delete *it;
}

int NotesManager::addNote(){
    if(listNotes.size()==0){
        Note* n=new Note(0);
        listNotes.push_back(n);
    }else {
        listNotes.push_back(new Note((listNotes.back())->getIdNote()+1));
    }
    return (listNotes.back())->getIdNote();
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

int Note::addNoteVersion(const NoteVersion& n){
    /*the former version of addNoteVersion (version which is bleow) had the disavantage that we could add several
     NoteVersion of different types (Image, Article...)
    if(listVersion.size()==0){
        listVersion.push_back(n.clone(0));
    }else {
        listVersion.push_back(n.clone((listVersion.back())->getIdVersion()+1));
    }
    return (listVersion.back())->getIdVersion();
    */
    /*The new version below allows to add only one version (artcile, image...) in a note. If we want to add a new version
    we have to use copylatestversion*/
    if(listVersion.size()==0){
        listVersion.push_back(n.clone(0));
    }else {
        throw Exception("La note n'est pas vide...");
    }
    return (listVersion.back())->getIdVersion();
}

int Note::copyLatestVersion(){
    if(listVersion.size()==0){
        throw Exception("La note est vide...");
    }else {
        NoteVersion* copyLatestVersion=listVersion.back()->clone(listVersion.back()->getIdVersion()+1);
        listVersion.push_back(copyLatestVersion);
    }
    return (listVersion.back())->getIdVersion();
}

NoteVersion& Note::getNoteVersion(unsigned int id) const{
    if(listVersion.size()==0)
        throw Exception("Il n'y a pas de verion pour cette note!");
    auto it = find_if(listVersion.begin(), listVersion.end(), [&id](NoteVersion* obj) {return obj->getIdVersion() == id;});
    if(it==listVersion.end())
        throw Exception("Il n'y a pas de version correspondant à l'id");
    return **it;
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

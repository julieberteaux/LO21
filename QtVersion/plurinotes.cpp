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



// QUESTION :??? [&t](Relation* obj) {return obj->getTitle() == t;}  ??????
// est ce qu'on peut comparer 2 string avec ==

const Relation* RelationsManager::getRelation(const QString& t) const{
    if(listRelations.size()==0)
        return nullptr;
    auto it = find_if(listRelations.begin(), listRelations.end(), [&t](Relation* obj) {return obj->getTitle() == t;});
    if(it==listRelations.end())
        return nullptr;
    return *it;

}

//PROBLEME
void RelationsManager::addRelation(const QString& t, const QString& d, bool o){


    const Relation* r = getRelation(t);
    if (r==nullptr)
    {
        listRelations.push_back(new Relation(t, d, o));

    }
    else
    {
        throw Exception("Cette relation existe deja");
    }


}



void RelationsManager::displayRelationCouples (const QString& t, std::ostream& f) {
    const Relation* r = getRelation(t);

    //parcourir r.listCouples et tous les afficher
}

// QUESTION :??? [&t](Relation* obj) {return obj->getTitle() == t;}  ??????
// est ce qu'on peut comparer 2 string avec ==
void RelationsManager::deleteRelation(const QString& t){
    if(listRelations.size()==0)
        throw Exception("Il n'y a pas de Relation!");
    auto it = find_if(listRelations.begin(), listRelations.end(), [&t](Relation* obj) {return obj->getTitle() == t;});
    if(it==listRelations.end())
        throw Exception("Il n'y a pas de Relation correspondant à ce titre");
    delete *it;
    listRelations.erase(it);
}

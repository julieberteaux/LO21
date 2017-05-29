#include "trash.h"



//Trash* Trash::instance = 0;
//Trash::Trash(){}

//Trash& Trash::getInstance(){if (!instance) instance= new Trash(); return *instance;}

//Note* Trash::getNoteId(int id)
//{
//    if(listTrashedNotes.size()==0)
//        throw Exception("Il n'y a pas de notes!");
//    auto it = find_if(listTrashedNotes.begin(), listTrashedNotes.end(), [&id](Note* obj) {return obj->getIdNote() == id;});
//    if(it==listTrashedNotes.end())
//        throw Exception("Il n'y a pas de note correspondant à l'id");
//    return **it;
//}



//void Trash::addNote(Note* n)
//{
//    listTrashedNotes.push_back(n);
//}

//void Trash::putBackNote(Note* n)

//{
//    //la remttre au bon endroit : respecter l'ordre croissant
//    int j=getPosNote(n);
//    NotesManager::getInstance().addNote(n);
//     for (unsigned int i=0;i<n->getSizeTabTags();i++)
//            {
//                QString name = n->getTag(i)->getName();
//                TagManager::getInstance().addAssociatedTag(name,n);
//            }
//            dust.removeAt(j);

//}


//int Trash::getPosNote(Note*n)
//{
//    for( int i=0;i<dust.size();i++)
//        if(dust[i]==n) return i;
//    throw("la note n'existe pas");
//}







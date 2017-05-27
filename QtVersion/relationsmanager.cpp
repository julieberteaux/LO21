#include "relationsmanager.h"


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

#ifndef RELATIONMANAGER_H
#define RELATIONMANAGER_H



#include "relation.h"


class RelationsManager{
    //singleton
    //we use a vector of Relation
    //Relation are sorted by Title
    std::vector<Relation*> listRelations;

    const RelationsManager& operator =(const RelationsManager&);
    RelationsManager(const RelationsManager&);

    RelationsManager(): listRelations(){}
    ~RelationsManager(){
        //composition: we delete every objects pointed by the vector
                for(std::vector<Relation*>::iterator it=listRelations.begin(); it!=listRelations.end(); ++it)
                    delete *it;
                listRelations.clear() ;
    }

public:
    static RelationsManager& getInstance(){
        static RelationsManager instance;
        return instance;
    }

    void addRelation(const QString& t, const QString& d, bool o);
    const Relation* getRelation(const QString& t) const;
    void deleteRelation(const QString& t);
    void displayRelationCouples (const QString& t, std::ostream& f);
/*

    listRelations (voir toutes les relations)
*/
};
#endif // RELATIONMANAGER_H

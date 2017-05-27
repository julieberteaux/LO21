#ifndef RELATION_H
#define RELATION_H

#include "note.h"

class Relation {

    QString title;
    QString description;
    std::vector<Couple*> listCouples;
    bool oriented;


public:

    Relation(const QString& t, const QString& d, bool o= true): title(t), description(d), listCouples(), oriented(o){}
    const QString& getTitle() {return title;}
    const QString& getDescription() {return description;}


    //pour accéder/parcourir les couples d'une relation faire un iterator ?

    bool getOrientation() {return oriented;}

    //addCouple : aggrégation de Couples
    void addCouple(Couple& c);

    //getArborescence()
};
#endif // RELATION_H

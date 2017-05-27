#include "relation.h"

void Relation::addCouple(Couple& c){
    listCouples.push_back(&c);
}

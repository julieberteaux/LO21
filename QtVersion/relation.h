/**
 * \file	relation.h
 * \brief	Définition de la classe Couple et Relation
 * \details La classe Couple définit les caractéristiques d'un couple de notes dans une relation.
 * \details La classe Relation définit les attributs et les méthodes des relations.
 */

#ifndef RELATION_H
#define RELATION_H

#include "note.h"
/********************************** Couple ****************************/

/**
* \class Couple relation.h
*/
class Couple {

    QString label;
    Note& n1;
    Note& n2;
public:

    /**
    * \brief		Constructeur de la classe Couple
    * \param    id1   id de la première note du couple
    * \param    id2   id de la deuxième note du couple
    * \param    l     label du couple
    */
    Couple(Note& id1, Note& id2, const QString& l=""): label(l), n1(id1), n2(id2){}

    /**
    * \brief		accesseur pour obtenir une référence sur la première note du couple
    */
    const Note& getNote1() const {return n1;}

    /**
    * \brief		accesseur pour obtenir une référence sur la deuxième note du couple
    */
    const Note& getNote2() const {return n2;}
};


/********************************** Relation ****************************/

/**
* \class Relation relation.h
*/
class Relation {

    QString title;
    QString description;
    std::vector<Couple*> listCouples;
    bool oriented;


public:

    /**
    * \brief		Constructeur de la classe Relation
    * \param    t   titre de la relation
    * \param    d   description de la relation
    * \param    o   orientation de la relation (booléen)
    */
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

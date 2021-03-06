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
    * \param    id1   Id de la première note du couple
    * \param    id2   Id de la deuxième note du couple
    * \param    l     Label du couple
    */
    Couple(Note& id1, Note& id2, const QString& l=""): label(l), n1(id1), n2(id2){}

    /**
    * \brief		Accesseur pour obtenir une référence sur la première note du couple
    */
    const Note& getNote1() const {return n1;}

    /**
    * \brief		Accesseur pour obtenir une référence sur la deuxième note du couple
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
    * \param    t   Titre de la relation
    * \param    d   Description de la relation
    * \param    o   Orientation de la relation (booléen)
    */
    Relation(const QString& t=0, const QString& d=0, bool o= true): title(t), description(d), listCouples(), oriented(o){}

    /**
    * \brief		Accesseur pour obtenir le titre de la relation
    */
    const QString& getTitle() const {return title;}
    /**
    * \brief		Permet de modifier le titre de la relation
    */
    void setTitle(const QString& str)  {title=str;}

    /**
    * \brief		Accesseur pour obtenir la description de la relation
    */
    const QString& getDescription() const {return description;}

    /**
    * \brief		Permet de modifier la description de la relation
    */
    void setDescription(const QString& str)  {description=str;}

    /**
    * \brief		Accesseur pour obtenir l'orientation de la relation
    */
    bool getOrientation() const {return oriented;}
    /**
    * \brief		Accesseur pour obtenir l'orientation de la relation
    */
    void setOrientation(bool i) {oriented=i;}

    /**
    * \brief		Méthode pour sauvegarder une relation
    * \details  Elle permet de sauvegarder les relations dans un fichier xml lors d'un enregistrement
    * \param    stream  Fichier QXmlStreamWriter qui permet de sauver les relations
    */
    void saveRelation(QXmlStreamWriter* stream) const;

    /**
    * \brief		Méthode pour charger une note
    * \details  Elle permet de charger les notes à partir d'un fichier xml
    * \param    &xml  Référence vers le fichier xml d'où on va charger les notes
    */
    void loadRelation(QXmlStreamReader &xml);

    /**
    * \brief  Méthode pour ajouter un couple
    * \details  Lors de la construction d'une relation, on initialise un vecteur de couple qui est vide. Avec la méthode addCouple on ajoute un couple c à ce vecteur
    * \param  c   Référence sur le couple à ajouter
    */
    void addCouple(Couple& c);

};
#endif // RELATION_H

/**
 * \file	relationsmanager.h
 * \brief	Définition de la classe RelationsManager
 * \details La classe RelationsManager définit les différents attributs et méthodes qui caractérise la gestion des relations au sein de l'application pluriNotes.
 */

#ifndef RELATIONMANAGER_H
#define RELATIONMANAGER_H



#include "relation.h"

/**
* \class RelationsManager relationsmanager.h
* \details La classe RelationsManager est un singleton car il ne peut exister qu'une seule instance.
*/
class RelationsManager{

    /**
    * \brief Pour stocker les différentes relations nous utilisons un vecteur de relation.
    * \details Les relations sont triées au sein du vecteur par leur titre
    */
    std::vector<Relation*> listRelations;

    mutable QString filename;

    /**
    * \brief		Constructeur d'affectation
    * \details  Il est privé car c'est un singleton donc pas d'affectation possible
    * \param    RelationsManager&  Référence sur l'instance de RelationsManager à affecter
    */
    const RelationsManager& operator =(const RelationsManager&);

    /**
    * \brief		Constructeur de recopie
    * \details  Il est privé car c'est un singleton donc pas de recopie possible
    * \param    RelationsManager&  Référence sur l'instance de RelationsManager à recopier
    */
    RelationsManager(const RelationsManager&);

    /**
    * \brief		Constructeur privé
    * \details  Il est privé car c'est un singleton
    */
    RelationsManager(): listRelations(){}

    /**
    * \brief		Destructeur privé
    * \details  Il est privé car c'est un singleton, c'est une composition donc on supprime tout les objets pointés par le vecteur
    */
    ~RelationsManager(){
                for(std::vector<Relation*>::iterator it=listRelations.begin(); it!=listRelations.end(); ++it)
                    delete *it;
                listRelations.clear() ;
    }

public:

  /**
  * \brief		Constructeur de l'unique instance du singleton
  * \details  c'est une méthode statique
  */
    static RelationsManager& getInstance(){
        static RelationsManager instance;
        return instance;
    }

    /**
    * \brief		Ajoute une Relation
    * \details  La nouvelle relation est vide à sa création, elle ne possède pas de couple.
    * \param  t   Titre de la relation
    * \param  d   Description de la relation
    * \param  o   Orientation de la relation
    */
    void addRelation(const QString& t, const QString& d, bool o);

    /**
    * \brief	Obtenir une relation à partir de son titre
    * \param  t    titre de la relation que l'on souhaite obtenir
    */
    const Relation* getRelation(const QString& t) const;

    /**
    * \brief	Supprimer une relation à partir de son titre
    * \param  t    titre de la relation que l'on souhaite supprimer
    */
    void deleteRelation(const QString& t);

    /**
    * \brief	Afficher les couples d'une relation à partir de son titre
    * \param  t   titre de la relation que l'on souhaite supprimer
    * \param  f   fichier de sortie standard
    */
    void displayRelationCouples (const QString& t, std::ostream& f);


     const std::vector<Relation*>& getListRelations() const{return listRelations;}

    /**
    * \brief  Charger la liste de Relations
    * \details  Cette méthode charge le vecteur de relations à partir d'un fichier xml à l'ouverture de l'application
    */
    void load();

    /**
    * \brief  Sauvegarder la liste de Relations
    * \details  Cette méthode sauvegarde le vecteur de Relations dans un fichier xml à la fermeture de l'application
    */
    void save() const;

};
#endif // RELATIONMANAGER_H

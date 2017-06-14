/**
 * \file	date.h
 * \brief	Définition du type date
 * \details Nous avons définit le type date afin de pouvoir l'utiliser dans nos différentes fonctions de classes plus tard
 */

#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<iomanip>

/**
* \class TimeException date.h
*/
class TimeException{
    public:
        TimeException(const std::string& m):info(m){}
        const std::string& GetInfo() const { return info; }
    private:
        std::string info;
};

/**
* \class Date date.h
*/
class Date {

    private:

      unsigned short int jour;
      unsigned short int mois;
      unsigned int annee;

    public:

      /**
      * \brief		Constructeur à partir d'un jour, mois, année
      * \param		j		jour avec 1<=j<=31
      * \param		m		mois avec 1<=m<=12
      * \param		a		année avec a>=0
      */

        Date(unsigned int short j=1, unsigned int short m=1, unsigned int a=0):jour(1),mois(1),annee(0){ setDate(j,m,a);}

        /**
        * \brief		Retourne le jour de la date
        * \param		1 <= jour <= 31
        */
        unsigned short int  getJour() const { return jour; }

        /**
        * \brief		Retourne le mois de la date
        * \param		1 <= mois <= 12
        */
        unsigned short int  getMois() const { return mois; }

        /**
        * \brief		Retourne l'année de la date
        * \param		annee >=0
        */
        unsigned int getAnnee() const { return annee; }

        /**
        * \brief		initialisation de la date
        * \param		j		jour avec 1<=j<=31
        * \param		m		mois avec 1<=m<=12
        * \param		a		année avec a>=0
        */
        void setDate(unsigned short int j, unsigned short int m, unsigned int a);

        /**
        * \brief		affiche le date sous le format JJ/MM/AAAA
        * \param		f   flux de sortie
        */
        void afficher(std::ostream& f=std::cout) const;

        /**
        * \brief		d1==d2 retourne vrai si les deux dates sont égales
        * \param		d   date
        * \details  on va comparer la date d avec la date appelant la méthode pour voir si elles sont égales
        */
        bool operator==(const Date& d) const;

        /**
        * \brief		Compare deux dates dans le temps
        * \param		d   date
        * \details  d1<d2 retourne true si d1 est avant d2
        */
        bool operator<(const Date& d) const;

        /**
        * \brief		Retourne le nombre de jours séparant les deux dates
        * \param		d   date
        */
        int operator-(const Date& d) const;

        /**
        * \brief		Met à jour la date appelant cette méthode avec la date du jour
        * \details  Donne la date du jour même où la méthodes est appelée
        */
        void today();

        /**
        * \brief		Retourne la date du lendemain
        * \details  Donne la date du lendemain où la méthodes est appelée
        */
        Date demain() const;

        /**
        * \brief		Retourne la date dans nb jours
        * \param		nb  nombre de jours
        * \details  Donne la date actuelle à laquelle on ajoute nb jours. En respectant bien entendu le format d'une date.
        */
        Date operator+(unsigned int nb) const;

};

#endif // DATE_H

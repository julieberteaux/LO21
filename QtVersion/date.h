#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<iomanip>

class TimeException{
    public:
        //! Constructeur ‡ partir d'une string
        TimeException(const std::string& m):info(m){}
        const std::string& GetInfo() const { return info; } //<! Retourne l'information stockÈe dans la classe
    private:
        std::string info;
};

class Date {
    public:
        //! Constructeur ‡ partir d'un jour, mois, annÈe
        /*! \param j jour avec 1<=j<=31
            \param m mois avec 1<=m<=12
            \param a annÈe avec a>=0
            */
        Date(unsigned int short j=1, unsigned int short m=1, unsigned int a=0):jour(1),mois(1),annee(0){ setDate(j,m,a);}
        // mÈthodes
        unsigned short int  getJour() const { return jour; } //<! Retourne le jour de la date
        unsigned short int  getMois() const { return mois; } //<! Retourne le mois de la date
        unsigned int getAnnee() const { return annee; } //<! Retourne l'annÈe de la date
        void setDate(unsigned short int j, unsigned short int m, unsigned int a); //<! initialisation de la date
        void afficher(std::ostream& f=std::cout) const; //<! affiche le date sous le format JJ/MM/AAAA
        bool operator==(const Date& d) const; //<! d1==d2 retourne vrai si les deux dates sont Ègales
        bool operator<(const Date& d) const; //<! Compare deux dates dans le temps : d1<d2 retourne true si d1 est avant d2
        int operator-(const Date& d) const; //<! Retourne le nombre de jours sÈparant les deux dates
        void today(); //Changes the date by putting the date of today
        Date demain() const; //<! Retourne la date du lendemain
        Date operator+(unsigned int nb) const; //<!Retourne la date de dans nb jours
    private:
        // attributs
        unsigned short int jour; // jour entre 1 et 31
        unsigned short int mois; // mois entre 1 et 12
        unsigned int annee;
};

#endif // DATE_H

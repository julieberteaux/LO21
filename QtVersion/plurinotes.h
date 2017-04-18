
#ifndef PLURINOTES_H
#define PLURINOTES_H

#include <QString>

class Exception{
    QString info;
public:
    Exception(const QString& str): info(str){}
    const QString & getInfo() const{return info;}
};

class Date{
    int day;
    int month;
    int year;
public:
    int getDay(){return day;}
    int getMonth(){return month;}
    int getYear(){return year;}
    void setDay(const int & d){
        if ((d>=1) && (d<=31))
            day=d;
        else throw Exception("Wrong day");
    }
    void setMonth(const int & m){
        if ((m>=1) && (m<=12))
            month=m;
        else throw Exception("Wrong month");
    }
    void setYear(const int & y){year=y;}
    Date(int d, int m, int y){
        setDay(d);
        setMonth(m);
        setYear(y);
    }
};

class NotesManager{

};

class NoteVersion{
    int idNote;
    QString title;
    Date dateCrea;
    Date dateEdit;
    int idVersion;
};
#endif // PLURINOTES_H

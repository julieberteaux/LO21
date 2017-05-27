#ifndef NOTE_H
#define NOTE_H


#include "noteversion.h"


class Note{
    friend class NotesManager;
    unsigned int idNote;
    Date dateCrea;
    std::vector<NoteVersion*> listVersion;


    //the constructor is private because only NotesManager can use it
    //used by addNote in NotesManager
    Note(unsigned int id): idNote(id), dateCrea(), listVersion(){
        dateCrea.today();
    }
    //only NotesManager can delete a Note or duplicate a Note
    const Note& operator =(const Note&);
    Note(const Note&);
    ~Note();
    saveNote(QXmlStreamWriter* stream) const;
public:
    unsigned int getIdNote() const{return idNote;}
    const Date& getDateCrea() const {return dateCrea;}
    int addNoteVersion(const NoteVersion &);
    int copyLatestVersion();
    NoteVersion& getNoteVersion(unsigned int id) const;
    /*
     changeState
     getLatestVersion
     */
};


/********************************** Couple ****************************/

class Couple{

    QString label;
    Note& n1;
    Note& n2;
public:
    Couple(Note& id1, Note& id2, const QString& l=""): label(l), n1(id1), n2(id2){}
};


/********************************** Exception ****************************/

class Exception{
    QString info;
public:
    Exception(const QString& str): info(str){}
    const QString & getInfo() const{return info;}
};


#endif // NOTE_H

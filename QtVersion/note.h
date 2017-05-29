#ifndef NOTE_H
#define NOTE_H


#include "noteversion.h"

#include <QXmlStreamWriter>

enum state { active=1, archived=0, trashed=-1 };

class Note{
    friend class NotesManager;
    unsigned int idNote;
    Date dateCrea;
    state noteState;
    std::vector<NoteVersion*> listVersion;


    //the constructor is private because only NotesManager can use it
    //used by addNote in NotesManager
    Note(unsigned int id): idNote(id), dateCrea(), noteState(active), listVersion(){dateCrea.today();}
    Note(unsigned int id, Date date): idNote(id), dateCrea(date), noteState(active), listVersion(){}

    //only NotesManager can delete a Note or duplicate a Note
    const Note& operator =(const Note&);
    Note(const Note&);
    ~Note();
    void saveNote(QXmlStreamWriter* stream) const;
    void loadVersion(QXmlStreamReader &xml);
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


/********************************** Exception ****************************/

class Exception{
    QString info;
public:
    Exception(const QString& str): info(str){}
    const QString & getInfo() const{return info;}
};


#endif // NOTE_H

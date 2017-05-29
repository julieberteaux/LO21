#include "noteversion.h"

//void addNoteVersion(unsigned int id){
//    Note& n = getNote(id);
//    NotesVersion& latestVersion = n.listVersion.back();
//    NotesVersion newVersion = latestVersion;
//    newVersion.dateEdit.today();
//    newVersion.idVersion++;
//    //cout<<
//    n.listVersion.push_back(newVersion);


//}
//template<typename T> NoteVersion * createT() { return new T;}
//NoteVersionFactory::map_type NoteVersionFactory::map = new NoteVersionFactory::map_type();

void NoteVersion::saveNoteVersion(QXmlStreamWriter* stream) const{
    stream->writeStartElement("version");

    stream->writeTextElement("idVersion",QString::number(idVersion));

    stream->writeTextElement("title",title);

    stream->writeStartElement("dateEdit");
    stream->writeTextElement("jour",QString::number(dateEdit.getJour()));
    stream->writeTextElement("mois",QString::number(dateEdit.getMois()));
    stream->writeTextElement("annee",QString::number(dateEdit.getAnnee()));
    stream->writeEndElement();

    saveNoteVersionType(stream);

    stream->writeEndElement();

}

/********************************** Article ****************************/
//DerivedRegister<Article> Article::reg("Article");

Article* Article::clone(unsigned int id) const{
    Article* art=new Article(*this);
    art->idVersion=id;
    return art;
}

void Article::saveNoteVersionType(QXmlStreamWriter* stream) const{
    stream->writeTextElement("texte",text);
}

/********************************** Task ****************************/

Task* Task::clone(unsigned int id) const{
    Task* tsk=new Task(*this);
    tsk->idVersion=id;
    return tsk;
}

void Task::saveNoteVersionType(QXmlStreamWriter* stream) const{
    //A FAIRE
}
/********************************** Image ****************************/

Image* Image::clone(unsigned int id) const{
    Image* img=new Image(*this);
    img->idVersion=id;
    return img;
}

void Image::saveNoteVersionType(QXmlStreamWriter* stream) const{
    stream->writeTextElement("description",description);
    stream->writeTextElement("file",file);

}
/********************************** Audio ****************************/

Audio* Audio::clone(unsigned int id) const{
    Audio* aud=new Audio(*this);
    aud->idVersion=id;
    return aud;
}
void Audio::saveNoteVersionType(QXmlStreamWriter* stream) const{
    //A FAIRE
}

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
//NoteVersionFactory::map_type NoteVersionFactory::map = new NoteVersionFactory::map_type();
NoteVersionFactory::map_type * NoteVersionFactory::map = NULL;

void NoteVersion::saveNoteVersion(QXmlStreamWriter* stream) const{
    stream->writeStartElement("version");

    stream->writeTextElement("idVersion",QString::number(idVersion));

    stream->writeTextElement("title",title);

    stream->writeStartElement("dateEdit");
    stream->writeTextElement("jour",QString::number(dateEdit.getJour()));
    stream->writeTextElement("mois",QString::number(dateEdit.getMois()));
    stream->writeTextElement("annee",QString::number(dateEdit.getAnnee()));
    stream->writeEndElement();

    saveNoteVersionType(*stream);

    stream->writeEndElement();

}

void NoteVersion::loadNoteVersion(QXmlStreamReader& xml){
    unsigned int jour, mois ,annee;
    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "dateEdit")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            // We've found identifieur.
            if(xml.name() == "idVersion") {
                xml.readNext();
                idVersion=xml.text().toInt();
                qDebug()<<"idVersion="<<idVersion<<"\n";
            }

            // We've found title.
            if(xml.name() == "title") {
                xml.readNext();
                title=xml.text().toString();
                qDebug()<<"titre="<<title<<"\n";
            }
            // We've found dateEdit.
            if(xml.name() == "dateEdit") {
                while(!(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "annee")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        if(xml.name() == "jour"){
                            xml.readNext();
                            jour=xml.text().toInt();
                        }
                        if(xml.name() == "mois"){
                            xml.readNext();
                            mois=xml.text().toInt();
                        }
                    }
                    xml.readNext();
                }
                xml.readNext();
                annee=xml.text().toInt();
                dateEdit.setDate(jour,mois,annee);
                qDebug()<<"dateEdit="<<jour<<"-"<<mois<<"-"<<annee<<"\n";

            }
        }
        // ...and next...
        xml.readNext();
        //qDebug()<<xml.name()<<"\n";

    }
    std::cout<<"NoteVersion.cpp"<<std::endl;

    loadNoteVersionType(xml);
}

/********************************** Article ****************************/
DerivedRegister<Article> Article::reg("Article");

Article* Article::clone(unsigned int id) const{
    Article* art=new Article(*this);
    art->idVersion=id;
    return art;
}

void Article::saveNoteVersionType(QXmlStreamWriter& stream) const{
    stream.writeTextElement("text",text);
}

void Article::loadNoteVersionType(QXmlStreamReader &xml){
    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "version")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            // We've found text.
            if(xml.name() == "text") {
                xml.readNext();
                text=xml.text().toString();
                qDebug()<<"text="<<text<<"\n";
            }
        }
        xml.readNext();
    }
    xml.readNext();
}

/********************************** Task ****************************/
DerivedRegister<Task> Task::reg("Task");

Task* Task::clone(unsigned int id) const{
    Task* tsk=new Task(*this);
    tsk->idVersion=id;
    return tsk;
}

void Task::saveNoteVersionType(QXmlStreamWriter& stream) const{
    //A FAIRE
}

void Task::loadNoteVersionType(QXmlStreamReader& stream){

}

/********************************** Image ****************************/
DerivedRegister<Image> Image::reg("Image");

Image* Image::clone(unsigned int id) const{
    Image* img=new Image(*this);
    img->idVersion=id;
    return img;
}

void Image::saveNoteVersionType(QXmlStreamWriter& stream) const{
    stream.writeTextElement("description",description);
    stream.writeTextElement("file",file);

}


void Image::loadNoteVersionType(QXmlStreamReader& xml){
    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "version")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            // We've found text.
            if(xml.name() == "description") {
                xml.readNext();
                description=xml.text().toString();
                qDebug()<<"description="<<description<<"\n";
            }
            if(xml.name() == "file") {
                xml.readNext();
                file=xml.text().toString();
                qDebug()<<"file="<<file<<"\n";
            }
        }
        xml.readNext();
    }
    xml.readNext();
}

/********************************** Audio ****************************/

Audio* Audio::clone(unsigned int id) const{
    Audio* aud=new Audio(*this);
    aud->idVersion=id;
    return aud;
}
void Audio::saveNoteVersionType(QXmlStreamWriter& stream) const{
    //A FAIRE
}

void Audio::loadNoteVersionType(QXmlStreamReader &xml){

}

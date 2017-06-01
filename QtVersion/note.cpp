#include "note.h"



Note::~Note(){
    for(std::vector<NoteVersion*>::iterator it=listVersion.begin(); it!=listVersion.end(); ++it)
        delete *it;
    //std::cout<<"suppression de la note d'id"<<idNote<<std::endl;
}

void Note::saveNote(QXmlStreamWriter* stream) const {
    //we consider that a note has ONE specific type (article, image, ...)
    //a note is saved if it has at least one version...
    if(listVersion.size()!=0){
        stream->writeStartElement("note");
        stream->writeTextElement("idNote",QString::number(idNote));

        stream->writeStartElement("dateCrea");
        stream->writeTextElement("jour",QString::number(dateCrea.getJour()));
        stream->writeTextElement("mois",QString::number(dateCrea.getMois()));
        stream->writeTextElement("annee",QString::number(dateCrea.getAnnee()));
        stream->writeEndElement();

        //A verifier...
        //stream->writeTextElement("noteState",QString::number(noteState));

        stream->writeTextElement("type",(listVersion.back())->type());

        for(std::vector<NoteVersion*>::const_iterator it=listVersion.begin(); it!=listVersion.end(); ++it)
            (**it).saveNoteVersion(stream);

        stream->writeEndElement();
    }
}


void Note::loadNote(QXmlStreamReader& xml){
    /*if(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "idNote")){
        throw Exception("Erreur lors du chargement: la balise n'est pas <type>.");
    }
    //QXmlStreamAttributes attributes = xml.attributes();
    xml.readNext();*/
    //We're going to loop over the things because the order might change.
    //We'll continue the loop until we hit an EndElement named note.
    unsigned int jour, mois, annee;
    while(!(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "type")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            // We've found identificteur.
            if(xml.name() == "idNote") {
                xml.readNext();
                idNote=xml.text().toInt();
                qDebug()<<"idNote:"<<idNote<<"\n";
            }

            // We've found dateCrea.
            if(xml.name() == "dateCrea") {
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
                dateCrea.setDate(jour,mois,annee);
                qDebug()<<"dateCrea="<<jour<<"-"<<mois<<"-"<<annee<<"\n";

            }

            //A vérifier
            /*if(xml.name() == "noteState") {
                xml.readNext();
                noteState=xml.text().toInt();
                qDebug()<<"noteState:"<<noteState<<"\n";
            }*/
        }
        // ...and next...
        xml.readNext();
    }

    xml.readNext();
    QString type=xml.text().toString();

    //We begin with the first version of the note...

    NoteVersion* version=NoteVersionFactory::createInstance(type);
    listVersion.push_back(version);
    qDebug()<<"first version"<<"\n";

    version->loadNoteVersion(xml);

    //... then we do the others versions
    int idVersion1;
    NoteVersion* noteversion;
    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "note")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "version"){
            idVersion1=copyLatestVersion();
            noteversion=&getNoteVersion(idVersion1);
            noteversion->loadNoteVersion(xml);
        }
        xml.readNext();
    }

}

int Note::addNoteVersion(const NoteVersion& n){
    /*the former version of addNoteVersion (version which is bleow) had the disavantage that we could add several
     NoteVersion of different types (Image, Article...)
    if(listVersion.size()==0){
        listVersion.push_back(n.clone(0));
    }else {
        listVersion.push_back(n.clone((listVersion.back())->getIdVersion()+1));
    }
    return (listVersion.back())->getIdVersion();
    */
    /*The new version below allows to add only one version (artcile, image...) in a note. If we want to add a new version
    we have to use copylatestversion*/
    if(listVersion.size()==0){
        listVersion.push_back(n.clone(0));
    }else {
        throw Exception("La note n'est pas vide...");
    }
    return (listVersion.back())->getIdVersion();
}

//void addNoteVersion(unsigned int id){
//    Note& n = getNote(id);
//    NotesVersion& latestVersion = n.listVersion.back();
//    NotesVersion newVersion = latestVersion;
//    newVersion.dateEdit.today();
//    newVersion.idVersion++;
//    //cout<<
//    n.listVersion.push_back(newVersion);


//}

int Note::copyLatestVersion(){
    if(listVersion.size()==0){
        throw Exception("La note est vide...");
    }else {
        NoteVersion* copyLatestVersion=listVersion.back()->clone((listVersion.back()->getIdVersion())+1);
        listVersion.push_back(copyLatestVersion);
    }
    return (listVersion.back())->getIdVersion();
}

NoteVersion& Note::getNoteVersion(unsigned int id) const{
    if(listVersion.size()==0)
        throw Exception("Il n'y a pas de verion pour cette note!");
    auto it = find_if(listVersion.begin(), listVersion.end(), [&id](NoteVersion* obj) {return obj->getIdVersion() == id;});
    if(it==listVersion.end())
        throw Exception("Il n'y a pas de version correspondant à l'id");
    return **it;
}

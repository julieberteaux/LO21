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

        stream->writeTextElement("type",(listVersion.back())->type());

        for(std::vector<NoteVersion*>::const_iterator it=listVersion.begin(); it!=listVersion.end(); ++it)
            (**it).saveNoteVersion(stream);

        stream->writeEndElement();
    }
}
void Note::loadVersion(QXmlStreamReader& xml){
    if(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "type")){
        throw Exception("Erreur lors du chargement: la balise n'est pas <type>.");
    }
    xml.readNext();

    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "note")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            // We've found identificteur.
            if(xml.name() == "idNote") {
                xml.readNext(); idNote=xml.text().toInt();
                //qDebug()<<"idNote="<<idNote<<"\n";
            }

            // We've found dateCrea.
            if(xml.name() == "dateCrea") {
                xml.readNext(); xml.readNext();
                unsigned int jour=xml.text().toInt();
                xml.readNext(); xml.readNext(); xml.readNext();
                unsigned int mois=xml.text().toInt();
                xml.readNext(); xml.readNext(); xml.readNext();
                unsigned int annee=xml.text().toInt();
                dateCrea.setDate(jour,mois,annee);
                //qDebug()<<"titre="<<titre<<"\n";
            }
        }
        // ...and next...
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

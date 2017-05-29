#include "notesmanager.h"
#include <QFile>
#include <QTextStream>

NotesManager::~NotesManager(){//composition: we delete every objects pointed by the vector
    for(std::vector<Note*>::iterator it=listNotes.begin(); it!=listNotes.end(); ++it)
        delete *it;
}

int NotesManager::addNote(){
    if(listNotes.size()==0){
        Note* n=new Note(0);
        listNotes.push_back(n);
    }else {
        listNotes.push_back(new Note((listNotes.back())->getIdNote()+1));
    }
    return (listNotes.back())->getIdNote();
}

Note& NotesManager::getNote(unsigned int id) const{
    if(listNotes.size()==0)
        throw Exception("Il n'y a pas de notes!");
    auto it = find_if(listNotes.begin(), listNotes.end(), [&id](Note* obj) {return obj->getIdNote() == id;});
    if(it==listNotes.end())
        throw Exception("Il n'y a pas de note correspondant à l'id");
    return **it;
}
void NotesManager::deleteNote(unsigned int id){
    if(listNotes.size()==0)
        throw Exception("Il n'y a pas de notes!");
    auto it = find_if(listNotes.begin(), listNotes.end(), [&id](Note* obj) {return obj->getIdNote() == id;});
    if(it==listNotes.end())
        throw Exception("Il n'y a pas de note correspondant à l'id");
    delete *it;
    listNotes.erase(it);
}

void NotesManager::save() const {
    QFile newfile(filename);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw Exception("erreur sauvegarde notes : ouverture fichier xml");
    QXmlStreamWriter stream(&newfile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("notes");

    for(std::vector<Note*>::const_iterator it=listNotes.begin(); it!=listNotes.end(); ++it)
        (**it).saveNote(&stream);

    stream.writeEndElement();
    stream.writeEndDocument();
    newfile.close();
}


void NotesManager::load() {
    //LOAD MUST BE USED ONLY AT THE START-UP OF THE PROGRAM (no verification of idNote...)
    QFile fin(filename);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw Exception("Erreur ouverture fichier notes");
    }
    // QXmlStreamReader takes any QIODevice.
    QXmlStreamReader xml(&fin);
    //qDebug()<<"debut fichier\n";
    // We'll parse the XML until we reach end of it.
    while(!xml.atEnd() && !xml.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = xml.readNext();
        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named notes, we'll go to the next.
            if(xml.name() == "notes") continue;
            // If it's named tache, we'll dig the information from there.
            if(xml.name() == "note") {
                //qDebug()<<"new note\n";
                unsigned int idNote;
                Date dateCrea;
                //QXmlStreamAttributes attributes = xml.attributes();
                xml.readNext();
                //We're going to loop over the things because the order might change.
                //We'll continue the loop until we hit an EndElement named note.
                while(!(xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "type")) {
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
                //qDebug()<<"ajout note "<<idNote<<"\n";
                Note* n=new Note(idNote,dateCrea);
                listNotes.push_back(n);
                n->loadVersion(xml);
            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw Exception("Erreur lecteur fichier notes, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
    //qDebug()<<"fin load\n";
}

#include "relationsmanager.h"


// QUESTIO :??? [&t](Relation* obj) {return obj->getTitle() == t;}  ??????
// est ce qu'on peut comparer 2 string avec ==

Relation* RelationsManager::getRelation(const QString& t) {
    if(listRelations.size()==0)
        return nullptr;
    auto it = find_if(listRelations.begin(), listRelations.end(), [&t](Relation* obj) {return obj->getTitle() == t;});
    if(it==listRelations.end())
        return nullptr;
    return *it;

}

//PROBLEME
void RelationsManager::addRelation(const QString& t, const QString& d, bool o){


    const Relation* r = getRelation(t);
    if (r==nullptr)
    {
        listRelations.push_back(new Relation(t, d, o));

    }
    else
    {
        throw Exception("Cette relation existe deja");
    }


}

void RelationsManager::displayRelationCouples (const QString& t, std::ostream& f) {
    const Relation* r = getRelation(t);

    //parcourir r.listCouples et tous les afficher
}

// QUESTION :??? [&t](Relation* obj) {return obj->getTitle() == t;}  ??????
// est ce qu'on peut comparer 2 string avec ==


void RelationsManager::deleteRelation(const QString& t){
    if(listRelations.size()==0)
        throw Exception("Il n'y a pas de Relation!");
    auto it = find_if(listRelations.begin(), listRelations.end(), [&t](Relation* obj) {return obj->getTitle() == t;});
    if(it==listRelations.end())
        throw Exception("Il n'y a pas de Relation correspondant à ce titre");
    delete *it;
    listRelations.erase(it);
}


void RelationsManager::save() const {
    QFile newfile(filename);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw Exception("erreur sauvegarde relation : ouverture fichier xml");
    QXmlStreamWriter stream(&newfile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("relations");

    for(std::vector<Relation*>::const_iterator it=listRelations.begin(); it!=listRelations.end(); ++it)
        (**it).saveRelation(&stream);

    stream.writeEndElement();
    stream.writeEndDocument();
    newfile.close();
}


void RelationsManager::load() {
    //LOAD MUST BE USED ONLY AT THE START-UP OF THE PROGRAM (no verification of idNote...)
    QFile fin(filename);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw Exception("Erreur ouverture fichier relation");
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
            if(xml.name() == "relations") continue;
            // If it's named tache, we'll dig the information from there.
            if(xml.name() == "relation") {
                qDebug()<<"new relation\n";
                Relation* r=new Relation();
                listRelations.push_back(r);
                xml.readNext();
                r->loadRelation(xml);
                qDebug()<<"relation"<<"\n";
            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw Exception("Erreur lecteur fichier relation, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
    qDebug()<<"fin load\n";
}


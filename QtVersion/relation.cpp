#include "relation.h"

void Relation::addCouple(Couple& c){
    listCouples.push_back(&c);
}

void Relation::saveRelation(QXmlStreamWriter* stream) const {
        stream->writeStartElement("relation");
        stream->writeTextElement("title",title);
        stream->writeTextElement("description",description);
        stream->writeTextElement("oriented",QString::number(oriented));
        stream->writeEndElement();
}

void Relation::loadRelation(QXmlStreamReader &xml){
    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "relation")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            // We've found text.
            if(xml.name() == "title") {
                xml.readNext();
                title=xml.text().toString();
                qDebug()<<"title="<<title<<"\n";
            }

            if(xml.name() == "description") {
                xml.readNext();
                description=xml.text().toString();
                qDebug()<<"description="<<description<<"\n";
            }
            if(xml.name() == "oriented") {
                xml.readNext();
                oriented=xml.text().toInt();
                qDebug()<<"description="<<description<<"\n";
            }
        }
        xml.readNext();
    }
    xml.readNext();
}

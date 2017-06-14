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

NoteVersion::NoteVersion(unsigned int v, const QString& t): idVersion(v), title(t), dateEdit(){dateEdit.today();}

const QString& NoteVersion::getTitle() const {return title;}

void NoteVersion::setTitle(const QString& str) {title=str;}

const Date& NoteVersion::getDateEdit() const{return dateEdit;}

void NoteVersion::setDateEdit(const Date& d){dateEdit=d;}

NoteVersion::~NoteVersion(){};

unsigned int NoteVersion::getIdVersion() const{return idVersion;}

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
/*********************************NoteVersionFactory***********************/
//used for load method

NoteVersionFactory::map_type * NoteVersionFactory::getMap() {
    // never delete'ed. (exist until program termination)
    // because we can't guarantee correct destruction order
    if(!map) { map = new map_type; }
    return map;
}


NoteVersion * NoteVersionFactory::createInstance(const QString & s) {
    map_type::iterator it = getMap()->find(s);
    if(it == getMap()->end())
        return 0;
    return it->second();
}

/********************************** Article ****************************/
DerivedRegister<Article> Article::reg("Article");

Article::Article (const QString& t, const QString& te): NoteVersion(0, t), text(te){}

const QString& Article::getText() const {return text;}
void Article::setText(const QString& str) {text=str;}
QString Article::type() const {return "Article";}

Article* Article::clone(unsigned int id) const{
    Article* art=new Article(*this);
    art->idVersion=id;
    (art->dateEdit).today();
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

FormVersion* Article::formVersion() {return new FormArticle(this);}

/********************************** Task ****************************/
DerivedRegister<Task> Task::reg("Task");

Task::Task (const QString& t,const QString& a, unsigned int p, const Date d, const Status s): NoteVersion(0, t), action(a), priority(p), deadline(d), status(s){}

const QString& Task::getAction() const {return action;}
unsigned int Task::getPriority() const {return priority;}
const Date& Task::getDeadline() const {return deadline;}
const Task::Status& Task::getStatus() const {return status;}
QString Task::type() const {return "Task";}

Task* Task::clone(unsigned int id) const{
    Task* tsk=new Task(*this);
    tsk->idVersion=id;
    (tsk->dateEdit).today();
    return tsk;
}

void Task::saveNoteVersionType(QXmlStreamWriter& stream) const{
    //A FAIRE SUR LE MEME MODELE QUE ARTICLES EN AJOUTANT DES CHAMPS
}

void Task::loadNoteVersionType(QXmlStreamReader& stream){
  //A FAIRE SUR LE MEME MODELE QUE ARTICLES EN AJOUTANT DES CHAMPS

}

FormVersion* Task::formVersion() {return nullptr;}

/********************************** Image ****************************/
DerivedRegister<Image> Image::reg("Image");
Image::Image(const QString& t, const QString& d, const QString& f): NoteVersion(0, t), description(d), file(f){}

const QString& Image::getDescription() const {return description;}
const QString& Image::getFile() const {return file;}
QString Image::type() const {return "Image";}

Image* Image::clone(unsigned int id) const{
    Image* img=new Image(*this);
    img->idVersion=id;
    (img->dateEdit).today();
    return img;
}

void Image::saveNoteVersionType(QXmlStreamWriter& stream) const{
    stream.writeTextElement("description",description);
    stream.writeTextElement("file",file);

}

void Image::setFile(const QString& str){
    file=str;
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

FormVersion* Image::formVersion() {return new FormImage(this);}


/********************************** Audio ****************************/
Audio::Audio (const QString& t, const QString& d, const QString& f): NoteVersion(0, t), description(d), file(f){}

const QString& Audio::getDescription() const {return description;}
const QString& Audio::getFile() const {return file;}
QString Audio::type() const {return "Audio";}

Audio* Audio::clone(unsigned int id) const{
    Audio* aud=new Audio(*this);
    aud->idVersion=id;
    (aud->dateEdit).today();

    return aud;
}
void Audio::saveNoteVersionType(QXmlStreamWriter& stream) const{
    //A FAIRE
}

void Audio::loadNoteVersionType(QXmlStreamReader &xml){

}
FormVersion* Audio::formVersion() {return nullptr;}

/********************************** Video ****************************/

Video::Video (const QString& t, const QString& d, const QString& f): NoteVersion(0, t), description(d), file(f){}

const QString& Video::getDescription() const {return description;}
const QString& Video::getFile() const {return file;}
QString Video::type() const {return "Video";}

Video* Video::clone(unsigned int id) const{
    //A FAIRE
}

void Video::saveNoteVersionType(QXmlStreamWriter& stream) const{
    //A FAIRE
}

void Video::loadNoteVersionType(QXmlStreamReader &xml){

}
FormVersion* Video::formVersion() {return nullptr;}


/*******************************INTERFACE NOTEVERSION*****************/

FormVersion::FormVersion(QWidget *parent): QWidget(parent){}
FormVersion::~FormVersion(){}

/***********************ARTICLE***********************/

FormArticle::FormArticle(Article *a, QWidget *parent): FormVersion(parent), article(a){
    textLabel=new QLabel("Texte:");
    text=new QTextEdit();
    textHbox=new QHBoxLayout();
    text->setText(a->getText());
    textHbox->addWidget(textLabel);
    textHbox->addWidget(text);
    this->setLayout(textHbox);

}
FormArticle::~FormArticle(){
    delete textLabel;
    delete text;
    delete textHbox;
}
void FormArticle::saveVersion(NoteVersion* ver){
    article=dynamic_cast<Article*>(ver);
    article->setText(text->toPlainText());
}

/***********************IMAGE***********************/
void FormImage::printImage(){
    imageLabel->setPixmap(QPixmap(image->getFile()).scaled(200,200,Qt::KeepAspectRatio));
    imageHbox->addWidget(imageLabel);
}

FormImage::FormImage(Image *a, QWidget *parent): FormVersion(parent), import(new QPushButton("Importer")), image(a), imageLabel(new QLabel()), imageHbox(new QHBoxLayout()){
    imageHbox->addWidget(import);
    printImage();
    QObject::connect(import, SIGNAL(clicked()), this, SLOT(importImage()));
    this->setLayout(imageHbox);

}

FormImage::~FormImage(){
    delete imageLabel;
    delete imageHbox;
}

void FormImage::importImage(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir une Image"), "./", tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    //std::cout<<fileName.toStdString()<<std::endl;
    image->setFile(fileName);
    printImage();
}


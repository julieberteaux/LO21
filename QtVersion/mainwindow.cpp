#include "mainwindow.h"
#include "notesmanager.h"
#include "ui_mainwindow.h"
#include "ui_formnote.h"
#include "ui_formrelation.h"
#include "ui_typenote.h"
#include "ui_formrelation.h"
#include "ui_listversions.h"

#include <QDebug>
#include<QMessageBox>

void FormNote::activateButtons()
{
    const std::vector<Note*>& notes=manager->getListNotes();
    if (!notes.empty()){
        ui->save->setEnabled(true);
        ui->supp->setEnabled(true);
    }
}

void MainWindow::loadActiveNotes(){
    const std::vector<Note*>& notes=manager->getListNotes();
    for(std::vector<Note* const>::iterator it=notes.begin(); it!=notes.end(); ++it){
        if((**it).getNoteState()==active){
            QListWidgetItem *item = new QListWidgetItem((**it).getLatestNoteVersion().getTitle());
            QVariant v;
            v.setValue((**it).getIdNote());
            item->setData(Qt::UserRole, v);
            ui->activenotes->addItem(item);

        }
    }

    if (formnote) formnote->activateButtons();
}

void MainWindow::unloadActiveNotes(){
     QListWidgetItem *item;
     unsigned int numberRows=ui->activenotes->count();
    for(int row = 0; row < numberRows; row++)
    {
        item = ui->activenotes->item(0);
        delete item;
    }
}


MainWindow::MainWindow(NotesManager* m,RelationsManager* r,Trash* t, QWidget *parent) :manager(m), managerR(r),formnote(nullptr), formrelation(nullptr),QMainWindow(parent),ui(new Ui::MainWindow), trash(t)
{
    ui->setupUi(this);
    loadActiveNotes();
    loadRelations();
    QObject::connect(ui->restore, SIGNAL(clicked()),this, SLOT(restoreNote()));
    QObject::connect(ui->supp, SIGNAL(clicked()),this, SLOT(deleteNote()));

    connect(ui->exit, SIGNAL(triggered()), this, SLOT(exit()));

}

void MainWindow::exit(){
    QMessageBox::information(this,"Exit", "Vidage de la Corbeille, au revoir !");
    this-> close();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete formnote;
    delete type;
}

void MainWindow::on_activenotes_itemClicked(QListWidgetItem *item)
{
    delete formnote;
    QVariant v = item->data(Qt::UserRole);
    unsigned int i=v.toInt();
    formnote=new FormNote(this, manager, i);
    ui->centre->addWidget(formnote);
}

void MainWindow::on_createNote_clicked(){
    type=new typeNote(manager,this);
    type->loadTypes();
    type->show();

}

void MainWindow::refresh(){
    unloadActiveNotes();
    loadActiveNotes();
}

void MainWindow::refreshTrash(){
    unloadTrashedNotes();
    loadTrashedNotes();
}

FormNote::FormNote(MainWindow *mwind, NotesManager *m, unsigned int id, QWidget *parent) : mainwindow(mwind), manager(m), idNote(id),version(nullptr),listversions(nullptr),QWidget(parent),ui(new Ui::FormNote)
{
    ui->setupUi(this);
    Note& note=manager->getNote(idNote);
    ui->idNoteLineEdit->setText(QString::number(note.getIdNote()));
    ui->idNoteLineEdit->setReadOnly(true);
    const Date& dateCreation=note.getDateCrea();
    ui->dateCreaDateEdit->setDate(QDate(dateCreation.getAnnee(),dateCreation.getMois(),dateCreation.getJour()));
    ui->dateCreaDateEdit->setReadOnly(true);
    NoteVersion& ver=note.getLatestNoteVersion();
    ui->idVersionLineEdit->setText(QString::number(ver.getIdVersion()));
    ui->idVersionLineEdit->setReadOnly(true);
    ui->titleLineEdit->setText(ver.getTitle());
    const Date& dateEdit=ver.getDateEdit();
    ui->dateEditDateEdit->setDate(QDate(dateEdit.getAnnee(),dateEdit.getMois(),dateEdit.getJour()));
    ui->dateEditDateEdit->setReadOnly(true);
    version=ver.formVersion();
    ui->versionLayout->addWidget(version);
    //ui->save->setEnabled(false);
    //QObject::connect(ui->titleLineEdit, SIGNAL(textChanged(QString)),this, SLOT(activerSave()));
    QObject::connect(ui->save, SIGNAL(clicked()),this, SLOT(saveNote()));
    QObject::connect(ui->supp, SIGNAL(clicked()),this, SLOT(PutToTrash()));
    QObject::connect(ui->versions, SIGNAL(clicked()),this, SLOT(showVersions()));

}

FormNote::~FormNote()
{
    delete version;
    delete ui;
    delete listversions;
}

void FormNote::saveNote()
{
    Note& n=manager->getNote(idNote);
    n.copyLatestVersion();
    NoteVersion& LatestVersion=n.getLatestNoteVersion();

    LatestVersion.setTitle(ui->titleLineEdit->text());

    version->saveVersion(&LatestVersion);

    ui->idVersionLineEdit->setText(QString::number(LatestVersion.getIdVersion()));
    Date dateEdit=LatestVersion.getDateEdit();
    ui->dateEditDateEdit->setDate(QDate(dateEdit.getAnnee(),dateEdit.getMois(),dateEdit.getJour()));

    //ui->save->setDisabled(true);
    mainwindow->refresh();
    QMessageBox::information(this,"Sauvegarde", "Note sauvegardée !!!");

    manager->save();

}

void MainWindow::unloadTrashedNotes(){
     QListWidgetItem *item;
    for(int row = 0; row <= (ui->trashedNotes->count()); row++){
        item = ui->trashedNotes->item(0);
        delete item;
    }
}

void FormNote::disableButtons() {
    const std::vector<Note*>& notes=manager->getListNotes();
    if (notes.empty()){
        ui->supp->setDisabled(true);
        ui->save->setDisabled(true);
    }

}

void FormNote::PutToTrash()
{
    mainwindow->unloadTrashedNotes();
//    Note& n=manager->getNote(idNote);
    manager->putToTrash(idNote);
    //ui->save->setDisabled(true);
    mainwindow->refresh();
    QMessageBox::information(this,"Supression", "Note supprimée !!!");

    manager->save();
    mainwindow->loadTrashedNotes();
    disableButtons();

}
void FormNote::showVersions(){
    listversions=new ListVersions(manager,idNote);
    listversions->loadVersions();
    listversions->show();
}

ListVersions::ListVersions(NotesManager *m, unsigned int id, QWidget *parent) : manager(m), idNote(id),QWidget(parent),ui(new Ui::ListVersions)
{
    ui->setupUi(this);
}

ListVersions::~ListVersions()
{
    delete ui;
}
void ListVersions::loadVersions(){
    Note& n=manager->getNote(idNote);
    std::vector<NoteVersion*> versions=n.getListVersions();
    for(auto it=versions.begin(); it!=versions.end(); ++it){
        std::string str=std::to_string((*it)->getIdVersion())+" "+(*it)->getTitle().toStdString();
        std::cout<<str<<std::endl;
        QString qstr = QString::fromStdString(str);
        ui->listWidget->addItem(qstr);
    }
}


void MainWindow::loadTrashedNotes(){
    const std::vector<Note*>& notes=trash->getListTrashedNotes();
    for(std::vector<Note* const>::iterator it=notes.begin(); it!=notes.end(); ++it){
            QListWidgetItem *item = new QListWidgetItem((**it).getLatestNoteVersion().getTitle());
            QVariant v;
            v.setValue((**it).getIdNote());
            item->setData(Qt::UserRole, v);
            ui->trashedNotes->addItem(item);
    }
}

void MainWindow::on_trashedNotes_itemClicked(QListWidgetItem *item)
{
    ui->restore->setEnabled(true);
    ui->supp->setEnabled(true);
}

void MainWindow::restoreNote(){
   //recuperer l'id venant de l'item cliqué...
    QListWidgetItem* item = ui->trashedNotes->currentItem();
    QVariant v = item->data(Qt::UserRole);
    int id = v.value<int>();
    trash->putBackNote(id);
    refreshTrash();
    refresh();


}

void MainWindow::deleteNote(){
    //recuperer l'id venant de l'item cliqué...
//    trash->deleteNote(idNote);
    QListWidgetItem* item = ui->trashedNotes->currentItem();
    QVariant v = item->data(Qt::UserRole);
    int id = v.value<int>();
    trash->deleteNote(id);
    refreshTrash();
}

typeNote::typeNote(NotesManager *m, MainWindow *mwindow, QWidget *parent) : manager(m), mainwindow(mwindow), QWidget(parent), ui(new Ui::typeNote)
{
    ui->setupUi(this);
    //QObject::connect(ui->validate, SIGNAL(clicked()),this, SLOT(on_validate_clicked()));
}

typeNote::~typeNote()
{
    delete ui;
}

void typeNote::loadTypes()
{
    NoteVersionFactory::map_type::iterator it = NoteVersionFactory::getMap()->begin();
    for(NoteVersionFactory::map_type::iterator it = NoteVersionFactory::getMap()->begin(); it!=NoteVersionFactory::getMap()->end(); it++){
        QListWidgetItem *item = new QListWidgetItem(it->first);
        ui->type->addItem(item);
    }
}

void typeNote::on_type_itemClicked(QListWidgetItem *item){
    int idNote=manager->addNote();
    Note& n=manager->getNote(idNote);
    NoteVersion* version=NoteVersionFactory::createInstance(item->text());
    version->setTitle("A MODIFIER: Nouvelle note!");
    n.addNoteVersion(*version);
    delete version;
    mainwindow->refresh();
    manager->save();
    this->close();
}


///////////// Relations /////////////////////

void MainWindow::loadRelations(){
    const std::vector<Relation*>& relations=managerR->getListRelations();
    for(std::vector<Relation* const>::iterator it=relations.begin(); it!=relations.end(); ++it){
            QListWidgetItem *item = new QListWidgetItem((**it).getTitle());
            ui->activerelations->addItem(item);
    }
}
void MainWindow::unloadRelations(){
     QListWidgetItem *item;
     unsigned int nbrow=ui->activerelations->count();
    for(int row = 0; row < nbrow; row++)
    {
        item = ui->activerelations->item(0);
        delete item;
    }
}

void MainWindow::refreshRelation(){
    unloadRelations();
    loadRelations();
}

///////////// FormRelation /////////////////////

FormRelation::FormRelation(MainWindow* mwind, RelationsManager* r, QString t,  QWidget *parent) : managerR(r), mainwindow(mwind), title(t), QWidget(parent), ui(new Ui::FormRelation)
{

    ui->setupUi(this);
    ui->saveR->setDisabled(true);
    ui->oriented->setChecked(1);
    unsigned int newRelation=1;
    if(title!=""){
        newRelation=0;
        const Relation* rela=managerR->getRelation(title);
        ui->titleEdit->setText(rela->getTitle());
        ui->descriptionEdit->setText(rela->getDescription());
        if(rela->getOrientation()==1){
            ui->nonOriented->setChecked(1);
            ui->oriented->setChecked(1);
        }else{
            ui->oriented->setChecked(0);
            ui->nonOriented->setChecked(1);
        }
    }
    QObject::connect(ui->titleEdit, SIGNAL(textChanged(QString)),this, SLOT(activateSave()));
    QObject::connect(ui->descriptionEdit, SIGNAL(textChanged()),this, SLOT(activateSave()));
    QObject::connect(ui->oriented, SIGNAL(toggled(bool)),this, SLOT(activateSave()));
    QObject::connect(ui->nonOriented, SIGNAL(toggled(bool)),this, SLOT(activateSave()));
    if(newRelation==1){
        QObject::connect(ui->saveR, SIGNAL(clicked()),this, SLOT(saveNewRelation()));
    }else{
        QObject::connect(ui->saveR, SIGNAL(clicked()),this, SLOT(saveRelation()));
    }
}

FormRelation::~FormRelation()
{
    delete ui;
}

void MainWindow::on_createRelation_clicked(){
    FormRelation* rel=new FormRelation(this, managerR);
    rel->show();

}

void FormRelation::activateSave(){
    ui->saveR->setEnabled(true);
}

void MainWindow::on_activerelations_itemClicked(QListWidgetItem *item)
{
    delete formrelation;
    formrelation=new FormRelation(this, managerR, item->text());
    ui->centreRelation->addWidget(formrelation);
}

void FormRelation::saveNewRelation(){
    bool o;
    if(ui->oriented->isChecked())
        o=1;
    else
        o=0;
    managerR->addRelation(ui->titleEdit->text(),ui->descriptionEdit->toPlainText(),o);
    //ui->save->setDisabled(true);
    mainwindow->refreshRelation();
    QMessageBox::information(this,"Sauvegarde", "Relation sauvegardée !!!");
    this->close();
    managerR->save();
}

void FormRelation::saveRelation(){
    std::cout<<"test10"<<std::endl;
    bool o;
    if(ui->oriented->isChecked())
        o=1;
    else
        o=0;
    Relation* r=managerR->getRelation(title);
    r->setTitle(ui->titleEdit->text());
    r->setDescription(ui->descriptionEdit->toPlainText());
    r->setOrientation(ui->oriented->isChecked());
    //ui->save->setDisabled(true);
    mainwindow->refreshRelation();

    QMessageBox::information(this,"Sauvegarde", "Relation sauvegardée !!!");
    this->close();
    managerR->save();
}

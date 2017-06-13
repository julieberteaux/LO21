#include "mainwindow.h"
#include "notesmanager.h"
#include "trasheditor.h"
#include "ui_mainwindow.h"
#include "ui_formnote.h"
#include "ui_typenote.h"
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

MainWindow::MainWindow(NotesManager* m,Trash* t, QWidget *parent) :manager(m), formnote(nullptr), QMainWindow(parent),ui(new Ui::MainWindow), trash(t)
{
    ui->setupUi(this);
    loadActiveNotes();
    QObject::connect(ui->supp, SIGNAL(clicked()),this, SLOT(deleteNote()));
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

FormNote::FormNote(MainWindow *mwind, NotesManager *m, unsigned int id, QWidget *parent) : mainwindow(mwind), manager(m), idNote(id),version(nullptr),
    QWidget(parent),ui(new Ui::FormNote)
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
}

FormNote::~FormNote()
{
    delete version;
    delete ui;
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
    for(int row = 0; row <= (ui->trashedNotes->count()); row++)
    {
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

    //manager->save(); A remettre quand la corbeille sera opérationnelle
    mainwindow->loadTrashedNotes();
    disableButtons();

}

void MainWindow::loadTrashedNotes(){
    const std::vector<Note*>& notes=trash->getListTrashedNotes();
    for(std::vector<Note* const>::iterator it=notes.begin(); it!=notes.end(); ++it){
            std::cout<< "load trash"<<std::endl;
            QListWidgetItem *item = new QListWidgetItem((**it).getLatestNoteVersion().getTitle());
            QVariant v;
            v.setValue((**it).getIdNote());
            item->setData(Qt::UserRole, v);
            ui->trashedNotes->addItem(item);

    }
}

void MainWindow::on_trashedNotes_itemClicked(QListWidgetItem *item)
{
    ui->save->setEnabled(true);
    ui->supp->setEnabled(true);
}

void MainWindow::restoreNote(){
   //recuperer l'id venant de l'item cliqué...
//    trash->putBackNote(item->v);
}

void MainWindow::deleteNote(){
    //recuperer l'id venant de l'item cliqué...
//    trash->deleteNote(idNote);
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


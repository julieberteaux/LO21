#include "mainwindow.h"
#include "notesmanager.h"
#include "trasheditor.h"
#include "ui_mainwindow.h"
#include "ui_formnote.h"
#include "ui_typenote.h"

#include<QMessageBox>
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
}

void MainWindow::unloadActiveNotes(){
     QListWidgetItem *item;
    for(int row = 0; row <= (ui->activenotes->count()); row++)
    {
        item = ui->activenotes->item(0);
        delete item;
    }
}

MainWindow::MainWindow(NotesManager* m,Trash* t, QWidget *parent) :manager(m), formnote(nullptr), QMainWindow(parent),ui(new Ui::MainWindow), trash(t)
{
    ui->setupUi(this);
    loadActiveNotes();
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
    type=new typeNote(manager);
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
    QObject::connect(ui->supp, SIGNAL(clicked()),this, SLOT(deleteNote()));
}

FormNote::~FormNote()
{
    delete version;
    delete ui;
}

void FormNote::activerSave()
{
    //ui->save->setEnabled(true);
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

void FormNote::deleteNote()
{
    Note& n=manager->getNote(idNote);
    manager->putToTrash(idNote);
    //ui->save->setDisabled(true);
    mainwindow->refresh();
    QMessageBox::information(this,"Supression", "Note supprimée !!!");

    //manager->save(); A remettre quand la corbeille sera opérationnelle
    mainwindow->loadTrashedNotes();
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



typeNote::typeNote(NotesManager *m, QWidget *parent) : manager(m), QWidget(parent), ui(new Ui::typeNote)
{
    ui->setupUi(this);
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
        std::cout<<(it->first).toStdString()<<std::endl;
        std::cout<<"test"<<std::endl;

        //QVariant v;
        //v.setValue((**it).getIdNote());
        //item->setData(Qt::UserRole, v);
        ui->listWidget->addItem(item);
    }
}
void typeNote::on_validate_clicked(){

}


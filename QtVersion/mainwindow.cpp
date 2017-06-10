#include "mainwindow.h"
#include "notesmanager.h"
#include "ui_mainwindow.h"
#include "ui_formnote.h"

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

MainWindow::MainWindow(NotesManager* m, QWidget *parent) :manager(m), formnote(nullptr), QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadActiveNotes();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete formnote;
}

void MainWindow::on_activenotes_itemClicked(QListWidgetItem *item)
{
    delete formnote;
    formnote=new FormNote(this, manager, item);
    ui->centre->addWidget(formnote);
}
void MainWindow::refresh(){
    unloadActiveNotes();
    loadActiveNotes();
}

FormNote::FormNote(MainWindow *mwind, NotesManager *m, QListWidgetItem *i, QWidget *parent) : mainwindow(mwind), manager(m), item(i),version(nullptr),
    QWidget(parent),ui(new Ui::FormNote)
{
    ui->setupUi(this);
    QVariant v = item->data(Qt::UserRole);
    int idNote = v.value<int>();
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
}

FormNote::~FormNote()
{
    delete version;
    delete ui;
}

void FormNote::activerSave()
{
    ui->save->setEnabled(true);
}

void FormNote::saveNote()
{
    QVariant v = item->data(Qt::UserRole);
    int idNote = v.toInt();
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
    QMessageBox::information(this,"Sauvegarde", "Article sauvegardé !!!");

    //if (filename!="") save();
}

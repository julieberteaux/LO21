#include "formnote.h"
#include "ui_formnote.h"
FormNote::FormNote(NotesManager *m, QListWidgetItem *i, QWidget *parent) : manager(m), item(i),version(nullptr),
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

}

FormNote::~FormNote()
{
    delete version;
    delete ui;
}

#include "mainwindow.h"
#include "notesmanager.h"

#include "ui_mainwindow.h"
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
    // get back the data
    //QVariant v = item->data(Qt::UserRole);
    //int id = v.value<int>();
}

MainWindow::MainWindow(NotesManager* m, QWidget *parent) :manager(m), QMainWindow(parent),ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    loadActiveNotes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

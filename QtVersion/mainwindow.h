/**
 * \file	mainwindow.h
 * \brief	Définition de la classe MainWindow
 * \details La classe MainWindow permet de gérer l'interface grahique de notre application, elle a été réalisée à l'aide de Qt Designer.
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QListWidgetItem>
#include <QMessageBox>
#include <Qdialog>

#include "notesmanager.h"
#include "relationsmanager.h"
//#include "trasheditor.h"
namespace Ui {
class MainWindow;
}
class FormNote;
class FormRelation;
class FormRelation;
class typeNote;
class ListVersions;

class MainWindow : public QMainWindow{
    Q_OBJECT
    NotesManager* manager;
    FormNote* formnote;
    FormRelation* formrelation;
    RelationsManager* managerR;
    Trash *trash;
    typeNote* type;

public:
    explicit MainWindow(NotesManager *m,RelationsManager* r,Trash* t, QWidget *parent = 0);
    ~MainWindow();
    void loadActiveNotes();
    void unloadActiveNotes();
    void loadTrashedNotes();
    void unloadTrashedNotes();
    void loadRelations();
    void unloadRelations();

    void refresh();
    void refreshTrash();
    void refreshRelation();



public slots:
    void on_activenotes_itemClicked(QListWidgetItem *item);
    void on_activerelations_itemClicked(QListWidgetItem *item);

    void on_createNote_clicked();
    void on_createRelation_clicked();
    void restoreNote();
    void deleteNote();


    void on_trashedNotes_itemClicked(QListWidgetItem *item);

    void exit();


private:
    Ui::MainWindow *ui;
};






namespace Ui {
class FormNote;
}

class FormNote : public QWidget
{
    Q_OBJECT
    MainWindow* mainwindow;
    NotesManager* manager;
    unsigned int idNote;
    FormVersion* version;
    ListVersions* listversions;
public:
    explicit FormNote(MainWindow* mwind, NotesManager* m, unsigned int id, QWidget *parent = 0);
    ~FormNote();

public slots:
    void activateButtons();
    void disableButtons();
    void saveNote();
    void PutToTrash();
    void showVersions();

private:
    Ui::FormNote *ui;
};


namespace Ui {
class typeNote;
}

class typeNote : public QWidget
{
    Q_OBJECT
    NotesManager* manager;
    MainWindow* mainwindow;
public:
    explicit typeNote(NotesManager* m, MainWindow* mwindow, QWidget *parent = 0);
    ~typeNote();
    void loadTypes();
public slots:
    void on_type_itemClicked(QListWidgetItem *item);

private:
    Ui::typeNote *ui;
};


namespace Ui {
class FormRelation;
}

class FormRelation : public QWidget
{
    Q_OBJECT
    MainWindow* mainwindow;
    RelationsManager* managerR;
    QString title;

public:
    explicit FormRelation(MainWindow* mwind, RelationsManager* r, QString t="",  QWidget *parent = 0);
    ~FormRelation();

public slots:
    void activateSave();
    void saveNewRelation();
    void saveRelation();

private:
    Ui::FormRelation *ui;
};

namespace Ui {
class ListVersions;
}

class ListVersions : public QWidget
{
    Q_OBJECT
    unsigned int idNote;
    NotesManager* manager;
public:
    explicit ListVersions(NotesManager* m, unsigned int id, QWidget *parent = 0);
    void loadVersions();
    ~ListVersions();

private:
    Ui::ListVersions *ui;
};

#endif // MAINWINDOW_H

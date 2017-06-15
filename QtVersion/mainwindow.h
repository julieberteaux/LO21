/**
 * \file	mainwindow.h
 * \brief	Définition de la classe MainWindow
 * \details La classe MainWindow permet de gérer l'interface grahique de notre application qui a été réalisée à l'aide de Qt Designer.
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
namespace Ui { class MainWindow;}

class FormNote;
class FormRelation;
class FormRelation;
class typeNote;
class ListVersions;

/**
* \class MainWindow mainwindow.h
*/
class MainWindow : public QMainWindow{
    Q_OBJECT
    NotesManager* manager;
    FormNote* formnote;
    FormRelation* formrelation;
    RelationsManager* managerR;
    Trash *trash;
    typeNote* type;

public:

  /**
  *\brief
  *\param   m   Instance de notes manager
  *\param   r   Instance de reation manager
  *\param   t   Instance de Trash
  */
    explicit MainWindow(NotesManager *m,RelationsManager* r,Trash* t, QWidget *parent = 0);
    ~MainWindow();

    /**
    *\brief
    */
    void loadActiveNotes();

    /**
    *\brief
    */
    void unloadActiveNotes();

    /**
    *\brief
    */
    void loadTrashedNotes();

    /**
    *\brief
    */
    void unloadTrashedNotes();

    /**
    *\brief
    */
    void loadRelations();

    /**
    *\brief
    */
    void unloadRelations();

    /**
    *\brief
    */
    void refresh();

    /**
    *\brief
    */
    void refreshTrash();

    /**
    *\brief
    */
    void refreshRelation();

    /**
    *\brief
    */
    void resetFormnote(){formnote=nullptr;}



public slots:

    /**
    *\brief
    */
    void on_activenotes_itemClicked(QListWidgetItem *item);

    /**
    *\brief
    */
    void on_activerelations_itemClicked(QListWidgetItem *item);

    /**
    *\brief
    */
    void on_createNote_clicked();

    /**
    *\brief
    */
    void on_createRelation_clicked();

    /**
    *\brief
    */
    void restoreNote();

    /**
    *\brief
    */
    void deleteNote();

    /**
    *\brief
    */
    void on_trashedNotes_itemClicked(QListWidgetItem *item);

    /**
    *\brief
    */
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

    /**
    *\brief
    */
    void activateButtons();

    /**
    *\brief
    */
    void disableButtons();

    /**
    *\brief
    */
    void saveNote();

    /**
    *\brief
    */
    void PutToTrash();

    /**
    *\brief
    */
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

    /**
    *\brief
    */
    void loadTypes();
public slots:

    /**
    *\brief
    */
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

    /**
    *\brief
    */
    void activateSave();

    /**
    *\brief
    */
    void saveNewRelation();

    /**
    *\brief
    */
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

    /**
    *\brief
    */
    void loadVersions();

    /**
    *\brief destructeur de la classe ListVersions
    */
    ~ListVersions();

public slots:
    /**
    *\brief
    */
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::ListVersions *ui;
};

#endif // MAINWINDOW_H

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
  *\brief Constructeur de la fenetre
  *\param   m   Instance de notes manager
  *\param   r   Instance de reation manager
  *\param   t   Instance de Trash
  */
    explicit MainWindow(NotesManager *m,RelationsManager* r,Trash* t, QWidget *parent = 0);
    ~MainWindow();

    /**

    *\brief Charge les notes présentes dans NotesManager
    */
    void loadActiveNotes();

    /**
    *\brief Enlève les notes actives de l'interface
    */
    void unloadActiveNotes();

    /**
    *\brief Charge les notes présentes dans Trash
    */
    void loadTrashedNotes();

    /**
    *\brief Enlève les notes de l'interface de la Corbeille
    */
    void unloadTrashedNotes();

    /**
    *\brief Charge les relations présentes dans RelationManager
    */
    void loadRelations();

    /**
    *\brief Enlève les relations de l'interface
    */
    void unloadRelations();

    /**
    *\brief Rafraichit l'interface à l'aide des méthodes unloadActiveNotes puis loadActiveNotes
    */
    void refresh();

    /**
    *\brief  Rafraichit l'interface de la Corbeille à l'aide des méthodes unloadTrashedNotes puis loadTrashedNotes
    */
    void refreshTrash();

    /**
    *\brief Rafraichit l'interface de la Corbeille à l'aide des méthodes unloadRelations puis loadTRelations
    */
    void refreshRelation();



public slots:

    /**
    *\brief Affiche les détails de la note cliquée
    *\param   item   note cliquée
    */
    void on_activenotes_itemClicked(QListWidgetItem *item);

    /**
    *\brief Affiche les détails de la relation cliquée
    * \param   item   relation cliquée
    */
    void on_activerelations_itemClicked(QListWidgetItem *item);

    /**
    *\brief Lance un formulaire pour choisir le type de note désiréé
    */
    void on_createNote_clicked();

    /**
    *\brief Lance un formulaire pour créer une relation
    */
    void on_createRelation_clicked();

    /**
    *\brief Restaure une note et la replace dans NotesManager
    */
    void restoreNote();

    /**
    *\brief Supprime définitivement une note
    */
    void deleteNote();

    /**
    *\brief Permet d'activer les boutons restaurer et supprimer lorsque une note de la Corbeille est cliquée
    * \param   item   note cliquée de la Corbeille
    */
    void on_trashedNotes_itemClicked(QListWidgetItem *item);

    /**
    *\brief Ferme l'application
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
    *\brief Active les boutons sauver et supprimer
    */
    void activateButtons();

    /**
    *\brief Désactive les boutons sauver et supprimer
    */
    void disableButtons();

    /**
    *\brief Enregistre la note dans NotesManager
    */
    void saveNote();

    /**
    *\brief Déplace la note vers la Corbeille
    */
    void PutToTrash();

    /**
    *\brief Affiche les versions d'une note dans l'interface
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
    *\brief Charge l'ensemble des types de notes que l'on peut créer
    */
    void loadTypes();
public slots:

    /**
    *\brief Création d'une note correspondant au type cliqué
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
    *\brief Rend le bouton sauver cliquable
    */
    void activateSave();

    /**
    *\brief Ajoute une nouvelle relation dans RelationsManager
    */
    void saveNewRelation();

    /**
    *\brief Met à jour et enregistre une relation existante
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
    *\brief Charge l'ensemble des versions d'une note
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

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

#include "notesmanager.h"
//#include "trasheditor.h"
namespace Ui {
class MainWindow;
}
class FormNote;

class typeNote;


class MainWindow : public QMainWindow{
    Q_OBJECT
    NotesManager* manager;
    FormNote* formnote;

    Trash *trash;

    typeNote* type;


public:
    explicit MainWindow(NotesManager *m,Trash* t, QWidget *parent = 0);
    ~MainWindow();
    void loadActiveNotes();
    void unloadActiveNotes();
    void refresh();
    void unloadTrashedNotes();
    void loadTrashedNotes();
    void restoreNote();
    void deleteNote();



private slots:
    void on_activenotes_itemClicked(QListWidgetItem *item);

    void on_createNote_clicked();


    void on_trashedNotes_itemClicked(QListWidgetItem *item);


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


public:
    explicit FormNote(MainWindow* mwind, NotesManager* m, unsigned int id, QWidget *parent = 0);
    ~FormNote();

public slots:
    void activateButtons();
    void disableButtons();
    void saveNote();
    void PutToTrash();

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


#endif // MAINWINDOW_H

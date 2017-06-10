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


    void loadTrashedNotes();



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
    void activerSave();
    void saveNote();
    void deleteNote();

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

public:
    explicit typeNote(NotesManager* m, QWidget *parent = 0);
    ~typeNote();
    void loadTypes();
    void on_validate_clicked();

private:
    Ui::typeNote *ui;
};


#endif // MAINWINDOW_H

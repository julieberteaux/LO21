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

class MainWindow : public QMainWindow{
    Q_OBJECT
    NotesManager* manager;
    FormNote* formnote;
public:
    explicit MainWindow(NotesManager *m, QWidget *parent = 0);
    ~MainWindow();
    void loadActiveNotes();
    void unloadActiveNotes();

    void refresh();


private slots:
    void on_activenotes_itemClicked(QListWidgetItem *item);
    void displayTrash();
    //void on_actionOpentrash_triggered();


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
    QListWidgetItem *item;
    FormVersion* version;

public:
    explicit FormNote(MainWindow* mwind, NotesManager* m, QListWidgetItem *i, QWidget *parent = 0);
    ~FormNote();

public slots:
    void activerSave();
    void saveNote();

private:
    Ui::FormNote *ui;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include "notesmanager.h"
#include "formnote.h"
#include "formversion.h"
//#include "trasheditor.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    NotesManager* manager;
    FormNote* formnote;
public:
    explicit MainWindow(NotesManager *m, QWidget *parent = 0);
    ~MainWindow();
    void loadActiveNotes();


private slots:
    void on_activenotes_itemClicked(QListWidgetItem *item);
    void displayTrash();
    //void on_actionOpentrash_triggered();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

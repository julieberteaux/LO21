#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include "notesmanager.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    NotesManager* manager;

public:
    explicit MainWindow(NotesManager *m, QWidget *parent = 0);
    ~MainWindow();
    void loadActiveNotes();

private slots:
    void on_activenotes_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

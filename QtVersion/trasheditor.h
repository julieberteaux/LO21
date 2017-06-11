#ifndef TRASHEDITOR_H
#define TRASHEDITOR_H

#include <QDialog>
#include <QListWidgetItem>
#include "trash.h"

namespace Ui {
class TrashEditor;
}

class TrashEditor : public QDialog
{
    Q_OBJECT
    Trash *trash;

public:
    explicit TrashEditor(QWidget *parent = 0);
    void loadTrashedNotes();
    ~TrashEditor();

private slots:
    void on_trashedNotes_itemClicked(QListWidgetItem *item);

private:
    Ui::TrashEditor *ui;
};

#endif // TRASHEDITOR_H


//#include <QWidget>

//#include <QListWidget>

//#include <QListWidgetItem>
//#include <QScrollArea>
//#include <QPushButton>

//class TrashEditor : public QWidget{
//    Q_OBJECT

//private:

//    QListWidget* list;
//    QVBoxLayout* lay;
//    QScrollArea* scroll;
//    QPushButton* supprimer;
//    QPushButton* vider;
//    QPushButton* restaurer;

//public:
///**
// * \brief		Constructeur de Trash, construit la fenÍtre de Trash
// */
//    TrashEditor(QWidget* parent=0);
//    QListWidget* getList(){return list;}
//    QPushButton* getSupCorbButton(){ return supprimer; }
//    QPushButton* getViderButton() { return vider; }
//    QPushButton* getRestaurer() { return restaurer; }

//public slots :
///**
// * \brief		Slot qui supprime une note de  Trash
// */
//    void deleteNote();

///**
// * \brief		Slot qui vide Trash
// */
//    void emptyTrash();

///**
// * \brief		Slot qui restaure une note
// */
//    Note* restore();

//    void activateButtons();
//};


//#endif // TRASHEDITOR_H


#ifndef FORMNOTE_H
#define FORMNOTE_H

#include <QListWidget>
#include <QWidget>
#include"notesmanager.h"
#include"formversion.h"
namespace Ui {
class FormNote;
}

class FormNote : public QWidget
{
    Q_OBJECT
    NotesManager* manager;
    QListWidgetItem *item;
    //FormVersion* version;
public:
    explicit FormNote(NotesManager* m, QListWidgetItem *i, QWidget *parent = 0);
    ~FormNote();

private:
    Ui::FormNote *ui;
};

#endif // FORMNOTE_H

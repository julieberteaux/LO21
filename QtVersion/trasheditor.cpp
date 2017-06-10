#include "trasheditor.h"
#include "ui_trasheditor.h"

TrashEditor::TrashEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrashEditor)
{
    ui->setupUi(this);
}

TrashEditor::~TrashEditor()
{
    delete ui;
}

void TrashEditor::loadTrashedNotes(){
    const std::vector<Note*>& notes=trash->getListTrashedNotes();
    for(std::vector<Note* const>::iterator it=notes.begin(); it!=notes.end(); ++it){

            QListWidgetItem *item = new QListWidgetItem((**it).getLatestNoteVersion().getTitle());
            QVariant v;
            v.setValue((**it).getIdNote());
            item->setData(Qt::UserRole, v);
            ui->trashedNotes->addItem(item);

    }
}

void TrashEditor::on_trashedNotes_itemClicked(QListWidgetItem *item)
{
    ui->save->setEnabled(true);
    ui->supp->setEnabled(true);
}



//#include "TrashEditor.h"



//void TrashEditor::deleteNote()
//{
//    if(!list->currentItem()==0){
//        QListWidgetItem* selectedItem = list->currentItem() ;
//        QString title = selectedItem->text();
//        Note* n = Trash::getInstance().getNoteViaName(title);
//        Trash::getInstance().deleteNote(n);
//        list->takeItem(list->currentRow());
//    }
//}

//void TrashEditor::emptyTrash()
//{
//    Trash::getInstance().emptyTrash();
//    list->clear();
//}

//void TrashEditor::activateButtons()
//{
//    supprimer->setEnabled(true);
//    restaurer->setEnabled(true);
//}


//Note* TrashEditor::restore()
//{
//    Note* n = 0;
//    if(!list->currentItem()==0){
//        QListWidgetItem* selectedItem = list->currentItem() ;
//        QString title = selectedItem->text();
//        n = Trash::getInstance().getNoteViaName(title);
//        Trash::getInstance().putBackNote(n);
//        list->takeItem(list->currentRow());
//    }
//    return n;

//}

//TrashEditor::TrashEditor(QWidget* parent)
//{
//    list = new QListWidget();
//    QListWidgetItem* item;
//    for(int i=0;i<Trash::getInstance().getSizeDust();i++)
//        {
//            Note* n = Trash::getInstance().getNoteByPos(i);
//            QString noteTitle = n->getTitle();
//            item = new QListWidgetItem(noteTitle,list); // ajoute l'item à la liste
//        }

//    lay=new QVBoxLayout();
//    scroll=new QScrollArea();

//    supprimer = new QPushButton("Supprimer");
//    vider = new QPushButton("Vider");
//    restaurer = new QPushButton("Restaurer");

//    supprimer->setEnabled(false);
//    restaurer->setEnabled(false);

//    QObject::connect(vider, SIGNAL(clicked()), this, SLOT(vid()));
//    QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(supp()));
//    QObject::connect(list, SIGNAL(itemSelectionChanged()), this, SLOT(activerBoutons()));

//    scroll->setWidget(list);

//    lay->addWidget(scroll);
//    lay->addWidget(restaurer);
//    lay->addWidget(supprimer);
//    lay->addWidget(vider);

//    setLayout(lay);

//}

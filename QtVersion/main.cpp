#include <QApplication>
#include <QString>
#include <QFileDialog>
//#include "plurinotes.h"
#include "notesmanager.h"
#include "relationsmanager.h"

int main(int argc, char* argv[]) {

//    QApplication app(argc, argv);
//    //QString fichier = "../TD6/notes.xml";
//    NotesManager& manager=NotesManager::getInstance();
//    QWidget fenetre;

//    //m.load();
//    Note& n=manager.getNote(0);

//    fenetre.show();
//    return app.exec();
    try{
        std::cout<<"Début du programme plurinotes"<<std::endl;
        NotesManager& manager=NotesManager::getInstance();
        Date d(10,1,12);
        //Note& n=manager.getNote(0);
<<<<<<< HEAD
        manager.addNote();//0
        manager.addNote();//1
        manager.addNote();//2
        Note& n0=manager.getNote(0);
        Note& n2=manager.getNote(1);
        //Note& n3=manager.getNote(3);
        std::cout<<"n0 id:"<<n0.getIdNote()<<std::endl;
        std::cout<<"n2 id:"<<n2.getIdNote()<<std::endl;
        std::cout<<n2.getDateCrea().getJour()<<" "<<n2.getDateCrea().getMois()<<" "<<n2.getDateCrea().getAnnee()<<std::endl;

        /*for(std::vector<Note*>::iterator it=manager.listNotes.begin(); it!=manager.listNotes.end(); ++it)
            std::cout<<(*it)->getIdNote()<<std::endl;*/
        Note& n4=manager.getNote(5);
        NoteVersion test;
=======

        //création d'une note + affichage de l'id et de la date de création
        int idn0=manager.addNote();//0
        Note& n0=manager.getNote(idn0);
        std::cout<<"n0 id:"<<n0.getIdNote()<<std::endl;
        std::cout<<n0.getDateCrea().getJour()<<" "<<n0.getDateCrea().getMois()<<" "<<n0.getDateCrea().getAnnee()<<std::endl;

        //création d'une version de la note: ici un article
        Article* temp=new Article("titre de l'article", "texte de l'article");
        int idart=n0.addNoteVersion(*temp);
        delete temp;// ne pas oublier de le supprimer tout de suite puisqu'il a été copié dans le vector de Note

        //affichage de l'article
        NoteVersion& art=n0.getNoteVersion(idart);
        Article& art2=dynamic_cast<Article&>(art);//conversion pour pouvoir utiliser les méthodes de la classe article
        std::cout<<"titre de la note: "<<art2.getTitle().toStdString()<<" texte de l'article: "<<art2.getText().toStdString()<<std::endl;

        //modification de la note=affichage de la note dans l'interface puis l'utilisateur modifie certains champs
        //lors de l'enregistrement cela créer une version du même type (Article, Image, ...). Cette version est enregistrée
        int idCopyLatestVersion=n0.copyLatestVersion();
        NoteVersion& art=n0.getNoteVersion(idCopyLatestVersion);
        Article& art2=dynamic_cast<Article&>(art);//conversion pour pouvoir utiliser les méthodes de la classe article

        /*for(std::vector<Note*>::iterator it=manager.listNotes.begin(); it!=manager.listNotes.end(); ++it)
            std::cout<<(*it)->getidNote()<<std::endl;*/
>>>>>>> 08db07038bd49af523e4e36d48bc9f3f5a05f793
        std::cout<<"fin du try plurinotes"<<std::endl;

        Relation* rReference = new Relation("Reference", "Cette relation permet de matérialiser les références qu’une note peut faire à d’autres notes grâce à une syntaxe spéciale",true);


    }
    catch(Exception& e){std::cout<<e.getInfo().toStdString()<<std::endl;}
    std::cout<<"fin du programme plurinotes"<<std::endl;

    return 0;
}

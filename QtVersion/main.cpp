#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <unistd.h>
#include <iostream>

//#include "plurinotes.h"
#include "notesmanager.h"
#include "relationsmanager.h"
#include "mainwindow.h"
#include "trash.h"

int main(int argc, char* argv[]) {
//objectif:
//chargement et sauvegarde
//on ouvre le logiciel, on charge les notes (articles pour commencer) et on les affiche


//    QApplication app(argc, argv);
//    //QString fichier = "../TD6/notes.xml";
//    NotesManager& manager=NotesManager::getInstance();
//    QWidget fenetre;

//    //m.load();
//    Note& n=manager.getNote(0);

//    fenetre.show();
//    return app.exec();
    try{
        //PARTIE 1 A NE PAS SUPPRIMER!

//       std::cout<<"Début du programme plurinotes"<<std::endl;

//        NotesManager& manager=NotesManager::getInstance();


//        // ATTENTION notes.xml est situé dans le working directory situé dans l'onglet projets/run
//        manager.setFilename("notes.xml");

//        //création d'une note + affichage de l'id et de la date de création

//        int idn0=manager.addNote();//0

//        Note& n0=manager.getNote(idn0);
////        std::cout<<"n0 id:"<<n0.getIdNote()<<std::endl;
////        std::cout<<n0.getDateCrea().getJour()<<" "<<n0.getDateCrea().getMois()<<" "<<n0.getDateCrea().getAnnee()<<std::endl;

//        //création d'une version de la note: ici un article
//        Article* temp=new Article("titre de l'article...", "texte de l'article...");
//        int idart=n0.addNoteVersion(*temp);
//        delete temp;// ne pas oublier de le supprimer tout de suite puisqu'il a été copié dans le vector de Note

//        //affichage de l'article
//        NoteVersion& art=n0.getNoteVersion(idart);
//        Article& art2=dynamic_cast<Article&>(art);//conversion pour pouvoir utiliser les méthodes de la classe article
//        std::cout<<"titre de la note: "<<art2.getTitle().toStdString()<<" texte de l'article: "<<art2.getText().toStdString()<<std::endl;

//        //modification de la note=affichage de la note dans l'interface puis l'utilisateur modifie certains champs
//        //lors de l'enregistrement cela créer une version du même type (Article, Image, ...). Cette version est enregistrée
//        int idCopyLatestVersion=n0.copyLatestVersion();
//        NoteVersion& artv2=n0.getNoteVersion(idCopyLatestVersion);
//        Article& artV2=dynamic_cast<Article&>(artv2);
//        artV2.setText("ceci est un essai");
//        std::cout<<"titre de la note: "<<artV2.getTitle().toStdString()<<" texte de l'article: "<<artV2.getText().toStdString()<<std::endl;

//        int idn1=manager.addNote();//1
//        int idn2=manager.addNote();//1
//        int idn3=manager.addNote();//1
//        Note& n1=manager.getNote(idn1);
//        Note& n2=manager.getNote(idn2);

//        Image* img=new Image("image des vacances", "c'est une image des vacances","/vacances.jpeg");
//        int idimg=n1.addNoteVersion(*img);

//        manager.save();
//        Date d=Date(1,2,2017);
//        Article* temp2=new Article("titre de l'article...", "texte de l'article...");

//        //test of load method:
//        NoteVersion* testArticle=NoteVersionFactory::createInstance("Article");
//        Article& testArticle2=dynamic_cast<Article&>(*testArticle);
//        testArticle2.setText("cedskplopkdz");


////        manager.putToTrash(idn2);

////        std::vector<Note*> notes = manager.getListNotes();



////        for(std::vector<Note*>::iterator it=notes.begin(); it!=notes.end(); ++it)
////            std::cout<<(*it)->getIdNote()<<std::endl;
////        std::cout<<std::endl;


////        Trash& trash=Trash::getInstance();
//////        trash.deleteNote(idn2);

////        std::vector<Note*> tnotes=trash.getListTrashedNotes();
////        if (tnotes.empty())
////            std::cout<<"empty"<<std::endl;
////        else std::cout<<"nope "<<tnotes.size()<<std::endl;
////        for(std::vector<Note*>::iterator it=tnotes.begin(); it!=tnotes.end(); ++it)
////            std::cout<<(*it)->getIdNote()<<std::endl;
////        trash.putBackNote(idn2);

////       trash.putBackNote(idn2);
////        manager.addExistingNote(&n2);

//        std::vector<Note*> note = manager.getListNotes();

//        std::cout<<std::endl;
//        for(std::vector<Note*>::iterator it=note.begin(); it!=note.end(); ++it)
//            std::cout<<(*it)->getIdNote()<<std::endl;

//        RelationsManager& managerR=RelationsManager::getInstance();
//       // Relation* Reference = new Relation("Reference", "Cette relation permet de matérialiser les références qu’une note peut faire à d’autres notes grâce à une syntaxe spéciale",true);
//       //Relation* theme = new Relation("Theme", "Cette relation permet de matérialiser les notes de même thème", false);
//       managerR.addRelation("Reference", "Cette relation permet de matérialiser les références qu’une note peut faire à d’autres notes grâce à une syntaxe spéciale",true);
//       managerR.addRelation("Theme", "Cette relation permet de matérialiser les notes de même thème", false);

//       std::vector<Relation*> rel = managerR.getListRelations();

//       std::cout<<std::endl;
//       for(std::vector<Relation*>::iterator it=rel.begin(); it!=rel.end(); ++it)
//           std::cout<<"R"<<std::endl; //(*it)->getTitle()
//       managerR.setFilename("relations.xml");
//       managerR.save();

        //PARTIE 2***************************************************************************************
        RelationsManager& managerR=RelationsManager::getInstance();
        NotesManager& manager2=NotesManager::getInstance();
        Trash& trash=Trash::getInstance();
        manager2.setFilename("notes.xml");
        managerR.setFilename("relations.xml");
        manager2.load();
        managerR.load();
        for(std::vector<Relation*>::const_iterator it=managerR.getListRelations().begin(); it!=managerR.getListRelations().end(); ++it){
            std::cout<<(*it)->getTitle().toStdString()<<std::endl;
        }

        QApplication app(argc, argv);
        MainWindow fenetre(&manager2,&managerR, &trash);

        fenetre.show();
        return app.exec();

    }
    catch(Exception& e){std::cout<<e.getInfo().toStdString()<<std::endl;}


    std::cout<<"fin du programme plurinotes"<<std::endl;


}

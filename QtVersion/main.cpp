#include "plurinotes.h"

int main() {
    try{
        std::cout<<"Début du programme plurinotes"<<std::endl;
        NotesManager& manager=NotesManager::getInstance();
        Date d(10,1,12);
        //Note& n=manager.getNote(0);

        //création d'une note + affichage de l'id et de la date de création
        Note& n0=manager.addNote();//0
        std::cout<<"n0 id:"<<n0.getIdNote()<<std::endl;
        std::cout<<n0.getDateCrea().getJour()<<" "<<n0.getDateCrea().getMois()<<" "<<n0.getDateCrea().getAnnee()<<std::endl;

        //création d'une version de la note: ici un article
        Article* temp=new Article("titre de l'article", "texte de l'article");
        NoteVersion& art=n0.addNoteVersion(*temp);
        delete temp;
        //NoteVersion& art0=n0.getNoteVersion(0);

        //affichage de l'article
        Article& art2=dynamic_cast<Article&>(art);
        std::cout<<"titre de la note: "<<art2.getTitle().toStdString()<<" texte de l'article: "<<art2.getText().toStdString()<<std::endl;

        //modification de la note=affichage de la note dans l'interface puis l'utilisateur modifie certains champs
        //lors de l'enregistrement cela créer une version du même type (Article, Image, ...). Cette version est enregistrée


        /*for(std::vector<Note*>::iterator it=manager.listNotes.begin(); it!=manager.listNotes.end(); ++it)
            std::cout<<(*it)->getidNote()<<std::endl;*/
        std::cout<<"fin du try plurinotes"<<std::endl;

    }
    catch(Exception& e){std::cout<<e.getInfo().toStdString()<<std::endl;}
    std::cout<<"fin du programme plurinotes"<<std::endl;

    return 0;
}

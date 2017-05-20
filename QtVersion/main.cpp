#include "plurinotes.h"

int main() {
    try{
        std::cout<<"Début du programme plurinotes"<<std::endl;
        NotesManager& manager=NotesManager::getInstance();
        Date d(10,1,12);
        //Note& n=manager.getNote(0);
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
        std::cout<<"fin du try plurinotes"<<std::endl;

        Relation* rReference = new Relation("Reference", "Cette relation permet de matérialiser les références qu’une note peut faire à d’autres notes grâce à une syntaxe spéciale",true);


    }
    catch(Exception& e){std::cout<<e.getInfo().toStdString()<<std::endl;}
    std::cout<<"fin du programme plurinotes"<<std::endl;

    return 0;
}

#include "plurinotes.h"

int main() {
    try{
        std::cout<<"Début du programme plurinotes"<<std::endl;
        NotesManager& manager=NotesManager::getInstance();
        Date d(10,1,12);
        //Note& n=manager.getNote(0);
        manager.addNote();
        manager.addNote();
        manager.addNote();
        Note& n0=manager.getNote(0);
        Note& n2=manager.getNote(1);
        //Note& n3=manager.getNote(3);
        std<<"n0 id:"<<n0.getidNote()<<std::endl;
        std<<"n2 id:"<<n0.getidNote()<<std::endl;
        std::cout<<"fin du try plurinotes"<<std::endl;

    }
    catch(Exception& e){std::cout<<e.getInfo().toStdString()<<std::endl;}
    std::cout<<"fin du programme plurinotes"<<std::endl;

    return 0;
}

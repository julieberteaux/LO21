#include "plurinotes.h"

int main() {
    try{
        std::cout<<"Début du programme plurinotes"<<std::endl;
        NotesManager& manager=NotesManager::getInstance();
        Date d(10,1,12);
        Note& n=manager.getNote(0);
        manager.addNote();
        std::cout<<"fin du try plurinotes"<<std::endl;

    }
    catch(Exception& e){std::cout<<e.getInfo().toStdString()<<std::endl;}
    std::cout<<"fin du programme plurinotes"<<std::endl;

    return 0;
}

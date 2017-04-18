#include "plurinotes.h"

int main() {
    try{

        NotesManager &n1=NotesManager::getInstance();
        Date d(10,1,12);
        //n.getNote(0);
        //n.addNote();
    }
    catch(Exception& e){std::cout<<e.getInfo().toStdString()<<std::endl;}

    return 0;
}

#include "noteversion.h"

//void addNoteVersion(unsigned int id){
//    Note& n = getNote(id);
//    NotesVersion& latestVersion = n.listVersion.back();
//    NotesVersion newVersion = latestVersion;
//    newVersion.dateEdit.today();
//    newVersion.idVersion++;
//    //cout<<
//    n.listVersion.push_back(newVersion);


//}
/********************************** Article ****************************/

Article* Article::clone(unsigned int id) const{
    Article* art=new Article(*this);
    art->idVersion=id;
    return art;
}
/********************************** Task ****************************/

Task* Task::clone(unsigned int id) const{
    Task* tsk=new Task(*this);
    tsk->idVersion=id;
    return tsk;
}
/********************************** Image ****************************/

Image* Image::clone(unsigned int id) const{
    Image* img=new Image(*this);
    img->idVersion=id;
    return img;
}
/********************************** Audio ****************************/

Audio* Audio::clone(unsigned int id) const{
    Audio* aud=new Audio(*this);
    aud->idVersion=id;
    return aud;
}

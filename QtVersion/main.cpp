#include <iostream>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include "plurinotes.h"

int main() {
    try{
        Date d(2,13,2017);
    }
    catch(Exception& e){std::cout<<e.getInfo().toStdString()<<std::endl;}
    return 0;
}

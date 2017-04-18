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


       std::vector<int> v;
       for(int i = 0; i < 20; i++)
       {
          std::cout << "capacité = " << v.capacity() << " pour une taille de " << v.size() << std::endl;
          v.push_back(1);
       }

    return 0;
}

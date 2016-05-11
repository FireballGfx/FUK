#include "mainform.h"
#include <QApplication>

#include "charakter.h"
#include "eigenschaft.h"
#include "eigenschaftexception.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm main;


    Eigenschaft *e = new Eigenschaft(KLUGHEIT,1);

    (*e)++;
    ++(*e);
    ++(*e);

    try{
        ++(*e); // nicht ok
    }catch(EigenschaftException& e){
        const char* fehler = e.what();
        int i=0;
    }




    main.show();

    delete e;
    return a.exec();
}

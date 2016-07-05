#include "mainform.h"
#include <QApplication>

#include "charakter.h"

#include "eigenschaft.h"
#include "fertigkeit.h"
#include "eigenschaftexception.h"
#include "charaktermanager.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm main;

    main.show();

    //Charakter* c = main.getCurrentChar();

    //int i = c->getAngriffsWert();


    //Overview o;
    //o.show();

    return a.exec();
}

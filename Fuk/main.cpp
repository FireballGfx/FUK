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

    CharakterManager manager;

    Charakter c("marcel");

    Fertigkeit f(STAERKE,"Heben","Gewichtheber");

    c.fertigkeitHinzufuegen(f);
    manager.insert(c);

    Charakter c2 = manager.findCharakter(c.getId());


    c2.getEigenschaft(STAERKE);
    f.setSatz("Ganz starker Gewichtheber");




    manager.update(c2);

    int count = manager.getCharaktere()->count();

    Charakter c1 = manager.getCharaktere()->find(c.getId()).value();



    main.show();

    return a.exec();
}

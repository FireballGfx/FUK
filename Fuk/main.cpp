
#include <QApplication>

#include "startlogo.h"

#include "overview.h"
#include "charaktermanager.h"
#include "charakter.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Startlogo s;
    s.show();


    /*Ptr<CharakterManager> charakterManagerPtr = Ptr<CharakterManager>(new CharakterManager());

    auto charakterManager = charakterManagerPtr.get();

    charakterManager->addCharakterBeschreibung("Name","Beschreibung, die etwas länger sein könnte. Können wir das irgendwie umbrechen? lalalallalalalalalala - Das könnte hier nicht mehr passen! lalalalalalalalalalalalalalalalala");

    auto charakter = charakterManager->getCurrentCharakter().get();
    QVector<Fertigkeit>* fertigkeiten = charakter->getFertigkeiten();



    Fertigkeit fertigkeit0 = fertigkeiten->value(0);
    fertigkeit0.setMerkmal(Merkmal::KLUGHEIT);
    fertigkeit0.setName("Test");
    fertigkeit0.setSatz("Test Satz");
    charakter->fertigkeitHinzufuegen(0,fertigkeit0);




    Overview o(NULL,charakterManagerPtr);
    o.paint(charakterManagerPtr->getCurrentCharakter());
    o.show();

    */
    return a.exec();
}






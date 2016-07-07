
#include <QApplication>

#include "startlogo.h"

#include "overview.h"
#include "charaktermanager.h"
#include "charakter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Startlogo s;
    //s.show();


    Ptr<CharakterManager> charakterManagerPtr = Ptr<CharakterManager>(new CharakterManager());

    auto charakterManager = charakterManagerPtr.get();

    charakterManager->addCharakterBeschreibung("Test","TEst");

    auto charakter = charakterManager->getCurrentCharakter().lock();
    QVector<Fertigkeit>* fertigkeiten = charakter->getFertigkeiten();
    Fertigkeit fertigkeit = fertigkeiten->value(0);

    //fertigkeit.setMerkmal(Merkmal::KLUGHEIT);
    Overview o(NULL,charakterManagerPtr);
    o.show();


    //delete charakterManager;
    return a.exec();
}

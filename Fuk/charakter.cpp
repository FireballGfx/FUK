#include "charakter.h"
#include "eigenschaft.h"


Charakter::Charakter(QString name){

    eigenschaften.resize(8);
    fertigkeiten.resize(12);

    Eigenschaft klugheit(KLUGHEIT,1);
    Eigenschaft willenskraft(WILLENSKRAFT,1);
    Eigenschaft wahrnehmung(WAHRNEHMUNG,1);
    Eigenschaft ausstrahlung(AUSSTRAHLUNG,1);
    Eigenschaft geschicklichkeit(GESCHICKLICHKEIT,1);
    Eigenschaft beweglichkeit(BEWEGLICHKEIT,1);
    Eigenschaft staerke(STAERKE,1);
    Eigenschaft widerstand(WIDERSTAND,1);

    eigenschaften[0] = klugheit;
    eigenschaften[1] = willenskraft;
    eigenschaften[2] = wahrnehmung;
    eigenschaften[3] = ausstrahlung;
    eigenschaften[4] = geschicklichkeit;
    eigenschaften[5] = beweglichkeit;
    eigenschaften[6] = staerke;
    eigenschaften[7] = widerstand;

    this->name = name;
}

Charakter::~Charakter(){
}

#include "charakter.h"
#include "eigenschaft.h"


Charakter::Charakter(QString name){

    fertigkeiten.resize(12);

    Eigenschaft klugheit(KLUGHEIT,1);
    Eigenschaft willenskraft(WILLENSKRAFT,1);
    Eigenschaft wahrnehmung(WAHRNEHMUNG,1);
    Eigenschaft ausstrahlung(AUSSTRAHLUNG,1);
    Eigenschaft geschicklichkeit(GESCHICKLICHKEIT,1);
    Eigenschaft beweglichkeit(BEWEGLICHKEIT,1);
    Eigenschaft staerke(STAERKE,1);
    Eigenschaft widerstand(WIDERSTAND,1);

    eigenschaften[KLUGHEIT] = klugheit;
    eigenschaften[WILLENSKRAFT] = willenskraft;
    eigenschaften[WAHRNEHMUNG] = wahrnehmung;
    eigenschaften[AUSSTRAHLUNG] = ausstrahlung;
    eigenschaften[GESCHICKLICHKEIT] = geschicklichkeit;
    eigenschaften[BEWEGLICHKEIT] = beweglichkeit;
    eigenschaften[STAERKE] = staerke;
    eigenschaften[WIDERSTAND] = widerstand;

    this->name = name;
}

Charakter::~Charakter(){
}

Eigenschaft& Charakter::getEigenschaft(Merkmal merkmal){

}

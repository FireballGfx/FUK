#include "charakter.h"
#include "eigenschaft.h"
#include "eigenschaftexception.h"
#include <QDebug>

Charakter::Charakter(QString name, QString beschreibung){

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
    this->beschreibung = beschreibung;
}

Charakter::~Charakter(){
}

Eigenschaft& Charakter::getEigenschaft(Merkmal merkmal){
    return eigenschaften.find(merkmal).value();
}


void Charakter::fertigkeitHinzufuegen(int index, Fertigkeit fertigkeit){
    QMap<Merkmal, Eigenschaft>::iterator it = eigenschaften.find(fertigkeit.getMerkmal());

    if(it != eigenschaften.end()){
        Eigenschaft* e =  &(*it);

        Fertigkeit tmp = fertigkeiten.value(index); // wurde diese Position schon einmal gesetzt?
        if(tmp.getName().size() > 0){
            fertigkeiten.erase(fertigkeiten.begin() + index);
            Merkmal merkmal = tmp.getMerkmal();
            QMap<Merkmal, Eigenschaft>::iterator it2 = eigenschaften.find(merkmal);
            Eigenschaft* tmpEigenschaft =  &(*it2);
            tmpEigenschaft->operator --();
        }

        e->operator ++();

        fertigkeiten.insert(index,fertigkeit);
    }
}

bool Charakter::checkHinzufuegen(int index, Fertigkeit f){
    Eigenschaft eigenschaft = getEigenschaft(f.getMerkmal());

    Fertigkeit tmp = fertigkeiten.value(index);

    if(tmp.getMerkmal() == eigenschaft.getMerkmal()){
        return true;
    }

    if(eigenschaft.getWert() == 5){
        return false;
    }else{
        return true;
    }
}

QVector<Fertigkeit>* Charakter::getFertigkeiten(){
    return &fertigkeiten;
}

void Charakter::setId(int id){
    this->id = id;
}

int Charakter::getId(){
    return id;
}

QString Charakter::getBeschreibung(){
    return beschreibung;
}

int Charakter::getAngriffsWert(){
    Eigenschaft st = getEigenschaft(Merkmal::STAERKE);
    Eigenschaft be = getEigenschaft(Merkmal::BEWEGLICHKEIT);
    int wert = st.getWert() + be.getWert();

    return wert;
}

int Charakter::getFernkampf(){
    Eigenschaft wa = getEigenschaft(Merkmal::WAHRNEHMUNG);
    Eigenschaft ge = getEigenschaft(Merkmal::GESCHICKLICHKEIT);

    int wert = wa.getWert() + ge.getWert();
    return wert;
}

int Charakter::getZauberwert(){
    Eigenschaft wk = getEigenschaft(Merkmal::WILLENSKRAFT);
    Eigenschaft kl = getEigenschaft(Merkmal::KLUGHEIT);

    int wert = wk.getWert() + kl.getWert();
    return wert;
}

int Charakter::getVerteidigungswert(){
    Eigenschaft wi = getEigenschaft(Merkmal::WIDERSTAND);
    Eigenschaft be = getEigenschaft(Merkmal::BEWEGLICHKEIT);

    int wert = wi.getWert() + be.getWert();
    return wert;
}

int Charakter::getGesundheit(){
    Eigenschaft wi = getEigenschaft(Merkmal::WIDERSTAND);
    int wert = 20 + wi.getWert();
    return wert;
}

QString Charakter::getName(){
    return name;
}

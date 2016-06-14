#include "charakter.h"
#include "eigenschaft.h"
#include "eigenschaftexception.h"
#include <QDebug>

Charakter::Charakter(QString name, QString beschreibung){

   // fertigkeiten.resize(11);

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


void Charakter::fertigkeitHinzufuegen(Fertigkeit fertigkeit){
    QMap<Merkmal, Eigenschaft>::iterator it = eigenschaften.find(fertigkeit.getMerkmal());

    if(it != eigenschaften.end()){
        Eigenschaft* e =  &(*it);
        e->operator ++(); // löst eine Exception aus, wenn der Wert von 4 überschritten wird.
        fertigkeiten.append(fertigkeit);
    }
}

bool Charakter::checkHinzufuegen(Fertigkeit f){
    Eigenschaft eigenschaft = getEigenschaft(f.getMerkmal());

    if(eigenschaft.getWert() == 4){
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

QString Charakter::getName(){
    return name;
}

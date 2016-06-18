#include "charakter.h"
#include "eigenschaft.h"
#include "eigenschaftexception.h"
#include <QDebug>

Charakter::Charakter(QString name, QString beschreibung){

    Eigenschaft klugheit(KLUGHEIT,0);
    Eigenschaft willenskraft(WILLENSKRAFT,0);
    Eigenschaft wahrnehmung(WAHRNEHMUNG,0);
    Eigenschaft ausstrahlung(AUSSTRAHLUNG,0);
    Eigenschaft geschicklichkeit(GESCHICKLICHKEIT,0);
    Eigenschaft beweglichkeit(BEWEGLICHKEIT,0);
    Eigenschaft staerke(STAERKE,0);
    Eigenschaft widerstand(WIDERSTAND,0);

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
        e->operator ++(); // löst eine Exception aus, wenn der Wert von 4 überschritten wird.
        fertigkeiten.insert(index,fertigkeit);
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

QString Charakter::validate(){

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

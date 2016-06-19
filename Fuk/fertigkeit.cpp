#include "fertigkeit.h"

Fertigkeit::Fertigkeit(Merkmal merkmal, QString name, QString satz)
    :merkmal(merkmal),name(name),satz(satz){
}

Fertigkeit::Fertigkeit(const Fertigkeit& fertigkeit)
    :merkmal(fertigkeit.merkmal),name(fertigkeit.name), satz(fertigkeit.satz){
}

QString Fertigkeit::getName() const{
    return name;
}

QString Fertigkeit::getSatz() const{
    return satz;
}

void Fertigkeit::setName(const QString name){
    this->name = name;
}

void Fertigkeit::setSatz(const QString satz){
    this->satz = satz;
}

Merkmal Fertigkeit::getMerkmal(){
    return merkmal;
}

void Fertigkeit::setMerkmal(const Merkmal merkmal){
    this->merkmal = merkmal;
}

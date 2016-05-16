#include "fertigkeit.h"

Fertigkeit::Fertigkeit(Eigenschaft& eigenschaft, QString name, QString satz)
    :eigenschaft(eigenschaft),name(name),satz(satz){

    eigenschaft++;
}

QString Fertigkeit::getName() const{
    return name;
}

QString Fertigkeit::getSatz() const{
    return satz;
}

Eigenschaft& Fertigkeit::getEigenschaft() const{
    return eigenschaft;
}

void Fertigkeit::setEigenschaft(const Eigenschaft& eigenschaft){
    this->eigenschaft = eigenschaft;
}

void Fertigkeit::setName(const QString name){
    this->name = name;
}

void Fertigkeit::setSatz(const QString satz){
    this->satz = satz;
}

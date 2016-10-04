#include "eigenschaft.h"
#include "eigenschaftexception.h"

Eigenschaft::Eigenschaft(){
    wert = 0;
}

Eigenschaft::Eigenschaft(Merkmal merkmal, int wert){
    if(wert < 1 || wert >5){
        throw EigenschaftException("Ungueltiger Wertebereich.");
    }
    this->merkmal = merkmal;
    this->wert = wert;
}

Eigenschaft::Eigenschaft(const Eigenschaft& eigenschaft)
    :merkmal(eigenschaft.merkmal),wert(eigenschaft.wert){
}


Merkmal& Eigenschaft::getMerkmal(){
    return merkmal;
}

int& Eigenschaft::getWert(){
    return wert;
}

void Eigenschaft::operator++(){
    ++wert;
}

void Eigenschaft::operator++(int){
    ++wert;
}

void Eigenschaft::operator--(){
    --wert;
}

void Eigenschaft::operator--(int){
    --wert;
}



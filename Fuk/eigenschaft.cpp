#include "eigenschaft.h"
#include "eigenschaftexception.h"

Eigenschaft::Eigenschaft(){
    wert = 1;
}

Eigenschaft::Eigenschaft(Merkmal merkmal, int wert){
    if(wert < 1 || wert >4){
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
    if(wert == 4){
        throw EigenschaftException("Ungueltiger Wertebereich.");
    }
    ++wert;
}

void Eigenschaft::operator++(int){
    if(wert == 4){
        throw EigenschaftException("Ungueltiger Wertebereich.");
    }
    ++wert;
}

void Eigenschaft::operator--(){
    if(wert == 1){
        throw EigenschaftException("Ungueltiger Wertebereich.");
    }
    --wert;
}

void Eigenschaft::operator--(int){
    if(wert == 1){
        throw EigenschaftException("Ungueltiger Wertebereich.");
    }
    --wert;
}



#include "charakter.h"
#include "eigenschaft.h"


Charakter::Charakter(){
    eigenschaften[0] = new Eigenschaft("KL","Klugheit");
    eigenschaften[1] = new Eigenschaft("WK","Willenskraft");
    eigenschaften[2] = new Eigenschaft("WA","Wahrnehmung");
    eigenschaften[3] = new Eigenschaft("AU","Ausstrahlung");
    eigenschaften[4] = new Eigenschaft("GE","Geschicklichkeit");
    eigenschaften[5] = new Eigenschaft("BE","Beweglichkeit");
    eigenschaften[6] = new Eigenschaft("ST","Stärke");
    eigenschaften[7] = new Eigenschaft("WI","Widerstand");
}

Charakter::~Charakter(){

    for(int i=0; i < 8 ; i++){
        delete eigenschaften[i];
    }
    delete[] eigenschaften;
}

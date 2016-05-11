#include "charakter.h"
#include "eigenschaft.h"


Charakter::Charakter(){

}

Charakter::~Charakter(){

    for(int i=0; i < 8 ; i++){
        delete eigenschaften[i];
    }
    delete[] eigenschaften;
}

#ifndef EIGENSCHAFT_H
#define EIGENSCHAFT_H

#include "merkmal.h"


class Eigenschaft
{
private:
    Merkmal merkmal;
    int wert;

public:
    Eigenschaft(Merkmal merkmal, int wert);
    Eigenschaft();
    Eigenschaft(const Eigenschaft& eigenschaft);

    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);

    Merkmal& getMerkmal();
    int& getWert();

};

#endif // EIGENSCHAFT_H

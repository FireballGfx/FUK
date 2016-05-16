#ifndef EIGENSCHAFT_H
#define EIGENSCHAFT_H

#include "merkmal.h"


class Eigenschaft
{
private:
    Merkmal merkmal;
    int wert; // 1 - 4

public:
    Eigenschaft(Merkmal merkmal, int wert); // das mit dem Wert noch einmal überdenken
    Eigenschaft();
    Eigenschaft(const Eigenschaft &eigenschaft);

    // operatoren
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);

    // function
    Merkmal& getMerkmal();
    int& getWert();

};

#endif // EIGENSCHAFT_H

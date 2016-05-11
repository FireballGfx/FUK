#ifndef EIGENSCHAFT_H
#define EIGENSCHAFT_H

enum Merkmal{
    KLUGHEIT,
    WILLENSKRAFT,
    WAHRNEHMUNG,
    AUSSTRAHLUNG,
    GESCHICKLICHKEIT,
    BEWEGLICHKEIT,
    STAERKE,
    WIDERSTAND
};


class Eigenschaft
{
private:
    Merkmal merkmal;
    int wert; // 1 - 4

public:
    Eigenschaft(Merkmal merkmal, int wert);
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

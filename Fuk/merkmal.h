#ifndef MERKMAN_H
#define MERKMAN_H

enum Merkmal{
    KLUGHEIT = 0,
    WILLENSKRAFT = 1,
    WAHRNEHMUNG = 2,
    AUSSTRAHLUNG = 3,
    GESCHICKLICHKEIT = 4,
    BEWEGLICHKEIT = 5,
    STAERKE = 6,
    WIDERSTAND = 7,
    SIZE_OF_ENUM
};

static const char* MerkmalNamen[]={"KLUGHEIT","WILLENSKRAFT",
                                   "WAHRNEHMUNG","AUSSTRAHLUNG",
                                   "GESCHICKLICHKEIT","BEWEGLICHKEIT",
                                   "STAERKE","WIDERSTAND"};

static_assert(sizeof(MerkmalNamen)/sizeof(char*) == SIZE_OF_ENUM
    , "sizes dont match");

#endif // MERKMAN_H

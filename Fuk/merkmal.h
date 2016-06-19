#ifndef MERKMAN_H
#define MERKMAN_H

enum Merkmal{
    KLUGHEIT = 0,
    WILLENSKRAFT,
    WAHRNEHMUNG,
    AUSSTRAHLUNG,
    GESCHICKLICHKEIT,
    BEWEGLICHKEIT,
    STAERKE,
    WIDERSTAND,
    SIZE_OF_ENUM,
    NULL_VALUE // Zustand undefiniert.
};

static const char* MerkmalNamen[]={"KLUGHEIT","WILLENSKRAFT",
                                   "WAHRNEHMUNG","AUSSTRAHLUNG",
                                   "GESCHICKLICHKEIT","BEWEGLICHKEIT",
                                   "STAERKE","WIDERSTAND"};

static_assert(sizeof(MerkmalNamen)/sizeof(char*) == SIZE_OF_ENUM
    , "sizes dont match");

#endif // MERKMAN_H

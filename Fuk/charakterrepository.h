#ifndef CHARAKTERREPOSITORY_H
#define CHARAKTERREPOSITORY_H

#include <QHash>

#include "charakter.h"

class CharakterRepository
{
public:
    CharakterRepository();

    void deleteCharakter(Charakter* charakter);
    void saveCharakter(Charakter* charakter);
    void saveAllCharakters(QHash<int,Charakter>* charaktere);
    void readCharakter(int key, Charakter* charakter);
    void readAllCharakters(QHash<int,Charakter>* charaktere);
    void readCharakterIndex(QHash<int, QString>* charakterIndex);

};

#endif // CHARAKTERREPOSITORY_H

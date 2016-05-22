#ifndef CHARAKTERMANAGER_H
#define CHARAKTERMANAGER_H

#include <QHash>

#include "charakter.h"

class CharakterManager
{
public:
    CharakterManager();

    void insert(Charakter& charakter);
    void update(Charakter& charakter);
    void drop(Charakter& charakter);
    void commit(); // muss noch

    QHash<int,Charakter>* getCharaktere();
    Charakter& findCharakter(int key);
private:
    QHash<int,Charakter> charaktere;


private:
    int getNewKey();
};

#endif // CHARAKTERMANAGER_H

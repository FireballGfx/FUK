#ifndef CHARAKTERMANAGER_H
#define CHARAKTERMANAGER_H

#include <QHash>

class Charakter;

class CharakterManager
{
public:
    CharakterManager();

    void add(Charakter& charakter);
    void update(Charakter& charakter);
    void drop(Charakter& charakter);

    QHash<int,Charakter>* getCharaktere();

private:
    QHash<int,Charakter> charaktere;


private:
    int getNewKey();
};

#endif // CHARAKTERMANAGER_H

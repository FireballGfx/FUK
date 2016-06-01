#ifndef CHARAKTERMANAGER_H
#define CHARAKTERMANAGER_H

#include <QHash>

#include "charakter.h"
#include "charakterrepository.h"

class CharakterManager
{
public:
    CharakterManager();
    ~CharakterManager();

    void insert(Charakter& charakter);
    void update(Charakter& charakter);
    void remove(Charakter& charakter);
    QHash<int,Charakter>* read();
    QHash<int,Charakter>* getCharaktere();
    Charakter& findCharakter(int key);
    void addCharakterBeschreibung(QString name, QString beschreibung);
    void deleteCurrentCharakter();

private:
    QHash<int,Charakter> charaktere;
    CharakterRepository charakterRepository;

    // Der aktuelle Held den der User bearbeitet oder betrachtet
    Charakter* currentCharakter;

private:
    int getNewKey();
};

#endif // CHARAKTERMANAGER_H

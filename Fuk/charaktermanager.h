#ifndef CHARAKTERMANAGER_H
#define CHARAKTERMANAGER_H

#include <QHash>

#include "charakter.h"

#include "charakterrepository.h";

class CharakterManager
{
public:
    CharakterManager();

    // fügt einen Charakter dem Manager hinzu und
    // speichert ihn direkt über das Repository.
    void insert(Charakter& charakter);
    // aktualisiert einen Charakter im Manager und
    // speichert die Änderung direkt über das Repository.
    void update(Charakter& charakter);

    // löscht einen Charakter im Manager und
    // Repository
    void remove(Charakter& charakter);

    // liest alle bisher gespeicherten Chraktäre.
    QHash<int,Charakter>* read();

    QHash<int,Charakter>* getCharaktere();
    Charakter& findCharakter(int key);
private:
    QHash<int,Charakter> charaktere;
    CharakterRepository charakterRepository;

private:
    int getNewKey();
};

#endif // CHARAKTERMANAGER_H

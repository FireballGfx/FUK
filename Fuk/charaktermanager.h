#ifndef CHARAKTERMANAGER_H
#define CHARAKTERMANAGER_H

#include <QHash>

#include "global.h"
#include "charakter.h"
#include "charakterrepository.h"

class CharakterManager
{
public:
    CharakterManager();
    ~CharakterManager();

    void select(int key);
    void insert(Charakter& charakter);
    void update(Charakter& charakter);
    void remove(Charakter& charakter);
    QHash<int,Charakter>* read();
    QHash<int,Charakter>* getCharaktere();
    Charakter& findCharakter(int key);
    void addCharakterBeschreibung(QString name, QString beschreibung);
    void saveCharakterToFile();
    WeakPtr<Charakter> getCurrentCharakter();



private:
    QHash<int,Charakter> charaktere;
    CharakterRepository charakterRepository;

    // Der aktuelle Held den der User bearbeitet oder betrachtet
    Ptr<Charakter> currentCharakter;

private:
    int getNewKey();

    void loadCharakterFromFile();

};

#endif // CHARAKTERMANAGER_H

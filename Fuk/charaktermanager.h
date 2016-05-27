#ifndef CHARAKTERMANAGER_H
#define CHARAKTERMANAGER_H

#include <QHash>

#include "charakter.h"
#include "charakterrepository.h"

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

    // gibt alle Charaktere in einer Hash zurück
    QHash<int,Charakter>* getCharaktere();

    // sucht einen Charakter anhand eines Schlüssels
    Charakter& findCharakter(int key);

    // fügt dem Chrakter im Generierungs Flow den Namen und
    // eine Beschreibung hinzu
    void addCharakterBeschreibung(QString name, QString beschreibung);

private:
    QHash<int,Charakter> charaktere;
    CharakterRepository charakterRepository;

    // Der aktuelle Held den der User bearbeitet oder betrachtet
    Charakter* currentCharakter;

private:
    int getNewKey();
};

#endif // CHARAKTERMANAGER_H

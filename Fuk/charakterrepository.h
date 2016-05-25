#ifndef CHARAKTERREPOSITORY_H
#define CHARAKTERREPOSITORY_H

#include <QHash>

#include "charakter.h"

class CharakterRepository
{
public:
    CharakterRepository();

    // löscht einen Charakter aus dem File
    void deleteCharakter(Charakter* charakter);

    // speichert einen Charakter in das File
    void saveCharakter(Charakter* charakter);

    // speichert alle Charaktere in das File
    void saveAllCharakters(QHash<int,Charakter>* charaktere);

    // liest einen Charakter anhand der Id
    void readCharakter(int key, Charakter* charakter);

    // liest alle Charaktete in den Speicher
    void readAllCharakters(QHash<int,Charakter>* charaktere);

    // liest nur die Id und den Namen aus dem File
    // so sparen wir Speicherplatz.
    void readCharakterIndex(QHash<int, QString>* charakterIndex);

};

#endif // CHARAKTERREPOSITORY_H

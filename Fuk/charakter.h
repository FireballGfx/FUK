#ifndef CHARAKTER_H
#define CHARAKTER_H

#include <QLinkedList>
#include <QString>
#include <QVector>

#include <QLinkedList>
#include <QMap>

#include "eigenschaft.h"
#include "fertigkeit.h"

class Charakter
{

private:
    int id;
    QString name;
    QMap<Merkmal, Eigenschaft> eigenschaften;
    QVector<Fertigkeit> fertigkeiten;



public:

    Charakter(QString name);
    ~Charakter();

    QVector<Fertigkeit>* getFertigkeiten();
    // Fügt dem Charakter eine neue Fertigkeit hinzu.
    // Wenn das hinzufügen nicht möglich sein sollte,
    // dann wirft die Methode eine exception.
    void fertigkeitHinzufuegen(Fertigkeit fertigkeit);

    // Prueft ob ein hinzufügen möglich ist.
    // True im positiven Fall.
    bool checkHinzufuegen(Fertigkeit f);

    // Gibt die Eigenschaft zum Merkmal zurück
    Eigenschaft& getEigenschaft(Merkmal merkmal);

    void setId(int id);
    int getId();
};

#endif // CHARAKTER_H

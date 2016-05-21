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
    QString name;
    QMap<Merkmal, Eigenschaft> eigenschaften;
    QVector<Fertigkeit> fertigkeiten;

public:

    Charakter(QString name);
    ~Charakter();

    // Gibt die Eigenschaft zum Merkmal zurück
    Eigenschaft& getEigenschaft(Merkmal merkmal);

    // Fügt dem Charakter eine neue Fertigkeit hinzu.
    void fertigkeitHinzufuegen(Fertigkeit fertigkeit);
};

#endif // CHARAKTER_H

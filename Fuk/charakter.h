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
    QString beschreibung;
    QMap<Merkmal, Eigenschaft> eigenschaften;
    QVector<Fertigkeit> fertigkeiten;

public:

    Charakter(QString name, QString beschreibung);
    ~Charakter();

    QVector<Fertigkeit>* getFertigkeiten();
    void fertigkeitHinzufuegen(int index, Fertigkeit fertigkeit);
    bool checkHinzufuegen(int index, Fertigkeit f);
    Eigenschaft& getEigenschaft(Merkmal merkmal);
    void setId(int id);
    int getId();

    QString getName();
    QString getBeschreibung();

    // abgleitete Werte
    int getAngriffsWert();
    int getFernkampf();
    int getZauberwert();
    int getVerteidigungswert();
    int getGesundheit();

};

#endif // CHARAKTER_H

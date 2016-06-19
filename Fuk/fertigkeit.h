#ifndef FERTIGKEIT_H
#define FERTIGKEIT_H

#include <QString>
#include "eigenschaft.h"

class Fertigkeit
{
private:
    //Eigenschaft &eigenschaft;
    Merkmal merkmal;
    QString name;
    QString satz; // Begründender Satz zu der Fertigkeit





public:
    //Fertigkeit(Eigenschaft &eigenschaft, QString name, QString satz);
    Fertigkeit(Merkmal merkmal, QString name, QString satz);
    Fertigkeit(){ merkmal = Merkmal::NULL_VALUE;}
    Fertigkeit(const Fertigkeit& fertigkeit);

    QString getName() const;
    QString getSatz() const;
    Merkmal getMerkmal();

    void setName(const QString name);
    void setSatz(const QString satz);

    void setMerkmal(const Merkmal merkmal);

};

#endif // FERTIGKEIT_H

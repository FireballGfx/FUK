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
    Fertigkeit(){}
    Fertigkeit(const Fertigkeit& fertigkeit);

    QString getName() const;
    QString getSatz() const;
    //Eigenschaft& getEigenschaft() const;
    Merkmal getMerkmal();

    void setName(const QString name);
    void setSatz(const QString satz);
    //void setEigenschaft(const Eigenschaft& eigenschaft);
    void setMerkmal(const Merkmal merkmal);

};

#endif // FERTIGKEIT_H

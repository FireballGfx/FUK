#ifndef FERTIGKEIT_H
#define FERTIGKEIT_H

#include <QString>
#include "eigenschaft.h"

class Fertigkeit
{
private:
    Eigenschaft &eigenschaft;
    QString name;
    QString satz; // Begründender Satz zu der Fertigkeit
public:
    Fertigkeit(Eigenschaft &eigenschaft, QString name, QString satz);

    QString getName() const;
    QString getSatz() const;
    Eigenschaft& getEigenschaft() const;

    void setName(const QString name);
    void setSatz(const QString satz);
    void setEigenschaft(const Eigenschaft& eigenschaft);

};

#endif // FERTIGKEIT_H

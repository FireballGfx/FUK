#ifndef EIGENSCHAFT_H
#define EIGENSCHAFT_H

#include <QObject>
#include <QString>

class Eigenschaft
{
private:
    QString bezeichnung;
    QString kurzBezeichnung;
public:
    Eigenschaft(QString kurzBezeichnung, QString bezeichnung);
    Eigenschaft();
};

#endif // EIGENSCHAFT_H

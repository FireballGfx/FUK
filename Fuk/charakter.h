#ifndef CHARAKTER_H
#define CHARAKTER_H

#include <QLinkedList>
#include <QString>

class Eigenschaft;

class Charakter
{

private:
    QString name;
    Eigenschaft* eigenschaften[8]; // Todo hier besser QVector benutzen.

public:

    Charakter();
    ~Charakter();
};

#endif // CHARAKTER_H

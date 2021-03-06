#ifndef BESCHREIBUNGDOCUMENTITEM_H
#define BESCHREIBUNGDOCUMENTITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include "basedocumentitem.h"

#include "charaktermanager.h"


class BeschreibungDocumentItem : public BaseDocumentItem
{
protected:
    Ptr<Charakter> charakter;

public:
    explicit BeschreibungDocumentItem(int x, int y, int width, int heigth,Ptr<Charakter> charakter);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BESCHREIBUNGDOCUMENTITEM_H


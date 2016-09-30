#ifndef FERTIGKEITDOCUMENTITEM_H
#define FERTIGKEITDOCUMENTITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include "beschreibungdocumentitem.h"
#include "charaktermanager.h"

class FertigkeitDocumentItem : public BeschreibungDocumentItem
{
public:
    FertigkeitDocumentItem(int x, int y, int width, int heigth, Ptr<Charakter> charakter);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // FERTIGKEITDOCUMENTITEM_H

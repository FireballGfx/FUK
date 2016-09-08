#ifndef EIGENSCHAFTENDOCUMENTITEM_H
#define EIGENSCHAFTENDOCUMENTITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include "beschreibungdocumentitem.h"
#include "charaktermanager.h"

class EigenschaftenDocumentItem : public BeschreibungDocumentItem
{
private:
    Ptr<Charakter> charakter;

public:
    EigenschaftenDocumentItem(int x, int y, int width, int heigth,
                              Ptr<Charakter>& charakter);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EIGENSCHAFTENDOCUMENTITEM_H

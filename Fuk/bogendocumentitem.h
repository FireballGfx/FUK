#ifndef BOGENDOCUMENTITEM_H
#define BOGENDOCUMENTITEM_H


#include "basedocumentitem.h"


class BogenDocumentItem : public BaseDocumentItem
{
public:
    explicit BogenDocumentItem(int x, int y, int width, int heigth);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BOGENDOCUMENTITEM_H

#ifndef HEADLINEDOCUMENTITEM_H
#define HEADLINEDOCUMENTITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include "basedocumentitem.h"

class HeadLineDocumentItem : public BaseDocumentItem
{
private:
    QString headline;

public:
    HeadLineDocumentItem(int x, int y, int width, int heigth, QString headline);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};

#endif // HEADLINEDOCUMENTITEM_H

#ifndef BASEDOCUMENTITEM_H
#define BASEDOCUMENTITEM_H

#include <QPainter>
#include <QGraphicsItem>

class BaseDocumentItem : public QGraphicsItem
{

protected:
    int x;
    int y;
    int width;
    int heigth;

public:
    explicit BaseDocumentItem(int x, int y, int width, int heigth);
    QRectF boundingRect() const;

};

#endif // BASEDOCUMENTITEM_H

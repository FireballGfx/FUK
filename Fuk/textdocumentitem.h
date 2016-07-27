#ifndef BESCHREIBUNGDOCUMENTITEM_H
#define BESCHREIBUNGDOCUMENTITEM_H

#include <QPainter>
#include <QGraphicsItem>
class TextDocumentItem : public QGraphicsItem
{

private:
    int x;
    int y;
    int width;
    int heigth;

    QString text;

public:
    TextDocumentItem(int x, int y, int width, int heigth, QString text);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    // keine Events
};

#endif // BESCHREIBUNGDOCUMENTITEM_H

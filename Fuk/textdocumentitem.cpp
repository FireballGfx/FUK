#include "textdocumentitem.h"

TextDocumentItem::TextDocumentItem(int x, int y, int width, int heigth, QString text)
    :x(x),y(y),width(width), heigth(heigth),text(text){
}

QRectF TextDocumentItem::boundingRect() const
{
    return QRectF(x,y,width,heigth);
}

void TextDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    painter->drawText(rect,Qt::TextWordWrap, text);

}

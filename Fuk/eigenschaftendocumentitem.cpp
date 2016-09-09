#include "eigenschaftendocumentitem.h"



EigenschaftenDocumentItem::EigenschaftenDocumentItem(int x, int y, int width, int heigth,
                                                     Ptr<Charakter> charakter)
    : BeschreibungDocumentItem(x,y,width,heigth,charakter){
}

void EigenschaftenDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Charakter* ch = charakter.get();
    QRectF rect = boundingRect();

    int x = rect.x();
    int y = rect.y();
    int width = rect.width();
    int heigth = rect.height();


    Eigenschaft eigenschaftKl = ch->getEigenschaft(KLUGHEIT);


    QRectF klugheitRect(x,y+30,width,heigth);
    painter->drawText(klugheitRect,Qt::TextWordWrap, "" + eigenschaftKl.getWert());


    QVector<Fertigkeit>* fertigkeiten = ch->getFertigkeiten();

    painter->drawRect(boundingRect());
}

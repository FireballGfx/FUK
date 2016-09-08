#include "eigenschaftendocumentitem.h"



EigenschaftenDocumentItem::EigenschaftenDocumentItem(int x, int y, int width, int heigth,
                                                     Ptr<Charakter> charakter)
    : BeschreibungDocumentItem(x,y,width,heigth,std::move(charakter)){

}

void EigenschaftenDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Charakter* ch = charakter.get();
    QRectF rect = boundingRect();

  //  Eigenschaft klugheit = ch->getEigenschaft(KLUGHEIT);


    QVector<Fertigkeit>* fertigkeiten = ch->getFertigkeiten();

    painter->drawRect(boundingRect());
}

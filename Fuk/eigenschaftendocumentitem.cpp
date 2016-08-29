#include "eigenschaftendocumentitem.h"



EigenschaftenDocumentItem::EigenschaftenDocumentItem(int x, int y, int width, int heigth,
                                                     WeakPtr<Charakter> charakter)
    : BeschreibungDocumentItem(x,y,width,heigth,charakter){

}

void EigenschaftenDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Charakter* ch = charakter.lock().get();
    QRectF rect = boundingRect();


    painter->drawRect(boundingRect());
}

#include "beschreibungdocumentitem.h"


BeschreibungDocumentItem::BeschreibungDocumentItem(int x, int y, int width, int heigth, WeakPtr<Charakter> charakter): BaseDocumentItem(x,y,width,heigth),charakter(charakter){

}

void BeschreibungDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Charakter* ch = charakter.lock().get();


    painter->drawText(boundingRect(),Qt::TextWordWrap, "Beschreibung deines Charakters:");

    painter->setPen(QPen(Qt::black));
    painter->drawRect(boundingRect());
}

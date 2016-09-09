#include "beschreibungdocumentitem.h"


BeschreibungDocumentItem::BeschreibungDocumentItem(int x, int y, int width, int heigth, Ptr<Charakter> charakter): BaseDocumentItem(x,y,width,heigth),charakter(std::move(charakter)){
    int i=0;
}

void BeschreibungDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Charakter* ch = charakter.get();
    QRectF rect = boundingRect();

    int x = rect.x();
    int y = rect.y();
    int width = rect.width();
    int heigth = rect.height();


    QFont font = painter->font();

    QFont boldFont = painter->font();
    boldFont.setBold(true);
    painter->setFont(boldFont);
    painter->drawText(boundingRect(),Qt::TextWordWrap, "Beschreibung deines Charakters");
    painter->setFont(font);
    QRectF name(x,y+15,width,heigth);
    QRectF beschreibung(x,y+30,width,heigth);
    painter->drawText(name,Qt::TextWordWrap, "Name: " + ch->getName());
    painter->drawText(beschreibung,Qt::TextWordWrap, ch->getBeschreibung());

    painter->setPen(QPen(Qt::black));
    painter->drawRect(boundingRect());
}

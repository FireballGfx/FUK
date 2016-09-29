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

    painter->setFont(QFont("times",32));

    QFont font = painter->font();


    QFont boldFont = painter->font();
    boldFont.setBold(true);
    painter->setFont(boldFont);
    painter->drawText(boundingRect(),Qt::TextWordWrap, "Beschreibung deines Charakters");
    painter->setFont(font);

    QRectF beschreibung(x,y+50,width,heigth);

    painter->drawText(beschreibung,Qt::TextWordWrap, ch->getBeschreibung());

   // painter->setPen(QPen(Qt::black));
   // painter->drawRect(boundingRect());
}

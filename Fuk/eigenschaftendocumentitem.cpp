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


    QRectF kl(x,y+15,width,heigth);
    QRectF wk(x,y+30,width,heigth);

    QFont font = painter->font();

    QFont boldFont = painter->font();
    boldFont.setBold(true);
    painter->setFont(boldFont);
    painter->drawText(boundingRect(),Qt::TextWordWrap, "Eigenschaften");
    painter->setFont(font);


    int ikl = ch->getEigenschaft(KLUGHEIT).getWert();
    QString klString = QString("Klugheit [KL]");

    int iwk = ch->getEigenschaft(WILLENSKRAFT).getWert();
    QString wkString = QString("Willenskraft [WK]");

    painter->drawText(kl,Qt::TextWordWrap, klString);
    painter->drawText(wk,Qt::TextWordWrap, wkString);

    QBrush brush(Qt::green);
    QBrush saveBrush = painter->brush();
    painter->setBrush(brush);
    painter->drawEllipse(x+90,y+20,5,5);
    painter->drawEllipse(x+90,y+35,5,5);
    painter->setBrush(saveBrush);
    painter->setPen(QPen(Qt::black));
    painter->drawRect(boundingRect());

}

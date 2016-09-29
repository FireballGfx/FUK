#include "headlinedocumentitem.h"

HeadLineDocumentItem::HeadLineDocumentItem(int x, int y, int width, int heigth, QString headline,Ptr<Charakter> charakter) : BaseDocumentItem(x,y,width,heigth), headline(headline),charakter(std::move(charakter)){
}

void HeadLineDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setFont(QFont("times",32));

    QString text = headline + "\n" +
                   "Name: " + charakter->getName();

    painter->drawText(boundingRect(),Qt::TextWordWrap,text);

    //painter->setPen(QPen(Qt::black));
    //painter->drawRect(boundingRect());
}

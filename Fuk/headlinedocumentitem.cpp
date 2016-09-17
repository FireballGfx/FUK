#include "headlinedocumentitem.h"

HeadLineDocumentItem::HeadLineDocumentItem(int x, int y, int width, int heigth, QString headline) : BaseDocumentItem(x,y,width,heigth), headline(headline){
}

void HeadLineDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setFont(QFont("times",22));

    painter->drawText(boundingRect(),Qt::TextWordWrap, headline);

    painter->setPen(QPen(Qt::black));
    painter->drawRect(boundingRect());
}

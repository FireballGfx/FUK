#include "bogendocumentitem.h"


BogenDocumentItem::BogenDocumentItem(int x, int y, int width, int heigth): BaseDocumentItem(x,y,width,heigth){

}

void BogenDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap bogen(":/data/image/Charakterbogen.png");
    QRectF rect = boundingRect();
    painter->drawPixmap(rect.x(),rect.y(),rect.width(),rect.height(),bogen);
}

#include "basedocumentitem.h"

BaseDocumentItem::BaseDocumentItem(int x, int y, int width, int heigth): x(x),y(y),width(width),heigth(heigth){
}

QRectF BaseDocumentItem::boundingRect() const{
    return QRectF(x,y,width, heigth);
}

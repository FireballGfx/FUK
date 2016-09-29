#ifndef HEADLINEDOCUMENTITEM_H
#define HEADLINEDOCUMENTITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include "basedocumentitem.h"
#include "charaktermanager.h"

class HeadLineDocumentItem : public BaseDocumentItem
{
private:
    QString headline;
    Ptr<Charakter> charakter;

public:
    explicit HeadLineDocumentItem(int x, int y, int width, int heigth, QString headline, Ptr<Charakter> charakter);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};

#endif // HEADLINEDOCUMENTITEM_H

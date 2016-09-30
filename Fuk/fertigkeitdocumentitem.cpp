#include "fertigkeitdocumentitem.h"

FertigkeitDocumentItem::FertigkeitDocumentItem(int x, int y, int width, int heigth,
                                               Ptr<Charakter> charakter): BeschreibungDocumentItem(x,y,width,heigth,charakter){

}


void FertigkeitDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    painter->setFont(QFont("times",30));
    int px = 2; // dicke der Linie

    int tmpHeightName = 107;
    int tmpWidthName = 543;

    int tmpHeightMerkmal = 107;
    int tmpWidthMerkmal = 107;

    int tmpHeightSatz = 107;
    int tmpWidthSatz = 871;


    int xCurrent = x;
    int yCurrent = y;

    int half = 107 / 4;

    QVector<Fertigkeit>* vector = charakter->getFertigkeiten();

    QVectorIterator<Fertigkeit> it(*vector);

    while(it.hasNext()){

        Fertigkeit fertigkeit = it.next();
        QString strMerkmal = MerkmalNamen[fertigkeit.getMerkmal()];
        strMerkmal = strMerkmal.mid(0,2);
        QString satz = fertigkeit.getSatz();
        QString name = fertigkeit.getName();

        QRectF fertigkeitRectName(xCurrent,yCurrent + half,tmpWidthName,tmpHeightName);
        painter->drawText(fertigkeitRectName,Qt::TextWordWrap, name);

        int xCurrentMerkmal = xCurrent + px + tmpWidthName;
        QRectF fertigkeitRectMerkmal( xCurrentMerkmal + half,yCurrent + half,tmpWidthMerkmal,tmpHeightMerkmal);
        painter->drawText(fertigkeitRectMerkmal,Qt::TextWordWrap, strMerkmal);

        int xCurrentSatz = xCurrentMerkmal + px + tmpWidthMerkmal;

        QRectF fertigkeitRectSatz( xCurrentSatz,yCurrent + half,tmpWidthSatz,tmpHeightSatz);
        painter->drawText(fertigkeitRectSatz,Qt::TextWordWrap, satz);

        xCurrent = xCurrent + px + tmpHeightName;
        yCurrent = yCurrent + px + tmpWidthName;
    }
}

/*

QFont boldFont = painter->font();
boldFont.setBold(true);
painter->setFont(boldFont);
painter->drawText(boundingRect(),Qt::TextWordWrap, "Beschreibung deines Charakters");
painter->setFont(font);

QRectF beschreibung(x,y+50,width,heigth);

painter->drawText(beschreibung,Qt::TextWordWrap, ch->getBeschreibung());
*/

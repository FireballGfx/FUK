#include "eigenschaftendocumentitem.h"



EigenschaftenDocumentItem::EigenschaftenDocumentItem(int x, int y, int width, int heigth,
                                                     Ptr<Charakter> charakter)
    : BeschreibungDocumentItem(x,y,width,heigth,charakter){
}

void EigenschaftenDocumentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    painter->setFont(QFont("times",30));
    int px = 2; // dicke der Linie

    int tmpHeight = 107;
    int tmpWidth = 107;

    int half = tmpHeight / 4;

    int xKL = x + tmpWidth + px;
    int yKL = y;

    int xWA = xKL;
    int yWA = y + tmpHeight + px;

    int xWK = xKL;
    int yWK = yWA + tmpHeight + px;

    int xAU = xKL;
    int yAU = yWK + tmpHeight + px;

    //---

    int xGE = 1418 + tmpWidth + px; // Zahl kommt von Photoshop
    int yGE = y;

    int xBE = xGE;
    int yBE = y + tmpHeight + px;

    int xST = xGE;
    int yST = yBE + tmpHeight + px;

    int xWI = xGE;
    int yWI = yST + tmpHeight + px;

    //--

    int xGH = 1200;
    int yGH = 828;

    int xZA = 1528;
    int yZA = 828;

    QRectF kl(xKL + half ,yKL + half,tmpWidth,tmpHeight);
    QRectF wa(xWA + half ,yWA + half,tmpWidth,tmpHeight);
    QRectF wk(xWK + half ,yWK + half,tmpWidth,tmpHeight);
    QRectF au(xAU + half ,yAU + half,tmpWidth,tmpHeight);

    QRectF ge(xGE + half ,yGE + half,tmpWidth,tmpHeight);
    QRectF be(xBE + half ,yBE + half,tmpWidth,tmpHeight);
    QRectF st(xST + half ,yST + half,tmpWidth,tmpHeight);
    QRectF wi(xWI + half ,yWI + half,tmpWidth,tmpHeight);

    QRectF gh(xGH + half ,yGH + half,tmpWidth,tmpHeight);
    QRectF za(xZA + half ,yZA + half,tmpWidth,tmpHeight);

    painter->drawText(kl,Qt::TextWordWrap, QString::number(charakter->getEigenschaft(Merkmal::KLUGHEIT).getWert()));
    painter->drawText(wa,Qt::TextWordWrap, QString::number(charakter->getEigenschaft(Merkmal::WAHRNEHMUNG).getWert()));
    painter->drawText(wk,Qt::TextWordWrap, QString::number(charakter->getEigenschaft(Merkmal::WILLENSKRAFT).getWert()));
    painter->drawText(au,Qt::TextWordWrap, QString::number(charakter->getEigenschaft(Merkmal::AUSSTRAHLUNG).getWert()));

    painter->drawText(ge,Qt::TextWordWrap, QString::number(charakter->getEigenschaft(Merkmal::GESCHICKLICHKEIT).getWert()));
    painter->drawText(be,Qt::TextWordWrap, QString::number(charakter->getEigenschaft(Merkmal::BEWEGLICHKEIT).getWert()));
    painter->drawText(st,Qt::TextWordWrap, QString::number(charakter->getEigenschaft(Merkmal::STAERKE).getWert()));
    painter->drawText(wi,Qt::TextWordWrap, QString::number(charakter->getEigenschaft(Merkmal::WIDERSTAND).getWert()));

    painter->drawText(gh,Qt::TextWordWrap, QString::number(charakter->getGesundheit()));
    painter->drawText(za,Qt::TextWordWrap, QString::number(charakter->getZauberwert()));


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

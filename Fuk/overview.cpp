#include "overview.h"
#include "ui_overview.h"
#include "global.h"
#include "bogendocumentitem.h"
#include "beschreibungdocumentitem.h"
#include "headlinedocumentitem.h"
#include "eigenschaftendocumentitem.h"


#include <QMessageBox>
#include <QGraphicsEllipseItem>
#include <QPrintDialog>
#include <QPrinter>
#include <QString>


Overview::Overview(QWidget *parent,Ptr<CharakterManager> charakterManager) :
    QDialog(parent),charakterManager(charakterManager),
    ui(new Ui::Overview)
{
    ui->setupUi(this);


    ui->graphicsView->setSceneRect(QRectF()); // ätzend geht aber nicht anders

    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    connect(ui->verwerfenButton,SIGNAL(clicked()),this,SLOT(verwerfen()));
    connect(ui->druckenButton,SIGNAL(clicked()),this,SLOT(drucken()));

}


void Overview::paint(Ptr<Charakter> charakter){

    BogenDocumentItem* bogen = new BogenDocumentItem(0,0,1748,2480);

    HeadLineDocumentItem* headline = new HeadLineDocumentItem(112,281,869,107, tr("Charakterdokument - ") + Constants::version,charakter);

    BeschreibungDocumentItem* beschreibungDocumentItem = new BeschreibungDocumentItem(112,499,868,436,charakter);

    EigenschaftenDocumentItem* eigenschaftenDocumentItem = new EigenschaftenDocumentItem(1090,281,554,645,charakter);

    scene->addItem(bogen);
    scene->addItem(headline);
    scene->addItem(beschreibungDocumentItem);
    scene->addItem(eigenschaftenDocumentItem);


}


void Overview::drucken(){
    QPrinter printer;
    if (QPrintDialog(&printer).exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        painter.setRenderHint(QPainter::Antialiasing);
        scene->render(&painter);
    }
}

Overview::~Overview()
{
    delete ui;
}


void Overview::verwerfen(){
    int result = QMessageBox::question(this,tr("Sicher?"),tr("Sind sie sich sicher, dass sie die Generierung abbrechen wollen?"),QMessageBox::Cancel | QMessageBox::Ok);

    if(result == QMessageBox::Ok){
        this->close();
    }
}

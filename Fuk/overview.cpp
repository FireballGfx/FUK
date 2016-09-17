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

    int x = 10;
    int y = 10;

    HeadLineDocumentItem* item = new HeadLineDocumentItem(x,y,600,200, tr("FUK Charakterdokument - ") + Constants::version);

    y+= 15;

    BeschreibungDocumentItem* beschreibungDocumentItem = new BeschreibungDocumentItem(x,y,600,60,charakter);

    y+= 60;

    EigenschaftenDocumentItem* eigenschaftenDocumentItem = new EigenschaftenDocumentItem(x,y,600,80,charakter);


    scene->addItem(bogen);
    scene->addItem(item);
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

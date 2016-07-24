#include "overview.h"
#include "ui_overview.h"
#include "global.h"

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


void Overview::paint(WeakPtr<Charakter> charakter){
    Charakter* ch = charakter.lock().get();

    QGraphicsSimpleTextItem* headLine = new QGraphicsSimpleTextItem(tr("FUK Charakterdokument - ") + Constants::version);

    QFont helvetica("Helvetica");
    headLine->setFont(helvetica);

    QGraphicsSimpleTextItem* nameWert = new QGraphicsSimpleTextItem("Name: " + ch->getName());
    QGraphicsSimpleTextItem* beschreibungWert = new QGraphicsSimpleTextItem("Beschreibung: " + ch->getBeschreibung());
    QGraphicsSimpleTextItem* angriffsWert = new QGraphicsSimpleTextItem("Angriffswert: " + QString::number(ch->getAngriffsWert()));

    int x = 10;
    int y = 10;


    headLine->setPos(x,y);
    nameWert->setPos(x,y + 20);
    beschreibungWert->setPos(x,y + 30);
    angriffsWert->setPos(x,y + 40);


    //scene->addText()

    scene->addItem(headLine);
    scene->addItem(nameWert);
    scene->addItem(beschreibungWert);
    scene->addItem(angriffsWert);





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

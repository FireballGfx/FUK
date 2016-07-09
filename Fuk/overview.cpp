#include "overview.h"
#include "ui_overview.h"
#include "glob.h"

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



    scene = new QGraphicsScene(QRect(0,0,300,800));



    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignBottom);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    //ui->graphicsView->scrollBarWidgets(Qt::AlignBottom);

    connect(ui->verwerfenButton,SIGNAL(clicked()),this,SLOT(verwerfen()));
    connect(ui->druckenButton,SIGNAL(clicked()),this,SLOT(drucken()));
}


void Overview::paint(WeakPtr<Charakter> charakter){
    Charakter* ch = charakter.lock().get();


    QGraphicsSimpleTextItem* headLine = new QGraphicsSimpleTextItem(tr("FUK Charakterdokument - ") + Constants::version);
    QFont helvetica("Helvetica");
    headLine->setFont(helvetica);
    QGraphicsSimpleTextItem* nameWert = new QGraphicsSimpleTextItem("Name: " + ch->getName());
    QGraphicsSimpleTextItem* angriffsWert = new QGraphicsSimpleTextItem("Angriffswert: " + QString::number(ch->getAngriffsWert()));
    headLine->setPos(10,5);
    nameWert->setPos(10,25);
    angriffsWert->setPos(10,40);



    scene->addItem(headLine);
    scene->addItem(nameWert);
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

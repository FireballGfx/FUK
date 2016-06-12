#include "fertigkeitform.h"
#include "merkmal.h"
#include "charakter.h"
#include "ui_fertigkeitform.h"


FertigkeitForm::FertigkeitForm(QDialog *parent, Ptr<CharakterManager> charakterManager) :
    QDialog(parent),charakterManager(charakterManager),step(1),index(0),
    ui(new Ui::FertigkeitForm)
{

    ui->setupUi(this);
    ui->zurueckButton->setEnabled(false);

    for(int i = KLUGHEIT; i != SIZE_OF_ENUM; i++){
        Merkmal merkmal = static_cast<Merkmal>(i);
        ui->comboEigenschaft->addItem(MerkmalNamen[merkmal]);
    }

    connect(ui->abbrechenButton,SIGNAL(clicked()),this,SLOT(onPushButtonAbbrechenClicked()));
    connect(ui->weiterButton,SIGNAL(clicked()),this,SLOT(naechsterSchritt()));
    connect(ui->zurueckButton,SIGNAL(clicked()),this,SLOT(zurueckSchritt()));
}

FertigkeitForm::~FertigkeitForm()
{
    delete ui;
}

void FertigkeitForm::onPushButtonAbbrechenClicked()
{
    index = 0;
    step = 1;
    ui->progressBar->setValue(step);
    ui->lineBeschreibung->clear();
    ui->lineName->clear();

    // todo nachfragen
    this->close();

    emit beenden();
}



void FertigkeitForm::zurueckSchritt()
{

    if(index != MIN_INDEX){
        index--;
    }

    if(step != MIN_STEP){
        step--;
    }


    auto charakter = charakterManager->getCurrentCharakter().lock();
    QVector<Fertigkeit>* fertigkeiten = charakter->getFertigkeiten();

    if(step != MAX_STEP){
        ui->weiterButton->setText("weiter >");
    }

    // todo auslagern in eine andere Methode
    if(step == MIN_STEP){
        ui->zurueckButton->setEnabled(false);
    }else if(!ui->zurueckButton->isEnabled()){
        ui->zurueckButton->setEnabled(true);
    }
    ui->progressBar->setValue(step);

    QString satz = fertigkeiten[index].data()->getSatz();
    QString name = fertigkeiten[index].data()->getName();

    ui->lineBeschreibung->setText(satz);
    ui->lineName->setText(name);


    emit ui->progressBar->valueChanged(step);



}

void FertigkeitForm::naechsterSchritt()
{


    if(step == MAX_STEP){
        this->close();
        emit beenden();
    }

    // todo auslagern in eine andere Methode
    if(step == MIN_STEP){
        ui->zurueckButton->setEnabled(false);
    }else if(!ui->zurueckButton->isEnabled()){
        ui->zurueckButton->setEnabled(true);
    }

    // todo auslagern in signal und slot
    if(step == MAX_STEP - 1){
        ui->weiterButton->setText("abschließen");
    }else{
        if(ui->weiterButton->text() == "abschließen"){
            ui->weiterButton->setText("weiter >");
        }
    }


    auto charakter = charakterManager->getCurrentCharakter().lock();

    QVector<Fertigkeit>* fertigkeiten = charakter->getFertigkeiten();

    QString lineName = ui->lineName->text();
    QString lineBeschreibung = ui->lineBeschreibung->text();
    Merkmal merkmal = static_cast<Merkmal>(ui->comboEigenschaft->currentIndex());

    Fertigkeit fertigkeit;
    fertigkeit.setName(lineName);
    fertigkeit.setSatz(lineBeschreibung);
    fertigkeit.setMerkmal(merkmal);
    fertigkeiten->insert(index,fertigkeit);


    ++step;
    ++index;
    ui->progressBar->setValue(step);

    ui->lineBeschreibung->setText("");
    ui->lineName->setText("");

    emit ui->progressBar->valueChanged(step);
}

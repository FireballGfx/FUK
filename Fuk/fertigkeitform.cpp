#include "fertigkeitform.h"
#include "merkmal.h"
#include "charakter.h"
#include "ui_fertigkeitform.h"
#include <QMessageBox>


FertigkeitForm::FertigkeitForm(QDialog *parent, Ptr<CharakterManager> charakterManager) :
    QDialog(parent),charakterManager(charakterManager),step(1),index(0),
    ui(new Ui::FertigkeitForm)
{

    ui->setupUi(this);
    ui->zurueckButton->setEnabled(false);

    reset();

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
    // todo validation

    index--;
    step--;

    handleButtons();

    auto charakter = charakterManager->getCurrentCharakter().lock();
    QVector<Fertigkeit>* fertigkeiten = charakter->getFertigkeiten();

    ui->progressBar->setValue(step);

    QString satz = fertigkeiten[index].data()->getSatz();
    QString name = fertigkeiten[index].data()->getName();

    ui->lineBeschreibung->setText(satz);
    ui->lineName->setText(name);


    emit ui->progressBar->valueChanged(step);



}

void FertigkeitForm::naechsterSchritt(){

    // todo validation


    if(step == MAX_STEP){

        int result = QMessageBox::question(this,tr("Sicher?"),tr("Sind sie sich sicher, dass sie die Generierung abschließen wollen?"),QMessageBox::Cancel | QMessageBox::Ok);

        if(result == QMessageBox::Ok){

            // todo store charakter
            this->close();
            emit beenden();
        }else{
            return;
        }

    }

    ++step;
    ++index; // Fehler

    handleButtons();

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

    ui->progressBar->setValue(step);
    ui->lineBeschreibung->setText("");
    ui->lineName->setText("");

    emit ui->progressBar->valueChanged(step);
}


void FertigkeitForm::handleButtons(){
    if(step == MIN_STEP){
        ui->zurueckButton->setEnabled(false);
    }
    if(step == MIN_STEP + 1){
        ui->zurueckButton->setEnabled(true);
    }

    if(step == MAX_STEP){
        ui->weiterButton->setText("abschließen");
    }else{
        if(ui->weiterButton->text() == "abschließen"){
            ui->weiterButton->setText("weiter >");
        }
    }

    if(step != MAX_STEP){
        ui->weiterButton->setText("weiter >");
    }
}

void FertigkeitForm::reset(){
    step = MIN_STEP;
    index = MIN_INDEX;
    ui->progressBar->setValue(step);
    emit ui->progressBar->valueChanged(step);
}

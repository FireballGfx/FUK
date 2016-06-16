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
    int result = QMessageBox::question(this,tr("Sicher?"),tr("Sind sie sich sicher, dass sie die Generierung abbrechen wollen?"),QMessageBox::Cancel | QMessageBox::Ok);

    if(result == QMessageBox::Ok){
        reset();
        this->close();
        emit abbrechen();
    }
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

    QString satz = "";
    QString name = "";

    Fertigkeit fertigkeit;


    fertigkeit = fertigkeiten->value(index);



    satz = fertigkeit.getSatz();
    name = fertigkeit.getName();


    ui->lineBeschreibung->setText(satz);
    ui->lineName->setText(name);
    ui->comboEigenschaft->setCurrentIndex(fertigkeit.getMerkmal());


    emit ui->progressBar->valueChanged(step);
}

void FertigkeitForm::naechsterSchritt(){

    // Auslesen der GUI
    QString lineName = ui->lineName->text();
    QString lineBeschreibung = ui->lineBeschreibung->text();
    Merkmal merkmal = static_cast<Merkmal>(ui->comboEigenschaft->currentIndex());

    auto charakter = charakterManager->getCurrentCharakter().lock();
    QVector<Fertigkeit>* fertigkeiten = charakter->getFertigkeiten();

    if(step == MAX_STEP){

        int result = QMessageBox::question(this,tr("Sicher?"),tr("Sind sie sich sicher, dass sie die Generierung abschließen wollen?"),QMessageBox::Cancel | QMessageBox::Ok);

        if(result == QMessageBox::Ok){

            reset();
            this->close();

            emit abschliessen();
        }else{
            return;
        }
    }

    Fertigkeit fertigkeit = fertigkeiten->value(index);
    fertigkeit.setName(lineName);
    fertigkeit.setSatz(lineBeschreibung);
    fertigkeit.setMerkmal(merkmal);

    if(!charakter->checkHinzufuegen(fertigkeit)){
        QMessageBox::warning(this,tr("Nein nein das kann ich nicht zulassen!"),tr("Sie haben bereits 4 Fertigkeiten mit der selben Eigenschaft zugewiesen."),QMessageBox::Ok);
        return;
    }

    //fertigkeiten->insert(index,fertigkeit);
    charakter->fertigkeitHinzufuegen(fertigkeit);


    ++step;
    ++index; // Fehler

    ui->progressBar->setValue(step);

    fertigkeit = fertigkeiten->value(index);

    ui->lineName->setText(fertigkeit.getName());
    ui->lineBeschreibung->setText(fertigkeit.getSatz());
    ui->comboEigenschaft->setCurrentIndex(fertigkeit.getMerkmal());

    handleButtons();

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

    ui->lineBeschreibung->clear();
    ui->lineName->clear();
    ui->progressBar->setValue(step);
    handleButtons();
    emit ui->progressBar->valueChanged(step);
}

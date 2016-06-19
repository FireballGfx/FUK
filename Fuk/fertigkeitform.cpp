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


bool FertigkeitForm::validateForm(){

    QString lineName = ui->lineName->text();
    QString lineBeschreibung = ui->lineBeschreibung->text();

    if(lineName.isEmpty() || lineBeschreibung.isEmpty()){
        QMessageBox::warning(this,tr("Nein nein das kann ich nicht zulassen!"),tr("Bitte füllen sie alle freien Felder aus!"),QMessageBox::Ok);

        return false;
    }

    return true;
}

void FertigkeitForm::naechsterSchritt(){
    auto charakter = charakterManager->getCurrentCharakter().lock();
    QVector<Fertigkeit>* fertigkeiten = charakter->getFertigkeiten();
    Fertigkeit fertigkeit = fertigkeiten->value(index);
    int comboBoxIndex = static_cast<int>(ui->comboEigenschaft->currentIndex());
    Merkmal merkmal = static_cast<Merkmal>(comboBoxIndex);


    // nichts hinzufügen, wenn nichts in den Feldern steht.
    if(validateForm()){
        fertigkeit.setName(ui->lineName->text());
        fertigkeit.setSatz(ui->lineBeschreibung->text());
        fertigkeit.setMerkmal(merkmal);


        if(!charakter->checkHinzufuegen(index,fertigkeit)){
            QMessageBox::warning(this,tr("Nein nein das kann ich nicht zulassen!"),tr("Sie haben bereits 4 Fertigkeiten mit der selben Eigenschaft zugewiesen."),QMessageBox::Ok);
            return;
        }else{
            charakter->fertigkeitHinzufuegen(index,fertigkeit);
        }

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

        // den nächsten Schritt vorbereiten
        ++step;
        ++index;

        ui->progressBar->setValue(step);

        fertigkeit = fertigkeiten->value(index);

        ui->lineName->setText(fertigkeit.getName());
        ui->lineBeschreibung->setText(fertigkeit.getSatz());

        if(fertigkeit.getMerkmal() != Merkmal::NULL_VALUE){
            comboBoxIndex = static_cast<int>(fertigkeit.getMerkmal());
        }

        ui->comboEigenschaft->setCurrentIndex(comboBoxIndex);

        // Schaltefläche einstellen
        handleButtons();

        emit ui->progressBar->valueChanged(step);
    }
}


void FertigkeitForm::zurueckSchritt()
{
    --index;
    --step;

    handleButtons();

    auto charakter = charakterManager->getCurrentCharakter().lock();
    QVector<Fertigkeit>* fertigkeiten = charakter->getFertigkeiten();

    Fertigkeit fertigkeit = fertigkeiten->value(index);
    QString satz = fertigkeit.getSatz();
    QString name = fertigkeit.getName();
    int comboBoxIndex = static_cast<int>(fertigkeit.getMerkmal());

    ui->progressBar->setValue(step);

    ui->lineBeschreibung->setText(satz);
    ui->lineName->setText(name);
    ui->comboEigenschaft->setCurrentIndex(comboBoxIndex);


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
    ui->comboEigenschaft->setCurrentIndex(0);
    handleButtons();
    emit ui->progressBar->valueChanged(step);
}

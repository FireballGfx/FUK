#include "fertigkeitform.h"
#include "merkmal.h"
#include "charakter.h"
#include "ui_fertigkeitform.h"


FertigkeitForm::FertigkeitForm(QDialog *parent, Ptr<CharakterManager> charakterManager) :
    QDialog(parent),charakterManager(charakterManager),step(1),
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
    step = 1;
    ui->progressBar->setValue(1);
    ui->lineBeschreibung->clear();
    ui->lineName->clear();

    // todo nachfragen
    this->close();
}



void FertigkeitForm::zurueckSchritt()
{

    step--;
    ui->progressBar->setValue(step);
    emit ui->progressBar->valueChanged(step);
}

void FertigkeitForm::naechsterSchritt()
{
    step++;


    // todo auslagern in eine andere Methode
    if(step == 1){
        ui->zurueckButton->setEnabled(false);
    }else if(!ui->zurueckButton->isEnabled()){
        ui->zurueckButton->setEnabled(true);
    }


    // todo auslagern in signal und slot
    if(step == 12){
        ui->weiterButton->setText("abschließen");
    }else{
        if(ui->weiterButton->text() == "abschließen"){
            ui->weiterButton->setText("weiter");
        }
    }


    ui->progressBar->setValue(step);


    auto charakter = charakterManager->getCurrentCharakter().lock();

    QString beschreibung = charakter->getBeschreibung();

    QVector<Fertigkeit>* fertigkeiten = charakter->getFertigkeiten();


    emit ui->progressBar->valueChanged(step);
}

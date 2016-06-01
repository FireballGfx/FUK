#include "fertigkeitform.h"

#include "ui_fertigkeitform.h"


FertigkeitForm::FertigkeitForm(QDialog *parent, Ptr<CharakterManager> charakterManager) :
    QDialog(parent),charakterManager(charakterManager),step(1),
    ui(new Ui::FertigkeitForm)
{
    ui->setupUi(this);
    connect(ui->abbrechenButton,SIGNAL(clicked()),this,SLOT(onPushButtonAbbrechenClicked()));
    connect(ui->weiterButton,SIGNAL(clicked()),this,SLOT(naechsterSchritt()));
}

FertigkeitForm::~FertigkeitForm()
{
    delete ui;
}

void FertigkeitForm::onPushButtonAbbrechenClicked()
{
    // todo nachfragen
    this->close();
}

void FertigkeitForm::on_pushButtonAbbrechen_clicked()
{
    // todo alles löschen
}

void FertigkeitForm::on_pushButtonZurueck_clicked()
{

}

void FertigkeitForm::naechsterSchritt()
{
    step++;
    ui->progressBar->setValue(step);
    emit ui->progressBar->valueChanged(step);
}

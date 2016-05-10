#include "fertigkeitform.h"

#include "ui_fertigkeitform.h"

FertigkeitForm::FertigkeitForm(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::FertigkeitForm)
{
    ui->setupUi(this);

    connect(ui->pushButtonAbbrechen,SIGNAL(clicked()),this,SLOT(onPushButtonAbbrechenClicked()));
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

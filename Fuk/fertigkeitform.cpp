#include "fertigkeitform.h"

#include "ui_fertigkeitform.h"

FertigkeitForm::FertigkeitForm(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::FertigkeitForm)
{
    ui->setupUi(this);
}

FertigkeitForm::~FertigkeitForm()
{
    delete ui;
}

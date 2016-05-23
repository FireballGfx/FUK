#include "charakterform.h"
#include "fertigkeitform.h"
#include "ui_charakterform.h"

CharakterForm::CharakterForm(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::charakterform)
{
    ui->setupUi(this);


    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(startGenerierung()));

    fertigkeitForm = new FertigkeitForm();
    fertigkeitForm->setModal(true);


}

CharakterForm::~CharakterForm()
{
    delete fertigkeitForm;
    delete ui;
}


void CharakterForm::startGenerierung(){

    QString name = ui->lineEditField->text();

    fertigkeitForm->show();
}

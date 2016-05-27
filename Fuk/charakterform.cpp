#include "charakterform.h"
#include "fertigkeitform.h"
#include "ui_charakterform.h"

CharakterForm::CharakterForm(QDialog *parent, CharakterManager* charakterManager) :
    QDialog(parent),charakterManager(charakterManager),
    ui(new Ui::charakterform)
{
    ui->setupUi(this);


    connect(ui->weiterButton,SIGNAL(clicked()),this,SLOT(startGenerierung()));

    fertigkeitForm = new FertigkeitForm(this,charakterManager);
    fertigkeitForm->setModal(true);


}

CharakterForm::~CharakterForm()
{
    delete fertigkeitForm;
    delete ui;
}


void CharakterForm::startGenerierung(){

    QString name = ui->lineEditName->text();
    QString beschreibung = ui->labelBeschreibung->text();

    charakterManager->addCharakterBeschreibung(name,beschreibung);

    fertigkeitForm->show();
}

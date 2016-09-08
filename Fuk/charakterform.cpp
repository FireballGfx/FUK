#include <QMessageBox>
#include "charakterform.h"
#include "fertigkeitform.h"
#include "ui_charakterform.h"
#include "ui_fertigkeitform.h"

CharakterForm::CharakterForm(QDialog *parent, std::shared_ptr<CharakterManager> charakterManager) :
    QDialog(parent),charakterManager(charakterManager),
    ui(new Ui::charakterform){
    ui->setupUi(this);

    fertigkeitForm = Ptr<FertigkeitForm>(new FertigkeitForm(this,charakterManager));
    fertigkeitForm->setModal(true);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    connect(ui->weiterButton,SIGNAL(clicked()),this,SLOT(startGenerierung()));
    connect(ui->abbrechenButton,SIGNAL(clicked()),this,SLOT(abbrechenGenerierung()));
    connect(fertigkeitForm->ui->abbrechenButton,SIGNAL(clicked()),this,SLOT(abbrechenGenerierung()));
    connect(fertigkeitForm.get(),SIGNAL(abschliessen()),this,SLOT(abschliessenGenerierung()));
    connect(fertigkeitForm.get(),SIGNAL(abbrechen()),this,SLOT(abbrechenGenerierung()));
}

CharakterForm::~CharakterForm(){
    delete ui;
}


void CharakterForm::startGenerierung(){
    QString name = ui->lineEditName->text();
    QString beschreibung = ui->textEditBeschreibung->toPlainText();

    if(name == NULL || name.trimmed().size() == 0){
        QMessageBox::warning(this,tr("Pflichtfeld nicht gesetzt."),tr("Bitte geben sie einen Namen für ihren Chrakter an."),QMessageBox::Ok);
    }else{
        charakterManager->addCharakterBeschreibung(name,beschreibung);
        this->close();
        fertigkeitForm->reset();
        fertigkeitForm->show();
    }
}

void CharakterForm::abschliessenGenerierung(){
    charakterManager->insert(*(charakterManager->getCurrentCharakter().get()));
    charakterManager->saveCharakterToFile();
    resetForm();
    emit beenden();
}

void CharakterForm::abbrechenGenerierung(){
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }

    foreach(QTextEdit *widget, this->findChildren<QTextEdit*>()) {
        widget->clear();
    }
    this->close();
}

void CharakterForm::resetForm(){
    ui->lineEditName->clear();
    ui->textEditBeschreibung->clear();
}

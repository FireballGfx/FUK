#include <iostream>
#include "mainform.h"
#include "ui_mainform.h"
#include "credits.h"

#include "charakterform.h"
#include "overview.h"


MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    this->setFixedSize(325, 66);

    charakterManager= Ptr<CharakterManager>(new CharakterManager());
    charakterForm = Ptr<CharakterForm>(new CharakterForm(0,charakterManager));
    creditsForm = Ptr<Credits>(new Credits(0));
    overviewForm = Ptr<Overview>(new Overview(0,charakterManager));

    creditsForm->setModal(true);
    charakterForm->setModal(true);
    overviewForm->setModal(true);

    connect(ui->erstellenButton,SIGNAL(clicked()),this,SLOT(erstellenButtonClicked()));
    connect(charakterForm.get(),SIGNAL(beenden()),this,SLOT(druckenDialog()));
    connect(ui->questionButton,SIGNAL(clicked()),this,SLOT(showCredits()));

}

MainForm::~MainForm(){
    delete ui;
}

void MainForm::erstellenButtonClicked(){
    charakterForm->show();
}

void MainForm::druckenDialog(){
    overviewForm->paint(charakterManager->getCurrentCharakter()); // TODO: vielliecht nicht nötig, weil der Chraktermanager bereits in der Klasse bekannt ist.
    overviewForm->show();
}

void MainForm::showCredits(){
    this->hide();

    creditsForm->show();


    this->show();
}

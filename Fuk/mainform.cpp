#include <iostream>
#include "mainform.h"
#include "ui_mainform.h"
#include "charakterform.h"



MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    // init

    charakterManager= Ptr<CharakterManager>(new CharakterManager());
    charakterForm = Ptr<CharakterForm>(new CharakterForm(0,charakterManager));

    charakterForm->setModal(true);
    loadCharakters();


   // QStringList items;
   // items << "Test";
   // ui->heldenListWidget->addItems(items);

    // connectors
    connect(ui->erstellenButton,SIGNAL(clicked()),this,SLOT(erstellenButtonClicked()));
    connect(charakterForm.get(),SIGNAL(beenden()),this,SLOT(aktualisieren()));

}

MainForm::~MainForm()
{
    //delete charakterManager;
    //delete charakterForm;
    delete ui;
}

void MainForm::erstellenButtonClicked()
{
    charakterForm->show();
}

void MainForm::clickedOnHinzufuegen(const QModelIndex &index)
{

}

void MainForm::aktualisieren(){
    ui->heldenListWidget->clear();

    QHash<int, Charakter>* charaktaere = charakterManager->getCharaktere();

    foreach(Charakter charakter, *charaktaere) {

        ui->heldenListWidget->addItem(charakter.getName());
    }
}

void MainForm::loadCharakters(){

}

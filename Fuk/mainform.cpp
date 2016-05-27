#include "mainform.h"
#include "ui_mainform.h"
#include "charakterform.h"



MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    // init
    charakterManager = new CharakterManager();
    charakterForm = new CharakterForm(0,charakterManager);
    charakterForm->setModal(true);
    loadCharakters();


    QStringList items;
    items << "Test";
    ui->heldenListWidget->addItems(items);

    // connectors
    connect(ui->erstellenButton,SIGNAL(clicked()),this,SLOT(erstellenButtonClicked()));
}

MainForm::~MainForm()
{
    delete charakterManager;
    delete charakterForm;
    delete ui;
}

void MainForm::erstellenButtonClicked()
{
    charakterForm->show();
}

void MainForm::clickedOnHinzufuegen(const QModelIndex &index)
{

}


void MainForm::loadCharakters(){

}

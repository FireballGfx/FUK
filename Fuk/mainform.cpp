#include "mainform.h"
#include "ui_mainform.h"
#include "fertigkeitform.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    fertigkeitForm = new FertigkeitForm();
    fertigkeitForm->setModal(true);


    ui->treeView->

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_pushButton_clicked()
{

    fertigkeitForm->show();
}

void MainForm::on_treeView_clicked(const QModelIndex &index)
{

}

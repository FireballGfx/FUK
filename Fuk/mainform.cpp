#include "mainform.h"
#include "ui_mainform.h"
#include "charakterform.h"


MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    charakterForm = new CharakterForm();
    charakterForm->setModal(true);

    QStringList items;

    items << "Test";

    ui->heldenListWidget->addItems(items);

    connect(ui->hinzufuegenButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}

MainForm::~MainForm()
{

    delete charakterForm;
    delete ui;
}

void MainForm::on_pushButton_clicked()
{

    charakterForm->show();
}

void MainForm::clickedOnHinzufuegen(const QModelIndex &index)
{

}

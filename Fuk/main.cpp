#include "mainform.h"
#include <QApplication>

#include "charakter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm main;


    Charakter *c = new Charakter;


    main.show();

    delete c;

    return a.exec();
}

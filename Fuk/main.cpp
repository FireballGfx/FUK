#include "mainform.h"
#include <QApplication>

#include "charakter.h"
#include "eigenschaft.h"
#include "eigenschaftexception.h"

#include "fertigkeit.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm main;


    Eigenschaft *klugheit = new Eigenschaft(KLUGHEIT,2);


    Fertigkeit *f = new Fertigkeit(*klugheit,"Schach","Ist Deutscher Schachmeister.");



    main.show();

    delete f;
    delete klugheit;
    return a.exec();
}

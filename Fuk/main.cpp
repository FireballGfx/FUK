
#include <QApplication>

#include "startlogo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Startlogo s;
    s.show();




    return a.exec();
}

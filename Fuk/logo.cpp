
#include "logo.h"
#include "ui_logo.h"

Logo::Logo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logo)
{
    ui->setupUi(this);

    setWindowFlags( Qt::CustomizeWindowHint );
    setFixedSize(725,507);
    QApplication::setOverrideCursor(Qt::BlankCursor);

}

Logo::~Logo(){
    Qt::CursorShape shape = Qt::ArrowCursor;
    QApplication::setOverrideCursor(QCursor(shape));
    delete ui;
}

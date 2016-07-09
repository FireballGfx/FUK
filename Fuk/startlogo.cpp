#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsSimpleTextItem>
#include "startlogo.h"
#include "ui_startlogo.h"
#include "global.h"


Startlogo::Startlogo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Startlogo)
{
    ui->setupUi(this);

    setWindowFlags( Qt::CustomizeWindowHint | Qt::FramelessWindowHint );
    setFixedSize(424,600);
    QApplication::setOverrideCursor(Qt::BlankCursor);


    setMouseTracking(true);
    QCoreApplication::instance()->installEventFilter(this);


    connect(this,SIGNAL(showMainForm()),this,SLOT(startApp()));
}

Startlogo::~Startlogo()
{

    delete ui;
}

void Startlogo::startApp(){

    mainForm.show();
}

void Startlogo::mouseMoveEvent(QMouseEvent *event){
    if(event->type() == QEvent::MouseMove){
        // QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);


        Qt::CursorShape shape = Qt::ArrowCursor;
        QApplication::setOverrideCursor(QCursor(shape));

        this->close();



        emit showMainForm();
    }
}

void Startlogo::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    QPixmap pixmap(":/data/image/fuk.jpg");

    painter.begin(this);
    painter.drawPixmap(0,0,pixmap);

    painter.setPen(Qt::red);
    painter.drawText(QPoint(5,590),Constants::version);
    painter.end();
}

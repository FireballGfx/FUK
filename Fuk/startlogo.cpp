#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsSimpleTextItem>
#include <QTimer>
#include "startlogo.h"
#include "ui_startlogo.h"
#include "global.h"


Startlogo::Startlogo(QWidget *parent) :
    QWidget(parent),counter(3),
    ui(new Ui::Startlogo)
{
    ui->setupUi(this);

    setWindowFlags( Qt::CustomizeWindowHint | Qt::FramelessWindowHint );
    setFixedSize(424,600);
    QApplication::setOverrideCursor(Qt::BlankCursor);


    setMouseTracking(true);
    QCoreApplication::instance()->installEventFilter(this);


    QTimer *timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(showMainForm()),this,SLOT(startApp()));

    timer->start(1000);
}

Startlogo::~Startlogo()
{
    delete ui;
}

void Startlogo::startApp(){

    mainForm.show();
}

void Startlogo::tick(){

    if(counter > 0){
        counter = counter - 1;
    }
}

void Startlogo::mouseMoveEvent(QMouseEvent *event){
    if(event->type() == QEvent::MouseMove){

        Qt::CursorShape shape = Qt::ArrowCursor;
        QApplication::setOverrideCursor(QCursor(shape));


        if(counter == 0){
            this->close();
            emit showMainForm();
        }
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

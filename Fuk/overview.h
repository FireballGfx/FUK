#ifndef OVERVIEW_H
#define OVERVIEW_H

#include <QDialog>
#include <QGraphicsScene>
#include "charaktermanager.h"

namespace Ui {
class Overview;
}

class Overview : public QDialog
{
    Q_OBJECT

public:
    explicit Overview(QWidget *parent = 0, Ptr<CharakterManager> charakterManager = 0);
    ~Overview();


private slots:
    void verwerfen();
    void drucken();

private:
    Ui::Overview *ui;

    Ptr<CharakterManager> charakterManager;

    QGraphicsScene* scene;
    QGraphicsEllipseItem* elipse;


private:
    void paint();

};

#endif // OVERVIEW_H

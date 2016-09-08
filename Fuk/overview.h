#ifndef OVERVIEW_H
#define OVERVIEW_H

#include <QDialog>
#include <QGraphicsScene>
#include "charaktermanager.h"

class Charakter;

namespace Ui {
class Overview;
}

class Overview : public QDialog
{
    Q_OBJECT

public:
    explicit Overview(QWidget *parent = 0, Ptr<CharakterManager> charakterManager = 0);
    ~Overview();

    void paint(Ptr<Charakter> charakter);

private slots:
    void verwerfen();
    void drucken();

private:
    Ui::Overview *ui;

    Ptr<CharakterManager> charakterManager;

    QGraphicsScene* scene;


private:



};

#endif // OVERVIEW_H

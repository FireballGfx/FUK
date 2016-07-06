#ifndef STARTLOGO_H
#define STARTLOGO_H

#include <QWidget>
#include "mainform.h"

namespace Ui {
class Startlogo;
}

class Startlogo : public QWidget
{
    Q_OBJECT

public:
    explicit Startlogo(QWidget *parent = 0);
    ~Startlogo();


public slots:
    void startApp();

signals:
    void showMainForm();

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);

private:
    Ui::Startlogo *ui;

    MainForm mainForm;
};

#endif // STARTLOGO_H

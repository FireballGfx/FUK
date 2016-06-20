#ifndef OVERVIEW_H
#define OVERVIEW_H

#include <QDialog>
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

private:
    Ui::Overview *ui;

    Ptr<CharakterManager> charakterManager;
};

#endif // OVERVIEW_H

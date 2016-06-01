#ifndef CHARAKTERFORM_H
#define CHARAKTERFORM_H

#include <QDialog>
#include <memory>

#include "global.h"
#include "charaktermanager.h"

class FertigkeitForm;


namespace Ui {
class charakterform;
}

class CharakterForm : public QDialog
{
    Q_OBJECT

public:
    explicit CharakterForm(QDialog *parent = 0,std::shared_ptr<CharakterManager> charakterManager = 0);
    ~CharakterForm();



private slots:
    void startGenerierung();
    void abbrechenGenerierung();

private:
    Ui::charakterform *ui;

    Ptr<FertigkeitForm> fertigkeitForm;
    Ptr<CharakterManager> charakterManager;
};

#endif // CHARAKTERFORM_H

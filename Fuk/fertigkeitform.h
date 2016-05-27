#ifndef FERTIGKEITFORM_H
#define FERTIGKEITFORM_H

#include <QDialog>
#include "charakter.h"
#include "charaktermanager.h"

namespace Ui {
class FertigkeitForm;
}

class FertigkeitForm : public QDialog
{
    Q_OBJECT

public:
    explicit FertigkeitForm(QDialog *parent = 0, CharakterManager* charakterManager = 0);
    ~FertigkeitForm();

private:
    Ui::FertigkeitForm *ui;
    CharakterManager* charakterManager;

    int step;


private slots:
    void onPushButtonAbbrechenClicked();
    void on_pushButtonAbbrechen_clicked();
    void on_pushButtonZurueck_clicked();
    void naechsterSchritt();
};

#endif // FERTIGKEITFORM_H

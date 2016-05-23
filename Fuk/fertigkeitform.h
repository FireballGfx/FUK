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
    explicit FertigkeitForm(QDialog *parent = 0);
    ~FertigkeitForm();

private:
    Ui::FertigkeitForm *ui;
    CharakterManager* charakterManager;



private slots:
    void onPushButtonAbbrechenClicked();
    void on_pushButtonAbbrechen_clicked();
    void on_pushButtonZurueck_clicked();
    void on_pushButtonNext_clicked();
};

#endif // FERTIGKEITFORM_H

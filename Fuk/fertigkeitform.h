#ifndef FERTIGKEITFORM_H
#define FERTIGKEITFORM_H

#include <QDialog>
#include "global.h"
#include "charakter.h"
#include "charaktermanager.h"

namespace Ui {
class FertigkeitForm;
}

class CharakterForm;

class FertigkeitForm : public QDialog
{
    Q_OBJECT

   friend class CharakterForm;

public:
    explicit FertigkeitForm(QDialog *parent = 0, Ptr<CharakterManager> charakterManager = 0);
    ~FertigkeitForm();

private:
    Ui::FertigkeitForm *ui;
    Ptr<CharakterManager> charakterManager;
    int step;
    int index;

    static const int MAX_STEP = 13;
    static const int MAX_INDEX = 12;
    static const int MIN_STEP = 1;
    static const int MIN_INDEX = 0;

signals:
    void beenden();

private slots:
    void onPushButtonAbbrechenClicked();
    void zurueckSchritt();
    void naechsterSchritt();
};

#endif // FERTIGKEITFORM_H

#ifndef FERTIGKEITFORM_H
#define FERTIGKEITFORM_H

#include <QDialog>

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
};

#endif // FERTIGKEITFORM_H

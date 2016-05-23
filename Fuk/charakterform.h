#ifndef CHARAKTERFORM_H
#define CHARAKTERFORM_H

#include <QDialog>


class FertigkeitForm;

namespace Ui {
class charakterform;
}

class CharakterForm : public QDialog
{
    Q_OBJECT

public:
    explicit CharakterForm(QDialog *parent = 0);
    ~CharakterForm();


private slots:
    void startGenerierung();

private:
    Ui::charakterform *ui;

    FertigkeitForm* fertigkeitForm;
};

#endif // CHARAKTERFORM_H

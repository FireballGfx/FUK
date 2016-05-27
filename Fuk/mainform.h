#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <charaktermanager.h>


class CharakterForm;

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:
    void erstellenButtonClicked();

    void clickedOnHinzufuegen(const QModelIndex &index);

private:
    CharakterManager* charakterManager;
    Ui::MainForm *ui;
    CharakterForm* charakterForm;


private:
    void loadCharakters();
};

#endif // MAINFORM_H

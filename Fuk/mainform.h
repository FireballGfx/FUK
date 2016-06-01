#ifndef MAINFORM_H
#define MAINFORM_H

#include <memory>
#include <QWidget>
#include <charaktermanager.h>

#include "global.h"


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

    Ptr<CharakterForm> charakterForm;
    Ptr<CharakterManager> charakterManager;
    Ui::MainForm *ui;



private:
    void loadCharakters();
};

#endif // MAINFORM_H

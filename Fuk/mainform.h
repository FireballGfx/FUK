#ifndef MAINFORM_H
#define MAINFORM_H

#include <memory>
#include <QWidget>
#include "charaktermanager.h"

#include "global.h"


class CharakterForm;
class Credits;
class Overview;

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{

    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();


    //todo löschen nach Test
    Charakter* getCurrentChar(){
        return charakterManager->getCurrentCharakter().lock().get();
    }

private slots:
    void druckenDialog();
    void erstellenButtonClicked();
    void showCredits();

private:

    Ptr<CharakterForm> charakterForm;
    Ptr<CharakterManager> charakterManager;
    Ptr<Credits> creditsForm;
    Ptr<Overview> overviewForm;
    Ui::MainForm *ui;



private:
    void loadCharakters();
};

#endif // MAINFORM_H

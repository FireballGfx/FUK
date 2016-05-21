#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <charaktermanager.h>

class FertigkeitForm;

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
    void on_pushButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    CharakterManager charakterManager;

    Ui::MainForm *ui;

    FertigkeitForm *fertigkeitForm;
};

#endif // MAINFORM_H

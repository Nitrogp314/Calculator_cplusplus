#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_testandoQt.h"

class testandoQt : public QMainWindow, Ui::testandoQtClass // Importar o Ui::testandoQtClass � essencial para usar o this l� no .cpp
{
    Q_OBJECT

public:
    testandoQt(QWidget *parent = nullptr);
    ~testandoQt();

public slots: // Feito manualmente

    // O slot da opera��o de subtra��o 
    void slotMinus();

    void slotSum();

    void slotMultiply();

    void slotDivide();

    void slot_Exponential();

    void slot_Sine();

    void slot_Cos();

private:
    //Ui::testandoQtClass ui;

    double single_input; // Vamos usar essa vari�veis para as "fun��es �nicas"
};

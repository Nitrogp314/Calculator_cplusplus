#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_testandoQt.h"

class testandoQt : public QMainWindow, Ui::testandoQtClass // Importar o Ui::testandoQtClass é essencial para usar o this lá no .cpp
{
    Q_OBJECT

public:
    testandoQt(QWidget *parent = nullptr);
    ~testandoQt();

public slots: // Feito manualmente

    // O slot da operação de subtração 
    void slotMinus();

    void slotSum();

    void slotMultiply();

    void slotDivide();

    void slot_Exponential();

    void slot_Sine();

    void slot_Cos();

private:
    //Ui::testandoQtClass ui;

    double single_input; // Vamos usar essa variáveis para as "funções únicas"
};

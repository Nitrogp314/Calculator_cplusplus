#include "testandoQt.h"


testandoQt::testandoQt(QWidget *parent) // Nessa classe definiremos todos os signals, um para cada ação
    : QMainWindow(parent)
{
     this->setupUi(this); // O original era ui.setupUi, e lembre-se, para ter o direito de usar o this, precisamos escrever  Ui::testandoQtClass lá no .h

    // Vamos, agora, escrever os sinais. Um para cada ação 

     // (1) Subtração :

     connect(this->btnSubtract, &QPushButton::clicked, this, &testandoQt::slotMinus, Qt::UniqueConnection); // 

     // (2) Adição:
     connect(this->btnAdd, &QPushButton::clicked, this, &testandoQt::slotSum, Qt::UniqueConnection);

     // (3) Multiplicação:
     connect(this->btnMultiply, &QPushButton::clicked, this, &testandoQt::slotMultiply, Qt::UniqueConnection);

     //(4) Divisão:
     connect(this->btnDivide, &QPushButton::clicked, this, &testandoQt::slotDivide, Qt::UniqueConnection);

     // Euler number to the power of something
     connect(this->btnExpo, &QPushButton::clicked, this, &testandoQt::slot_Exponential, Qt::UniqueConnection);

     // Sine function
     connect(this->btnSeno, &QPushButton::clicked, this, &testandoQt::slot_Sine, Qt::UniqueConnection);

     // Cossine Function 
     connect(this->btnCos, &QPushButton::clicked, this, &testandoQt::slot_Cos, Qt::UniqueConnection);
}

testandoQt::~testandoQt(){

}



// As funções abaixo farão as operações desejadas

void testandoQt::slotMinus() {

    double a = this->txtFirstNum->text().toDouble();
    double b = this->txtSecondNum->text().toDouble();

    double result = a - b;

    this->txtResult->setText(QString::number(result));
}


void testandoQt::slotSum() {

    double a = this->txtFirstNum->text().toDouble();
    double b = this->txtSecondNum->text().toDouble();

    double result = a + b;

    this->txtResult->setText(QString::number(result));
}

void testandoQt::slotMultiply() {

    double a = this->txtFirstNum->text().toDouble();
    double b = this->txtSecondNum->text().toDouble();

    double result = a * b;

    this->txtResult->setText(QString::number(result));

}



void testandoQt::slotDivide() {
    double a = this->txtFirstNum->text().toDouble();
    double b = this->txtSecondNum->text().toDouble();

    if (b != 0) {
        double result = a / b;
        this->txtResult->setText(QString::number(result)); // Exibe o resultado
    }
    else {
        this->txtResult->setText("Divisao por zero nao permitida"); // Exibe a mensagem de erro
    }
}



// Último exemplo : E se quiséssemos definir uma funç~çao fora da classe testandoQt ? Vamos fazer um exemplo de senos e cossenos, 
// Sabe-se que, numa calculadora, senos e cossenos são aproximados por uma série de taylor, até certo grau. Vejamos isto :

#include <cmath>

// Primeiro, uma função para calcular o fatorial , necessária para as séries de Taylor
double fatorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Função exponencial usando expansão de Taylor
double exponencial(double x) {
    double sum = 1.0;  // Termo inicial (n=0)
    int ordem = 10; // Trmos que parar em algum momento, logo, aqui,  escolha uma ordem razoável para precisão. Por ex, 10
    for (int n = 1; n <= ordem; ++n) {
        sum += pow(x, n) / fatorial(n);
    }
    return sum;
}



void testandoQt::slot_Exponential() {

    single_input = this->input_function->text().toDouble();

    double result = exponencial(single_input); // Lembre de pegar esses caras que foram definidos na .h

    this->txtResult->setText(QString::number(result));

}

// Função seno usando expansão de Taylor
double seno(double x) {
    double sum = 0.0;
    int ordem = 10;
    for (int n = 0; n <= ordem; ++n) {
        sum += pow(-1, n) * pow(x, 2 * n + 1) / fatorial(2 * n + 1);
    }
    return sum;
}

// Função cosseno usando expansão de Taylor
double cosseno(double x) {
    double sum = 0.0;
    int ordem = 10;
    for (int n = 0; n <= ordem; ++n) {
        sum += pow(-1, n) * pow(x, 2 * n) / fatorial(2 * n);
    }
    return sum;
}


void testandoQt::slot_Sine() {

    single_input = this->input_function->text().toDouble();

    double result = seno(single_input);

    this->txtResult->setText(QString::number(result));

}
 

void testandoQt::slot_Cos() {

    single_input = this->input_function->text().toDouble();
    double result = cosseno(single_input);

    this->txtResult->setText(QString::number(result));
}









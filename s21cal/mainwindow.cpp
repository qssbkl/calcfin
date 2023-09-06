#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>

extern "C" {
#include "../calculation.h"
#include "../mystack.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graph = new GRAPHG;

    connect(this, &MainWindow::signal, graph, &GRAPHG::slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

char input_string[256] = {' '};
char output_string[256];
struct st *operations = NULL;
int i = 0;
double d = 0.0;
double xmin = -10;
double xmax = 10;
double ymin = -10;
double ymax = 10;

void MainWindow::on_button0_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("0");
        input_string[i] = '0';
        i++;
    }
}

void MainWindow::on_button1_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("1");
        input_string[i] = '1';
        i++;
    }
}

void MainWindow::on_button2_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("2");
        input_string[i] = '2';
        i++;
    }
}

void MainWindow::on_button3_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("3");
        input_string[i] = '3';
        i++;
    }
}

void MainWindow::on_button4_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("4");
        input_string[i] = '4';
        i++;
    }
}

void MainWindow::on_button5_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("5");
        input_string[i] = '5';
        i++;
    }
}

void MainWindow::on_button6_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("6");
        input_string[i] = '6';
        i++;
    }
}

void MainWindow::on_button7_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("7");
        input_string[i] = '7';
        i++;
    }
}

void MainWindow::on_button8_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("8");
        input_string[i] = '8';
        i++;
    }
}

void MainWindow::on_button9_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x') {
        ui->lineEdit->insert("9");
        input_string[i] = '9';
        i++;
    }
}

void MainWindow::on_buttonsin_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("sin(");
        input_string[i] = 's';
        input_string[i+1] = 'i';
        input_string[i+2] = 'n';
        input_string[i+3] = '(';
        i += 4;
    }
}

void MainWindow::on_buttonpow_clicked()
{
    if (i != 0 && input_string[i-1] != '/' && input_string[i-1] != '*' && input_string[i-1] != '(' && input_string[i-1] != '^' && input_string[i-1] != '.') {
        ui->lineEdit->insert("^");
        input_string[i] = '^';
        i++;
    }
}

void MainWindow::on_buttoncos_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("cos(");
        input_string[i] = 'c';
        input_string[i+1] = 'o';
        input_string[i+2] = 's';
        input_string[i+3] = '(';
        i += 4;
    }
}

void MainWindow::on_buttontan_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("tan(");
        input_string[i] = 't';
        input_string[i+1] = 'g';
        input_string[i+2] = '(';
        i += 3;
    }
}

void MainWindow::on_buttonasin_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("asin(");
        input_string[i] = 'z';
        input_string[i+1] = '(';
        i += 2;
    }
}

void MainWindow::on_buttonacos_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("acos(");
        input_string[i] = 'v';
        input_string[i+1] = '(';
        i += 2;
    }
}

void MainWindow::on_buttonatan_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("atan(");
        input_string[i] = 'b';
        input_string[i+1] = '(';
        i += 2;
    }
}

void MainWindow::on_buttonmod_clicked()
{
    if (i != 0 && input_string[i-1] != '/' && input_string[i-1] != '*' && input_string[i-1] != '(' && input_string[i-1] != '^' && input_string[i-1] != '.') {
        ui->lineEdit->insert("mod");
        input_string[i] = 'm';
        i ++;
    }
}

void MainWindow::on_buttonlb_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("(");
        input_string[i] = '(';
        i ++;
    }
}

void MainWindow::on_buttonrb_clicked()
{
    int l = 0;
    int p = 0;
    for (int k = 0; k < i; k++) {
        if (input_string[k] == ')') l++;
        if (input_string[k] == '(') p++;
    }
    if (l < p && input_string[i-1] != '(') {
        ui->lineEdit->insert(")");
        input_string[i] = ')';
        i ++;
    }
}

void MainWindow::on_buttonln_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("ln(");
        input_string[i] = 'l';
        input_string[i+1] = 'n';
        input_string[i+2] = '(';
        i += 3;
    }
}

void MainWindow::on_buttonlog_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("log(");
        input_string[i] = 'l';
        input_string[i+1] = 'o';
        input_string[i+2] = 'g';
        input_string[i+3] = '(';
        i += 4;
    }
}

void MainWindow::on_buttonplus_clicked()
{
    if (input_string[i-1] != '/' && input_string[i-1] != '*' && input_string[i-1] != '^' && input_string[i-1] != '.' && input_string[i-1] != '+') {
        ui->lineEdit->insert("+");
        input_string[i] = '+';
        i ++;
    }
}

void MainWindow::on_buttonmin_clicked()
{
    if (input_string[i-1] != '/' && input_string[i-1] != '*' && input_string[i-1] != '^' && input_string[i-1] != '.' && input_string[i-1] != '-') {
        ui->lineEdit->insert("-");
        input_string[i] = '-';
        i ++;
    }
}

void MainWindow::on_buttondiv_clicked()
{
    if (i != 0 && input_string[i-1] != '/' && input_string[i-1] != '*' && input_string[i-1] != '(' && input_string[i-1] != '^' && input_string[i-1] != '.') {
        ui->lineEdit->insert("/");
        input_string[i] = '/';
        i ++;
    }
}

void MainWindow::on_buttonmul_clicked()
{
    if (i != 0 && input_string[i-1] != '/' && input_string[i-1] != '*' && input_string[i-1] != '(' && input_string[i-1] != '^' && input_string[i-1] != '.') {
        ui->lineEdit->insert("*");
        input_string[i] = '*';
        i ++;
    }
}

void MainWindow::on_buttonsqrt_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("sqrt(");
        input_string[i] = 's';
        input_string[i+1] = 'q';
        input_string[i+2] = 'r';
        input_string[i+3] = 't';
        input_string[i+4] = '(';
        i += 5;
    }

}

void MainWindow::on_buttonsol_clicked()
{
        bool nepopajopa {true};
        for (auto it = ui->xline->text().begin(); it < ui->xline->text().end(); it++) {
            if ( ! isNumber(it->toLatin1())) {
                nepopajopa = false;
            }
        }
        int l = 0;
        int p = 0;
        int u = 0;
        for (int k = 0; k < i; k++) {
            if (input_string[k] == ')') l++;
            if (input_string[k] == '(') p++;
            if (input_string[k] == 'x') u++;
        }
        if (input_string[0] != ' ' && input_string[i-1] != '/' && input_string[i-1] != '*' && input_string[i-1] != '(' && input_string[i-1] != '^' && input_string[i-1] != '.' && l == p && input_string[i-1] != '+' && input_string[i-1] != '-') {
            if (nepopajopa && u != 0) {
                double o = ui->xline->text().toDouble();
                parsing_in_polish_notation(operations, input_string, output_string);
                HEAD head;
                init(&head);
                d = counter(output_string, &head, o);
                ui->label->setNum(d);
            } else if (u == 0) {
                parsing_in_polish_notation(operations, input_string, output_string);
                HEAD head;
                init(&head);
                d = counter(output_string, &head, 0);
                ui->label->setNum(d);
            } else {
                ui->label->setText("Incorrect X");
            }
            ui->lineEdit->clear();
            for (int j = 0; j < i; j++) {
                input_string[j] = ' ';
            }
            for (int j = 0; j < i; j++) {
                output_string[j] = ' ';
            }
            i = 0;
            operations = NULL;
        }
}

void MainWindow::on_button8_2_clicked()
{
    if (input_string[i-1] != ')' && input_string[i-1] != 'x' && ! isNumber(input_string[i-1])) {
        ui->lineEdit->insert("x");
        input_string[i] = 'x';
        i++;
    }
}


void MainWindow::on_buttondot_clicked()
{
    if (i != 0 && input_string[i-1] != '-' && input_string[i-1] != '+' && input_string[i-1] != '/' && input_string[i-1] != '*' && input_string[i-1] != '(' && input_string[i-1] != '^' && input_string[i-1] != '.') {
        ui->lineEdit->insert(".");
        input_string[i] = '.';
        i ++;
    }
}


void MainWindow::on_button7_2_clicked()
{
    graph->x.clear();
    graph->y.clear();
    int l = 0;
    int p = 0;
    for (int k = 0; k < i; k++) {
        if (input_string[k] == ')') l++;
        if (input_string[k] == '(') p++;
    }
    if (input_string[0] != ' ' && input_string[i-1] != '/' && input_string[i-1] != '*' && input_string[i-1] != '(' && input_string[i-1] != '^' && input_string[i-1] != '.' && l == p && input_string[i-1] != '+' && input_string[i-1] != '-') {
        parsing_in_polish_notation(operations, input_string, output_string);
        HEAD head;
        init(&head);
        for (double h = xmin; h < xmax; h += 0.05) {
            d = counter(output_string, &head, h);
            emit signal(d, xmin, xmax, ymin, ymax);
        }
        ui->lineEdit->clear();
        for (int j = 0; j < i; j++) {
            input_string[j] = ' ';
        }
        for (int j = 0; j < i; j++) {
            output_string[j] = ' ';
        }
        i = 0;
        operations = NULL;
    }
    graph->show();
}


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->clear();
    for (int j = 0; j < i; j++) {
        input_string[j] = ' ';
    }
    for (int j = 0; j < i; j++) {
        output_string[j] = ' ';
    }
    i = 0;
    operations = NULL;
}


void MainWindow::on_xminup_clicked()
{
    xmin ++;
    ui->xmin->setNum(xmin);
}


void MainWindow::on_xmindown_clicked()
{
    xmin --;
    ui->xmin->setNum(xmin);
}


void MainWindow::on_xmaxup_clicked()
{
    xmax ++;
    ui->xmax->setNum(xmax);
}


void MainWindow::on_xmaxdown_clicked()
{
    xmax --;
    ui->xmax->setNum(xmax);
}


void MainWindow::on_yminup_clicked()
{
    ymin ++;
    ui->ymin->setNum(ymin);
}


void MainWindow::on_ymindown_clicked()
{
    ymin --;
    ui->ymin->setNum(ymin);
}


void MainWindow::on_ymaxup_clicked()
{
    ymax ++;
    ui->ymax->setNum(ymax);
}


void MainWindow::on_ymaxdown_clicked()
{
    ymax --;
    ui->ymax->setNum(ymax);
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <graphg.h>
//#include <qcustomplot.h>
//#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signal(double a, int xmin, int xmax, int ymin, int ymax);

private slots:
    void on_button0_clicked();

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

    void on_buttonsin_clicked();

    void on_buttonpow_clicked();

    void on_buttoncos_clicked();

    void on_buttontan_clicked();

    void on_buttonasin_clicked();

    void on_buttonacos_clicked();

    void on_buttonatan_clicked();

    void on_buttonmod_clicked();

    void on_buttonlb_clicked();

    void on_buttonrb_clicked();

    void on_buttonln_clicked();

    void on_buttonlog_clicked();

    void on_buttonplus_clicked();

    void on_buttonmin_clicked();

    void on_buttondiv_clicked();

    void on_buttonmul_clicked();

    void on_buttonsqrt_clicked();

    void on_buttonsol_clicked();

    void on_button8_2_clicked();

    void on_buttondot_clicked();

    void on_button7_2_clicked();

    void on_pushButton_clicked();

    void on_xminup_clicked();

    void on_xmindown_clicked();

    void on_xmaxup_clicked();

    void on_xmaxdown_clicked();

    void on_yminup_clicked();

    void on_ymindown_clicked();

    void on_ymaxup_clicked();

    void on_ymaxdown_clicked();

private:
    Ui::MainWindow *ui;
    GRAPHG *graph;
};
#endif // MAINWINDOW_H

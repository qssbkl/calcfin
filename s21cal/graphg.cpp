#include "graphg.h"
#include "ui_graphg.h"
#include <string>
#include <iostream>

extern "C" {
#include "../calculation.h"
#include "../mystack.h"
}


GRAPHG::GRAPHG(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GRAPHG)
{
    ui->setupUi(this);
}

GRAPHG::~GRAPHG()
{
    delete ui;
}


void GRAPHG::slot(double a, int xmin, int xmax, int ymin, int ymax)
{
    ui->widget->clearGraphs();
    ui->widget->replot();
    ui->widget->addGraph();
    ui->widget->xAxis->setRange(xmin, xmax);
    ui->widget->yAxis->setRange(ymin, ymax);
    for (double l = xmin; l < xmax; l += 0.05) {
            x.append(l);
    }
    y.append(a);
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
}

#ifndef GRAPHG_H
#define GRAPHG_H

#include <QWidget>
#include <qcustomplot.h>
#include <QVector>

namespace Ui {
class GRAPHG;
}

class GRAPHG : public QWidget
{
    Q_OBJECT

public:
    explicit GRAPHG(QWidget *parent = nullptr);
    ~GRAPHG();
    QVector<double> x,y;
private:
    Ui::GRAPHG *ui;

public slots:
    void slot(double a, int xmin, int xmax, int ymin, int ymax);

private slots:

};


#endif // GRAPHG_H

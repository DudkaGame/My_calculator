#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double directionAngle, increment, x_1, y_1, x_2, y_2 = 0;
int scaleFactor, quarter = 0;
bool mode = 1;


double calculation(int mode){


    switch (mode) {

    case true:
        x_2 = (cos(directionAngle * M_PI / 180) * increment + x_1) * scaleFactor * quarter;
        y_2 = (sin(directionAngle * M_PI / 180) * increment + x_1) * scaleFactor * quarter;
        return(x_2);
    break;

    case false:

    break;

    }

}

void MainWindow::on_сalculateButton_clicked(){



    ui->resultLabel->setText(QString("Координаты второй точки: %1").arg(calculation(mode)));

}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
#include "QIntValidator"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  QIntValidator* validator = new QIntValidator(0, 10000, this);  // Ограничить ввод от 0 до 100
  ui->x_1->setValidator(validator);
  ui->y_1->setValidator(validator);
}

MainWindow::~MainWindow()
{
  delete ui;
}

double directionAngle, increment, x_1, y_1, x_2, y_2 = 0;
int scaleFactor, quarter = 0;
bool mode = 1;
bool error = 0;

// ui->resultLabel->setText(QString("Координаты второй точки: %1").arg(calculation(mode)));

void MainWindow::on_Calculate_button_clicked()
{
  QString strX, strY, strDirectionAngle, strIncrement, strScale = "";

  if (error)
  {
    // проверка множественные условия
    return;
  }

  if (!error)
  {
    if (mode)
    {
      x_2 = (cos(directionAngle * M_PI / 180) * increment + x_1);
      y_2 = (sin(directionAngle * M_PI / 180) * increment + y_1);

      ui->resultLabel->setText(QString("Координаты второй точки: x2: %1  y2:").arg(x_2, y_2));
    }
  }
}

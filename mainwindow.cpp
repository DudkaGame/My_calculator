#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
#include "QIntValidator"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  //  QIntValidator* validator = new QIntValidator(0, 10000, this);  // Ограничить ввод от 0 до 100
  //  ui->x_1->setValidator(validator);
  //  ui->y_1->setValidator(validator);
}

MainWindow::~MainWindow()
{
  delete ui;
}

int scaleFactor, quarter = 0;
bool mode = 1;
bool error = 0;

// ui->resultLabel->setText(QString("Координаты второй точки: %1").arg(calculation(mode)));

void MainWindow::on_Calculate_button_clicked()
{
  QString strX, strY, strDirectionAngle, strIncrement, strScale = "";
  double x_2, y_2 = 0;
  int quarterX, quarterY;

  strX = ui->x_1->text();
  double x_1 = strX.toDouble();

  strY = ui->y_1->text();
  double y_1 = strY.toDouble();

  strDirectionAngle = ui->directionAngle->text();
  double directionAngle = strDirectionAngle.toDouble();

  strIncrement = ui->increment->text();
  double increment = strIncrement.toDouble();

  strScale = ui->scale->text();
  double scale = strScale.toDouble();

  if (error)
  {
    // проверка множественные условия
    return;
  }

  if (!error)
  {
    if (mode)
    {
      int quarterInt = trunc(directionAngle / 90);
      switch (quarterInt)
      {
        case 1:
          quarterX = 1;
          quarterY = 1;
          break;
        case 2:
          quarterX = -1;
          quarterY = 1;
          directionAngle = 180 - directionAngle;
          break;
        case 3:
          quarterX = -1;
          quarterY = -1;
          directionAngle = 270 - directionAngle;
          break;
        case 4:
          quarterX = 1;
          quarterY = -1;
          directionAngle = 360 - directionAngle;
          break;
      }
      x_2 = ((cos(directionAngle * M_PI / 180) * (increment / scale)) + (quarterX * x_1));
      y_2 = ((sin(directionAngle * M_PI / 180) * (increment / scale)) + (quarterY * y_1));

      ui->resultLabel->setText(QString("Координаты второй точки: x2: %1  y2: %2").arg(x_2).arg(y_2));
    }
  }
}

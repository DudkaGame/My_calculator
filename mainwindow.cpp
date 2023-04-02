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

  ui->directTask->click();
}
MainWindow::~MainWindow()
{
  delete ui;
}

int scaleFactor, quarter = 0;
bool mode = 1;
bool error = 0;

void MainWindow::on_Calculate_button_clicked()
{
  QString strX, strY, strDirectionAngle, strIncrement, strScale = "";
  double x_2, y_2 = 0;

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

  if (ui->directTask->isChecked())
  {
    if (directionAngle > 0 and directionAngle <= 90)
    {
      x_2 = ((cos(directionAngle * M_PI / 180) * (increment / scale)) + x_1);
      y_2 = ((sin(directionAngle * M_PI / 180) * (increment / scale)) + y_1);
    }
    if (directionAngle > 90 and directionAngle <= 180)
    {
      directionAngle = fabs(90 - directionAngle);
      x_2 = (x_1 - (sin(directionAngle * M_PI / 180) * (increment / scale)));
      y_2 = ((cos(directionAngle * M_PI / 180) * (increment / scale)) + y_1);
    }
    if (directionAngle > 180 and directionAngle <= 270)
    {
      directionAngle = fabs(180 - directionAngle);
      x_2 = (x_1 - (cos(directionAngle * M_PI / 180) * (increment / scale)));
      y_2 = (y_1 - (sin(directionAngle * M_PI / 180) * (increment / scale)));
    }
    if (directionAngle > 270 and directionAngle <= 360)
    {
      directionAngle = fabs(270 - directionAngle);
      x_2 = ((cos(directionAngle * M_PI / 180) * (increment / scale)) + x_1);
      y_2 = (y_1 - (sin(directionAngle * M_PI / 180) * (increment / scale)));
    }

    ui->resultLabel->setText(QString("Координаты второй точки: x2: %1  y2: %2").arg(x_2).arg(y_2));
  }
  else
  {
    if (directionAngle > 0 and directionAngle <= 90)
    {
      x_2 = ((cos(directionAngle * M_PI / 180) * (increment / scale)) + x_1);
      y_2 = ((sin(directionAngle * M_PI / 180) * (increment / scale)) + y_1);
    }
    if (directionAngle > 90 and directionAngle <= 180)
    {
      directionAngle = fabs(90 - directionAngle);
      x_2 = (x_1 - (sin(directionAngle * M_PI / 180) * (increment / scale)));
      y_2 = ((cos(directionAngle * M_PI / 180) * (increment / scale)) + y_1);
    }
    if (directionAngle > 180 and directionAngle <= 270)
    {
      directionAngle = fabs(180 - directionAngle);
      x_2 = (x_1 - (cos(directionAngle * M_PI / 180) * (increment / scale)));
      y_2 = (y_1 - (sin(directionAngle * M_PI / 180) * (increment / scale)));
    }
    if (directionAngle > 270 and directionAngle <= 360)
    {
      directionAngle = fabs(270 - directionAngle);
      x_2 = ((cos(directionAngle * M_PI / 180) * (increment / scale)) + x_1);
      y_2 = (y_1 - (sin(directionAngle * M_PI / 180) * (increment / scale)));
    }

    ui->resultLabel->setText(QString("Дирекционный угол: %1 Дирекционный угол: %2").arg(directionAngle).arg(increment));
  }
}

void MainWindow::on_Clear_button_clicked()
{
  ui->x_1->clear();
  ui->y_1->clear();
  ui->directionAngle->clear();
  ui->scale->clear();
  ui->resultLabel->clear();
}

void MainWindow::on_directTask_clicked()
{
  on_Clear_button_clicked();

  ui->label_x2->hide();
  ui->label_y2->hide();
  ui->label_increnent->show();
  ui->label_angle->show();

  ui->x2->hide();
  ui->y2->hide();
  ui->increment->show();
  ui->directionAngle->show();
}

void MainWindow::on_invertTask_clicked()
{
  on_Clear_button_clicked();

  ui->label_angle->hide();
  ui->label_increnent->hide();
  ui->label_x2->show();
  ui->label_y2->show();

  ui->directionAngle->hide();
  ui->increment->hide();
  ui->x2->show();
  ui->y2->show();
}

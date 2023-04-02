#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void on_Calculate_button_clicked();

  void on_Clear_button_clicked();

  void on_directTask_clicked();

  void on_invertTask_clicked();

private:
  Ui::MainWindow* ui;

  // private: int mode;
};
#endif  // MAINWINDOW_H

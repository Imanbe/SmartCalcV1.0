#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QMainWindow>

#include "graphic.h"
#include "ui_mainwindow.h"

extern "C" {
#include "../src/s21_parser.h"
#include "../src/s21_stack.h"
#include "../src/s21_valid.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:

  void Mods();

  void DigitsNumbers();

  void Operations();

  void MathOperations();

  void TrigonometryOperations();

  void Calculating();

  void CheckStart();

  void SyntaxLabel(QLabel *current_label);

 signals:
  void signal(QString, QString);

 private:
  Ui::MainWindow *ui;
  Graphic *graphic;

  void closeEvent(QCloseEvent *);
};
#endif  // MAINWINDOW_H

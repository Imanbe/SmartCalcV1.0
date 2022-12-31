#include "graphic.h"

#include <locale.h>

#include <iostream>
#include <sstream>

#include "mainwindow.h"
#include "ui_graphic.h"

Graphic::Graphic(QWidget* parent) : QWidget(parent), ui(new Ui::Graphic) {
  ui->setupUi(this);

  ui->Graphic_Poligon->addGraph();
}

Graphic::~Graphic() { delete ui; }

void Graphic::slot(QString line, QString Xnum) {
  setlocale(LC_NUMERIC, "C");

  if (ui->Graphic_Poligon->graphCount() != 0) {
    ui->Graphic_Poligon->removeGraph(0);
    ui->Graphic_Poligon->addGraph();
  }
  x.clear();
  y.clear();

  QString xMin = ui->lineEdit->text();
  QString xMax = ui->lineEdit_2->text();
  QString Step = ui->lineEdit_3->text();

  QList<QString> errors;

  if (Xnum != nullptr && xMax != nullptr && xMin != nullptr) {
    //      try {
    xEnd = Xnum.toDouble();
    xBegin = xEnd * -1;
    //      } catch (double xEnd) {
    //          errors.append(Xnum);
    //      }
  } else if (xMax != nullptr && xMin != nullptr) {
    //      try {
    xEnd = xMax.toDouble();
    //      }
    //      catch (QString xMax) {
    errors.append(xMax);
    //      }
    //      try {
    xBegin = xMin.toDouble();
    //      } catch(QString xMin) {
    //          errors.append(xMin);
    //      }
  } else {
    xBegin = -10;
    xEnd = 10;
  }

  if (Step != nullptr) {
    //      try {
    h = Step.toDouble();
    //      } catch (QString Step) {
    //          errors.append(Step);
    //      }
  } else {
    h = 0.1;
  }

  //  if (errors.count() != 0) {
  //      ui->checker->setText("errors:");
  //      ui->errors->setStyleSheet("QLabel { color: red; }");

  //      QString str;
  //      foreach (str, errors) {
  //       ui->errors->setText(ui->errors->text() + " " + str);
  //      }
  //  }

  ui->Graphic_Poligon->xAxis->setRange(xEnd, xBegin);
  ui->Graphic_Poligon->yAxis->setRange(xEnd, xBegin);

  for (X = xBegin; X <= xEnd; X += h) {
    x.push_back(X);
    y.push_back(Calculater(line, X));
  }

  ui->Graphic_Poligon->graph(0)->addData(x, y);
  ui->Graphic_Poligon->replot();

  x.clear();
  y.clear();
}

double Graphic::Calculater(QString line, double x_number) {
  double result = 0.0;

  std::string tmp_str = line.toStdString();

  const char* current_str = tmp_str.c_str();

  if (Checker(current_str) && sizeof(current_str) <= 256) {
    Calculate(current_str, &result, x_number);
  }

  return result;
}

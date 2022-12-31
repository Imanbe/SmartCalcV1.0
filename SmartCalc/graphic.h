#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QVector>
#include <QWidget>

extern "C" {
#include "../src/s21_parser.h"
#include "../src/s21_stack.h"
#include "../src/s21_valid.h"
}

namespace Ui {
class Graphic;
}

class Graphic : public QWidget {
  Q_OBJECT

 public:
  explicit Graphic(QWidget *parent = nullptr);
  ~Graphic();

  double Calculater(QString a, double x);

 signals:
  void firstWindow();

 private:
  Ui::Graphic *ui;

  double xBegin, xEnd, h, X;

  QVector<double> x, y;

  QString line;

 public slots:
  void slot(QString line, QString xNum);
};

#endif  // GRAPHIC_H

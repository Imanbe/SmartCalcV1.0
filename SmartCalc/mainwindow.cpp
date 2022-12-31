#include "mainwindow.h"

#include <locale.h>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->stackedWidget->setCurrentIndex(0);

  graphic = new Graphic();
  connect(graphic, &Graphic::firstWindow, this, &MainWindow::show);
  connect(this, &MainWindow::signal, graphic, &Graphic::slot);

  // Digits
  connect(ui->PushButton_number_0, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_1, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_2, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_3, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_4, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_5, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_6, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_7, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_8, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_9, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_0_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_1_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_2_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_3_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_4_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_5_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_6_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_7_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_8_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_9_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_X, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));
  connect(ui->PushButton_number_X_mod, SIGNAL(clicked()), this,
          SLOT(DigitsNumbers()));

  // Math Operations
  connect(ui->PushButton_sum, SIGNAL(clicked()), this, SLOT(MathOperations()));
  connect(ui->PushButton_sub, SIGNAL(clicked()), this, SLOT(MathOperations()));
  connect(ui->PushButton_mul, SIGNAL(clicked()), this, SLOT(MathOperations()));
  connect(ui->PushButton_div, SIGNAL(clicked()), this, SLOT(MathOperations()));
  connect(ui->PushButton_dot, SIGNAL(clicked()), this, SLOT(MathOperations()));
  connect(ui->PushButton_degree, SIGNAL(clicked()), this,
          SLOT(MathOperations()));
  connect(ui->PushButton_sum_mod, SIGNAL(clicked()), this,
          SLOT(MathOperations()));
  connect(ui->PushButton_sub_mod, SIGNAL(clicked()), this,
          SLOT(MathOperations()));
  connect(ui->PushButton_mul_mod, SIGNAL(clicked()), this,
          SLOT(MathOperations()));
  connect(ui->PushButton_div_mod, SIGNAL(clicked()), this,
          SLOT(MathOperations()));
  connect(ui->PushButton_dot_mod, SIGNAL(clicked()), this,
          SLOT(MathOperations()));
  connect(ui->PushButton_degree_mod, SIGNAL(clicked()), this,
          SLOT(MathOperations()));
  // Trigonometry Operations (also buttons on "Mod" theme)
  //  (1) trig
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  // (2) simple buttons
  connect(ui->pushButton_equal_mod, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_close_bracket_mod, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));
  connect(ui->pushButton_open_bracket_mod, SIGNAL(clicked()), this,
          SLOT(TrigonometryOperations()));

  // Operations
  connect(ui->PushButton_clear, SIGNAL(clicked()), this, SLOT(Operations()));
  connect(ui->PushButton_clear_all, SIGNAL(clicked()), this,
          SLOT(Operations()));
  connect(ui->pushButton_clear_mod, SIGNAL(clicked()), this,
          SLOT(Operations()));
  connect(ui->pushButton_clear_all_mod, SIGNAL(clicked()), this,
          SLOT(Operations()));
  // Mods
  connect(ui->pushButton_basic, SIGNAL(clicked()), this, SLOT(Mods()));
  connect(ui->pushButton_mods, SIGNAL(clicked()), this, SLOT(Mods()));
  connect(ui->pushButton_graphic, SIGNAL(clicked()), this, SLOT(Mods()));
  // Equal
  connect(ui->PushButton_equal, SIGNAL(clicked()), this, SLOT(Calculating()));
  connect(ui->pushButton_equal_mod, SIGNAL(clicked()), this,
          SLOT(Calculating()));

  ui->pushButton_basic->setStyleSheet(
      "QPushButton { border-radius: 7px; border: all; } QPushButton:hover { "
      "background-color: rgb(61, 61, 61); border-radius: 7px; }  "
      "QPushButton:pressed { background-color: qlineargradient(spread:pad, "
      "x1:0, y1:0, x2:1, y2:1, stop:0 rgba(103, 121, 228, 255), stop:0.47549 "
      "rgba(110, 99, 195, 255), stop:1 rgba(116, 79, 166, 255)); "
      "border-radius: 7px; } ");
}

MainWindow::~MainWindow() {
  QWidget::setAttribute(Qt::WA_DeleteOnClose, true);
  delete graphic;
  delete ui;
}

void MainWindow::Mods() {
  QPushButton *button = (QPushButton *)sender();
  QString text_of_button = button->text();
  static int index = 0;

  static QPushButton *last_button = NULL;

  if (text_of_button.contains("Basic")) {
    index = 0;
    SyntaxLabel(ui->Label_synatx_err);
  } else if (text_of_button.contains("Mod")) {
    index = 2;
    SyntaxLabel(ui->Label_synatx_err_mod);
  } else if (text_of_button.contains("Graphic")) {
    if (!graphic->isVisible()) {
      index = 4;
      graphic->show();
      graphic->move(this->geometry().x() + 380, this->geometry().y() - 28);
    } else {
      graphic->close();
    }
  }

  if (index != -1 && index != 4) {
    ui->stackedWidget->setCurrentIndex(index);
  }
  // ----------- changes the color of the current button ----------- //
  if (last_button != NULL) {
    last_button->setStyleSheet(
        "QPushButton { border-radius: 7px; border: all; } QPushButton:hover { "
        "background-color: rgb(61, 61, 61); border-radius: 7px; }  "
        "QPushButton:pressed { background-color: qlineargradient(spread:pad, "
        "x1:0, y1:0, x2:1, y2:1, stop:0 rgba(103, 121, 228, 255), stop:0.47549 "
        "rgba(110, 99, 195, 255), stop:1 rgba(116, 79, 166, 255)); "
        "border-radius: 7px; } ");
  }

  if (!text_of_button.contains("Graphic")) {
    button->setStyleSheet(
        "QPushButton { border-radius: 7px; border: all; background-color: "
        "qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(103, "
        "121, 228, 255), stop:0.47549 rgba(110, 99, 195, 255), stop:1 "
        "rgba(116, 79, 166, 255)); }");
  }

  last_button = button;
}

void MainWindow::Operations() {
  QPushButton *button = (QPushButton *)sender();
  QString deleted_text, text_of_button = button->text();

  QLabel *tmp;
  QLabel *tmp_1;

  if (ui->stackedWidget->currentIndex() == 0) {
    tmp = ui->Label_result_basic;
    tmp_1 = ui->Label_result_mod;
  } else {
    tmp = ui->Label_result_mod;
    tmp_1 = ui->Label_result_basic;
  }

  if (text_of_button.contains("AC")) {
    deleted_text = "0";
  } else if (text_of_button.contains("C")) {
    if (tmp->text().length() == 1) {
      deleted_text = "0";
    } else {
      deleted_text = tmp->text();
      deleted_text.chop(1);
    }
  }

  tmp->setText(deleted_text);
  tmp_1->setText(deleted_text);
}

void MainWindow::DigitsNumbers() {
  QPushButton *button = (QPushButton *)sender();

  QLabel *tmp;
  QLabel *tmp_1;
  CheckStart();

  if (ui->stackedWidget->currentIndex() == 0) {
    tmp = ui->Label_result_basic;
    tmp_1 = ui->Label_result_mod;
  } else {
    tmp = ui->Label_result_mod;
    tmp_1 = ui->Label_result_basic;
  }

  QString added_text = tmp->text();

  if (button->text().contains("X")) {
    added_text = (tmp->text() + "x");
  } else {
    added_text = (tmp->text() + button->text());
  }

  tmp->setText(added_text);
  tmp_1->setText(added_text);
}

void MainWindow::MathOperations() {
  QPushButton *button = (QPushButton *)sender();
  QString added_text;

  QLabel *tmp;
  QLabel *tmp_1;
  CheckStart();

  if (ui->stackedWidget->currentIndex() == 0) {
    tmp = ui->Label_result_basic;
    tmp_1 = ui->Label_result_mod;
  } else {
    tmp = ui->Label_result_mod;
    tmp_1 = ui->Label_result_basic;
  }

  if (button->text().contains("x")) {
    added_text = (tmp->text() + "*");
  } else if (button->text().contains("÷")) {
    added_text = (tmp->text() + "/");
  } else {
    added_text = (tmp->text() + button->text());
  }

  tmp->setText(added_text);
  tmp_1->setText(added_text);
}

void MainWindow::TrigonometryOperations() {
  QPushButton *button = (QPushButton *)sender();
  QString added_text, text_of_button = button->text();

  CheckStart();

  if (text_of_button.contains("Cos")) {
    added_text = "cos(";
  } else if (text_of_button.contains("Sin")) {
    added_text = "sin(";
  } else if (text_of_button.contains("Tan")) {
    added_text = "tan(";
  } else if (text_of_button.contains("Acos")) {
    added_text = "acos(";
  } else if (text_of_button.contains("Asin")) {
    added_text = "asin(";
  } else if (text_of_button.contains("Atan")) {
    added_text = "atan(";
  } else if (text_of_button.contains("Mod")) {
    added_text = "mod";
  } else if (text_of_button.contains("Sqrt")) {
    added_text = "sqrt(";
  } else if (text_of_button.contains("Log")) {
    added_text = "log(";
  } else if (text_of_button.contains("Ln")) {
    added_text = "ln(";
  } else if (text_of_button.contains(')')) {
    added_text = ')';
  } else if (text_of_button.contains('(')) {
    added_text = '(';
  }

  added_text = (ui->Label_result_mod->text() + added_text);
  ui->Label_result_mod->setText(added_text);
  ui->Label_result_basic->setText(added_text);
}

void MainWindow::Calculating() {
  setlocale(LC_NUMERIC, "C");

  QLabel *syntax_error;
  QLabel *syntax_error_1;
  QLabel *tmp;
  QLabel *tmp_1;

  if (ui->stackedWidget->currentIndex() == 0) {
    syntax_error = ui->Label_synatx_err;
    syntax_error_1 = ui->Label_synatx_err_mod;
    tmp = ui->Label_result_basic;
    tmp_1 = ui->Label_result_mod;
  } else {
    syntax_error = ui->Label_synatx_err_mod;
    syntax_error_1 = ui->Label_synatx_err;
    tmp = ui->Label_result_mod;
    tmp_1 = ui->Label_result_basic;
  }

  QString numbers_end = "0123456789x)";

  if (!TheXInStr(tmp->text().toStdString().c_str())) {
    double result = 0.0;

    std::string tmp_str = tmp->text().toStdString();
    const char *current_str = tmp_str.c_str();

    if (Checker(current_str) && sizeof(current_str) <= 256 &&
        numbers_end.contains(tmp_str[tmp->text().count() - 1])) {
      Calculate(current_str, &result, 0.0);

      tmp->setText(QString::number(result, 'f', 7));
      tmp_1->setText(QString::number(result, 'f', 7));

      syntax_error->setStyleSheet("QLabel { color: gray; }");
      syntax_error->setText(current_str);
      syntax_error_1->setStyleSheet("QLabel { color: gray; }");
      syntax_error_1->setText(current_str);
    } else {
      syntax_error->setStyleSheet("QLabel { color: red; }");
      syntax_error->setText("syntax error");
      syntax_error_1->setStyleSheet("QLabel { color: red; }");
      syntax_error_1->setText("syntax error");
    }

  } else {
    if (Checker(tmp->text().toStdString().c_str())) {
      emit signal(tmp->text(), ui->lineEdit->text());
    } else {
      syntax_error->setStyleSheet("QLabel { color: red; }");
      syntax_error->setText("syntax error");
      syntax_error_1->setStyleSheet("QLabel { color: red; }");
      syntax_error_1->setText("syntax error");
    }
  }
}

void MainWindow::CheckStart() {
  QLabel *current_str;
  QLabel *current_str_1;

  if (ui->stackedWidget->currentIndex() == 0) {
    current_str = ui->Label_result_basic;
    current_str_1 = ui->Label_result_mod;
  } else {
    current_str = ui->Label_result_mod;
    current_str_1 = ui->Label_result_basic;
  }

  if (current_str->text().contains("0") && current_str->text().length() == 1) {
    current_str->setText("");
    current_str_1->setText("");
  }
}

void MainWindow::SyntaxLabel(QLabel *current_label) {
  if (current_label->text().contains("syntax error")) {
    current_label->setStyleSheet("QLabel { color: red; }");
  } else {
    current_label->setStyleSheet("QLabel { color: gray; }");
  }
}

void MainWindow::closeEvent(QCloseEvent *e) {
  if (graphic->isVisible()) {
    graphic->close();
  }
  e->accept();
}

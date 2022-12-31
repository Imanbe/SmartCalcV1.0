#include "s21_parser.h"

int FoundSymbol1(char *array, char to_found) {
  char *ptr = strchr(array, to_found);
  return ptr != NULL ? 1 : 0;
}

double Parsing(const char *str, double x_number) {
  s_stack *ready = NULL;
  s_stack *tmp = NULL;
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (FoundDigital(str[i]) || str[i] == 'x') {
      if (FoundDigital(str[i])) {
        const char *dig_start = &str[i];
        while (FoundDigital(str[i])) i++;
        const char *dig_end = &str[--i];
        char *dig_end1 = (char *)dig_end;
        Data_lf data_lf = strtod(dig_start, &dig_end1);
        push_data_lf(data_lf, &ready);
      } else if (str[i] == 'x') {
        push_data_lf(x_number, &ready);
      }
      SetPriority(&ready);
    } else if (FoundOpenBracket(str[i])) {
      push_data_d(str[i], &tmp);
      SetPriority(&tmp);
    } else if (MathExpression(str, &i, &tmp)) {
    } else if (FoundSign(str[i])) {
      while (tmp != NULL && tmp->priority >= GetPriority(str[i])) {
        push_data_d(pop_data_d(&tmp), &ready);
        SetPriority(&ready);
      }
      push_data_d(str[i], &tmp);
      SetPriority(&tmp);
    } else if (FoundCloseBracket(str[i])) {
      while (!FoundOpenBracket(tmp->data_d) /* && tmp != NULL*/) {
        push_data_d(pop_data_d(&tmp), &ready);
        SetPriority(&ready);
      }
      pop_data_d(&tmp);
      if (!is_empty(&tmp)) {
        if (FoundFunction(peek_type_t(&tmp))) {
          push_type_t(pop_type_t(&tmp), &ready);
        }
      }
    }
  }
  while (tmp != NULL) {
    type_t type = peek_type_t(&tmp);
    if (FoundFunction(type)) {
      push_type_t(pop_type_t(&tmp), &ready);
    } else if (FoundSign(tmp->data_d)) {
      push_data_d(pop_data_d(&tmp), &ready);
      SetPriority(&ready);
    }
  }
  if (tmp != NULL) {
    if (FoundFunction(peek_type_t(&tmp))) {
      push_type_t(pop_type_t(&tmp), &ready);
    }
    if (ThisIsSign(tmp->data_d)) {
      push_data_d(pop_data_d(&tmp), &ready);
      SetPriority(&ready);
    }
  }

  double result = 0;
  Calculation(&ready, &result);

  while (ready != NULL) {
    type_t type = peek_type_t(&tmp);
    if (FoundFunction(type)) {
      pop_type_t(&ready);
    } else if (FoundSign(ready->data_d)) {
      pop_data_d(&ready);
    } else {
      pop_data_lf(&ready);
    }
  }
  return result;
}

double Calculation(s_stack **ready, Data_lf *result) {
  s_stack *tmp = NULL;
  s_stack *output = reverse_stack(ready);

  while (!is_empty(&output)) {
    type_t type = peek_type_t(&output);
    if (type == Number) {
      push_data_lf(pop_data_lf(&output), &tmp);
    } else {
      Data_lf first_value = pop_data_lf(&tmp);
      for (type_t i = Cos; i <= Log; i++) {
        CalculateTrigonometry(type, first_value, &tmp);
        break;
      }
      if ((type >= Sum && type <= Pow) || (type == Mod)) {
        Data_lf second_value = pop_data_lf(&tmp);
        CalculateOperation(type, first_value, second_value, &tmp);
      }
      pop_data_d(&output);
    }
  }
  *result = pop_data_lf(&tmp);
  if (!is_empty(&output)) {
    remove_stack(output);
  }
  if (!is_empty(&tmp)) {
    remove_stack(tmp);
  }
  return *result;
}

int MathExpression(const char *str, size_t *i, s_stack **list) {
  int f_res = ERROR;

  if (strncmp(str + *i, "sin", 3) == 0) {
    push_type_t(Sin, list);
    *i += 2;
    f_res = OK;
  } else if (strncmp(str + *i, "cos", 3) == 0) {
    push_type_t(Cos, list);
    *i += 2;
    f_res = OK;
  } else if (strncmp(str + *i, "tan", 3) == 0) {
    push_type_t(Tan, list);
    *i += 2;
    f_res = OK;
  } else if (strncmp(str + *i, "acos", 4) == 0) {
    push_type_t(Acos, list);
    *i += 3;
    f_res = OK;
  } else if (strncmp(str + *i, "asin", 4) == 0) {
    push_type_t(Asin, list);
    *i += 3;
    f_res = OK;
  } else if (strncmp(str + *i, "atan", 4) == 0) {
    push_type_t(Atan, list);
    *i += 3;
    f_res = OK;
  } else if (strncmp(str + *i, "sqrt", 4) == 0) {
    push_type_t(Sqrt, list);
    *i += 3;
    f_res = OK;
  } else if (strncmp(str + *i, "ln", 2) == 0) {
    push_type_t(Ln, list);
    *i += 1;
    f_res = OK;
  } else if (strncmp(str + *i, "log", 3) == 0) {
    push_type_t(Log, list);
    *i += 2;
    f_res = OK;
  } else if (strncmp(str + *i, "mod", 3) == 0) {
    push_type_t(Mod, list);
    *i += 2;
    f_res = OK;
  }
  return f_res;
}

void CalculateTrigonometry(type_t type, double first_value, s_stack **tmp) {
  Data_lf f_res = 0;

  switch (type) {
    case Cos: {
      f_res = cos(first_value);
      break;
    }
    case Sin: {
      f_res = sin(first_value);
      break;
    }
    case Tan: {
      f_res = tan(first_value);
      break;
    }
    case Acos: {
      f_res = acos(first_value);
      break;
    }
    case Asin: {
      f_res = asin(first_value);
      break;
    }
    case Atan: {
      f_res = atan(first_value);
      break;
    }
    case Sqrt: {
      f_res = sqrt(first_value);
      break;
    }
    case Ln: {
      f_res = log10(first_value);
      break;
    }
    case Log: {
      f_res = log(first_value);
      break;
    }
    default: {
      break;
    }
  }
  if (type >= Cos && type <= Log) {
    push_data_lf(f_res, tmp);
  }
}

void CalculateOperation(type_t type, Data_lf first_value, Data_lf second_value,
                        s_stack **ready) {
  Data_lf f_res = 0.0;

  switch (type) {
    case Sum: {
      f_res = first_value + second_value;
      break;
    }
    case Sub: {
      f_res = second_value - first_value;
      break;
    }
    case Mul: {
      f_res = first_value * second_value;
      break;
    }
    case Div: {
      f_res = second_value / first_value;
      break;
    }
    case Mod: {
      f_res = fmod(second_value, first_value);
      break;
    }
    case Pow: {
      if (first_value == 0.0) {
        f_res = 1;
      } else {
        f_res = pow(second_value, first_value);
      }
      break;
    }
    default: {
      break;
    }
  }
  push_data_lf(f_res, ready);
}

int FoundDigital(char symbol) {
  int res = ERROR;
  if (FoundSymbol1("0123456789.,", symbol)) {
    res = OK;
  }
  return res;
}

int FoundSign(char symbol) {
  int res = ERROR;
  if (FoundSymbol1("+-*/^", symbol)) {
    res = OK;
  }
  return res;
}

int FoundOpenBracket(char symbol) { return symbol == '(' ? 1 : 0; }

int FoundCloseBracket(char symbol) { return symbol == ')' ? 1 : 0; }

int FoundFunction(type_t type) { return type >= Cos && type <= Mod ? 1 : 0; }

int ThisIsSign(int token) {
  int f_result = ERROR;
  char sign[] = {'+', '-', '*', '/', '^'};
  for (char *i = sign; i <= sign + 4; i++) {
    if (token == *i) {
      f_result = OK;
    }
  }
  return f_result;
}

void SetPriority(s_stack **stack) {
  Data_d data_d = (*stack)->data_d;
  type_t *type = &(*stack)->type;
  int *prt = &(*stack)->priority;
  if (FoundDigital(data_d))
    *type = Number, *prt = -1;
  else if (data_d == '(')
    *type = OpenBracket, *prt = 0;
  else if (data_d == ')')
    *type = CloseBrackt, *prt = 0;
  else if (data_d == '+')
    *type = Sum, *prt = 1;
  else if (data_d == '-')
    *type = Sub, *prt = 1;
  else if (data_d == '*')
    *type = Mul, *prt = 2;
  else if (data_d == '/')
    *type = Div, *prt = 2;
  else
    *type = Pow, *prt = 3;  // data_d == '^';
}

int GetPriority(char data_d) {
  int priority;
  if (FoundDigital(data_d))
    priority = -1;
  else if (data_d == '(' || data_d == ')')
    priority = 0;
  else if (data_d == '+' || data_d == '-')
    priority = 1;
  else if (data_d == '*' || data_d == '/')
    priority = 2;
  else
    priority = 3;  // data_d == '^';
  return priority;
}

void UnaryExpression(const char *str) {
  int k = 0;
  char new_str[255] = "";
  for (int i = 0; i < (int)strlen(str); i++) {
    char symbol = str[i];
    if (symbol == '-' || symbol == '+') {
      if (i == 0) {
        new_str[k] = '0';
        k++;
      } else if (str[i - 1] == '(') {
        new_str[k] = '0';
        k++;
      }
    }
    new_str[k++] = symbol;
  }
  strncpy((char *)str, new_str, strlen(new_str));
}

int TheXInStr(const char *str) {
  int f_result = ERROR;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == 'x') {
      f_result = OK;
      break;
    }
  }
  return f_result;
}

int Calculate(const char *str, double *result, double x) {
  int r_flag = OK;
  if (Checker(str)) {
    UnaryExpression(str);
    *result = Parsing(str, x);
  } else {
    r_flag = ERROR;
  }
  return r_flag;
}

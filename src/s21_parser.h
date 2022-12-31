#ifndef SRC_PARSER_H
#define SRC_PARSER_H

#include "s21_stack.h"
#include "s21_valid.h"

#define ERROR 0
#define OK 1

// int Calculate(const char *str, double *result, double x);

double Parsing(const char *str, double x_number);

int FoundDigital(char symbol);

int FoundSign(char symbol);

int FoundOpenBracket(char symbol);

int FoundCloseBracket(char symbol);

int FoundFunction(type_t type);

int ThisIsSign(int token);

void SetPriority(s_stack **stack);

int GetPriority(char data_d);

void PrintfStackMega(s_stack *list, const char *type_printf);

void CalculateTrigonometry(type_t type, Data_lf first_value, s_stack **tmp);

void CalculateOperation(type_t type, Data_lf first_value, Data_lf second_value,
                        s_stack **ready);

double Calculation(s_stack **ready, Data_lf *result);

int MathExpression(const char *str, size_t *i, s_stack **list);

void UnaryExpression(const char *str);

int FoundSymbol1(char *array, char to_found);

int TheXInStr(const char *str);

int Calculate(const char *str, double *result, double x);

#endif  // SRC_PARSER_H

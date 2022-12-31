#ifndef SRC_S21_STACK_H
#define SRC_S21_STACK_H

//  Libraries  //
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0

typedef enum type_t {
  OpenBracket = 0,
  CloseBrackt,
  Number,
  X,
  Sum,
  Sub = 5,
  Mul,
  Div,
  Pow,
  Cos,
  Sin = 10,
  Tan,
  Acos,
  Asin,
  Atan,
  Sqrt = 15,
  Ln,
  Log,
  Mod,
} type_t;

typedef char Data_d;
typedef double Data_lf;
typedef char *Data_s;

//  Stack  //

typedef struct s_stack {
  Data_d data_d;
  Data_lf data_lf;
  int priority;
  type_t type;
  struct s_stack *next;
} s_stack;

//  Stack functions  //

//  PUSH  //
void push_data_d(Data_d data_d, s_stack **stack);
void push_data_lf(Data_lf, s_stack **stack);
void push_type_t(type_t type, s_stack **stack);
s_stack *push_all(s_stack **_new, s_stack **old);

//  POP  //

Data_d pop_data_d(s_stack **stack);
Data_lf pop_data_lf(s_stack **stack);
type_t pop_type_t(s_stack **stack_t);

// PEEK  //

Data_d peek_data_d(s_stack **stack);
Data_lf peek_data_lf(s_stack **stack);
type_t peek_type_t(s_stack **stack);

//  CHECK EMPTY, REVERSE STACK, REMOVE STACK  //

int is_empty(s_stack **stack);

s_stack *reverse_stack(s_stack **stack);

void printf_stack_mega(s_stack *list, const char *type_printf);

void remove_stack(s_stack *list);

#endif  //  SRC_STACK_H

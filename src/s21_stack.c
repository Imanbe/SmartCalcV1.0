#include "s21_stack.h"

//  PUSH  //

void push_data_d(Data_d data_d, s_stack **stack) {
  s_stack *tmp = (s_stack *)malloc(sizeof(s_stack));
  if (tmp != NULL) {
    tmp->next = *stack;
    tmp->data_d = data_d;
    *stack = tmp;
  }
}

void push_data_lf(Data_lf data_lf, s_stack **stack) {
  s_stack *tmp = (s_stack *)malloc(sizeof(s_stack));
  if (tmp != NULL) {
    tmp->next = *stack;
    tmp->data_lf = data_lf;
    *stack = tmp;
  }
}

void push_type_t(type_t type, s_stack **stack) {
  s_stack *tmp = (s_stack *)malloc(sizeof(s_stack));
  if (tmp != NULL) {
    tmp->next = *stack;
    tmp->type = type;
    *stack = tmp;
  }
}

s_stack *push_all(s_stack **old, s_stack **_new) {
  s_stack *tmp = (s_stack *)malloc(sizeof(s_stack));

  tmp->type = (*old)->type;
  tmp->data_lf = (*old)->data_lf;
  tmp->data_d = (*old)->data_d;
  tmp->priority = (*old)->priority;

  tmp->next = *_new;

  return tmp;
}

//  POP  //

Data_d pop_data_d(s_stack **stack) {
  Data_d data_d;
  s_stack *p = *stack;
  data_d = p->data_d;
  *stack = p->next;
  free(p);
  return data_d;
}

Data_lf pop_data_lf(s_stack **stack) {
  Data_lf data_lf;
  s_stack *p = *stack;
  data_lf = p->data_lf;
  *stack = p->next;
  free(p);
  return data_lf;
}

type_t pop_type_t(s_stack **stack) {
  type_t type;
  s_stack *p = *stack;
  type = p->type;
  *stack = p->next;
  free(p);
  return type;
}

//  PEEK  //

// Data_d peek_data_d(s_stack **stack) {
//   Data_d data = 0;
//   if (!is_empty(stack)) {
//     s_stack *p = *stack;
//     data = p->data_d;
//   }
//   return data;
// }

// Data_lf peek_data_lf(s_stack **stack) {
//   Data_lf data = 0;
//   if (!is_empty(stack)) {
//     s_stack *p = *stack;
//     data = p->data_lf;
//   }
//   return data;
// }

type_t peek_type_t(s_stack **stack) {
  type_t data = -1;
  if (!is_empty(stack)) {
    s_stack *p = *stack;
    data = p->type;
  }
  return data;
}

//  CHECK EMPTY, REVERSE STACK, REMOVE STACK  //

int is_empty(s_stack **stack) { return *stack == NULL; }

s_stack *reverse_stack(s_stack **stack) {
  s_stack *p = *stack;
  s_stack *new = NULL;
  while (p) {
    new = push_all(&p, &new);
    p = p->next;
  }
  return new;
}

void remove_stack(s_stack *list) {
  while (!is_empty(&list)) {
    s_stack *tmp = list;
    list = list->next;
    free(tmp);
  }
}

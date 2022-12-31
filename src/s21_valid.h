#ifndef SRC_VALID_H
#define SRC_VALID_H

#include <math.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

#define CORRECT 0
#define INCORRECT 1

int Checker(const char *str);
void FirstWave(const char *str, int *err);
void FoundSymbol(const char *array, char to_found, int *flag);
void StaplesSmart(const char *str, int *err);
void Expressions(const char *str, int *err);
void IndPlus(const char symbol, char symbol_2, int *index);
void Operators(const char *str, int *err);
void OnlyMod(const char *str, int *err);

#endif  // SRC_VALID_H

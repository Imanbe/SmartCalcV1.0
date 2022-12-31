#include <check.h>

#include "s21_parser.h"

#define C_STRING_SIZE 255

START_TEST(syntax_test) {
  const char str1[C_STRING_SIZE] = "sin()";              // f_result = ERROR
  const char str2[C_STRING_SIZE] = "sin(1)^2+cos(1)^2";  // f_result = OK
  const char str3[C_STRING_SIZE] = "tan(1)/(cos(1)/sin(1))";  // f_result = OK
  const char str4[C_STRING_SIZE] =
      "atan(1)/(acos(1)/asin(1))";  // f_result = OK
  const char str5[C_STRING_SIZE] =
      "sqrt(4)*ln(2)/log(4)*4mod2";  // f_result = OK

  double result = 0.0;
  int count = 0;
  printf("------------------Systax-test-begin------------------\n");

  if (!Calculate(str1, &result, 0.0)) printf("Success!\n"), count++;
  if (Calculate(str2, &result, 0.0)) printf("Success!\n"), count++;
  if (Calculate(str3, &result, 0.0)) printf("Success!\n"), count++;
  if (Calculate(str4, &result, 0.0)) printf("Success!\n"), count++;
  if (Calculate(str5, &result, 0.0)) printf("Success!\n"), count++;

  if (count == 5)
    printf("----------------Systax-test-completed----------------\n\n");
}
END_TEST

START_TEST(result_test) {
  const char str1[C_STRING_SIZE] = "sin(1)^2+cos(1)^2";       // result = 1
  const char str2[C_STRING_SIZE] = "tan(1)*(cos(1)/sin(1))";  // result = 1
  const char str3[C_STRING_SIZE] = "sqrt(4)";                 // result = 2
  const char str4[C_STRING_SIZE] = "2^(2^3)";                 // result = 256
  const char str5[C_STRING_SIZE] = "6-(3^0)+(-3)";            // result = 256
  const char str6[C_STRING_SIZE] = "sqrt(4)+4modx";           // result = 256
  const char str7[C_STRING_SIZE] = "1+x";                     // result = 256

  double result = 0.0;
  int count = 0;
  printf("------------------Result-test-begin------------------\n");
  if (Calculate(str1, &result, 0.0)) {
    if (result == 1) {
      printf("Success!\n"), count++;
    }
  }
  if (Calculate(str2, &result, 0.0)) {
    if (result == 1.0) {
      printf("Success!\n"), count++;
    }
  }
  if (Calculate(str3, &result, 0.0)) {
    if (result == 2.0) {
      printf("Success!\n"), count++;
    }
  }
  if (Calculate(str4, &result, 0.0)) {
    if (result == 256.0) {
      printf("Success!\n"), count++;
    }
  }
  if (Calculate(str5, &result, 0.0)) {
    if (result == 2.0) {
      printf("Success!\n"), count++;
    }
  }
  if (Calculate(str6, &result, 3.0)) {
    if (result == 3.0) {
      printf("Success!\n"), count++;
    }
  }
  if (Calculate(str7, &result, 2.0)) {
    if (result == 3.0) {
      printf("---OK----\n");
      printf("Success!\n"), count++;
    }
  }

  if (count == 7)
    printf("----------------Result-test-completed----------------\n\n");
}

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, syntax_test);
  tcase_add_test(tc1_1, result_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

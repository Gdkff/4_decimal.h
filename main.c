#include "s21_decimal.h"

int main() {
//   float q1 = -7.8e+28;
//   float q2 = 5e+28;
  s21_decimal a;
  float f1 = 1e-29;
  printf("%.100f\n", f1);

  s21_from_float_to_decimal(f1, &a);
  s21_from_decimal_to_float(a, &f1);
  printf("%.100f\n", f1);
  return 0;
}

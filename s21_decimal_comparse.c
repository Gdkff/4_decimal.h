#include "s21_decimal.h"

int s21_is_less_bits(s21_decimal num1, s21_decimal num2) {
  int sol = 0;
  for (int i = 95; i >= 0; i--) {  // идем по мантиссе
    if (!!s21_getbit(num1, i) && !s21_getbit(num2, i)) {  // если 1=1, 2 = 0
      sol = 0;
      break;
    }
    if (!s21_getbit(num1, i) && !!s21_getbit(num2, i)) {  // если 1 = 0, 2 = 1
      sol = 1;
      break;
    }
  }
  return sol;
}

int s21_is_equal_bits(s21_decimal num1, s21_decimal num2) {
  int sol = 1;
  for (int i = 95; i >= 0; i--) {  // идем по мантиссе
    if (!!s21_getbit(num1, i) != !!s21_getbit(num2, i)) {
      sol = 0;
      break;
    }
  }
  return sol;
}

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  int sol = 1, flag = 0;
  s21_decimal nol;
  s21_decimal_null(&nol);

  if (s21_is_equal_bits(nol, num1) && s21_is_equal_bits(nol, num2)) {
    sol = 1;
  } else if (!!s21_getbit(num1, 127) != !!s21_getbit(num2, 127)) {
    sol = 0;
  } else {
    flag = s21_one_scale_comparse(&num1, &num2);
    sol = s21_is_equal_bits(num1, num2);
    if (flag && sol) sol = 0;
  }
  return sol;
}

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  int sol = 0;
  int minus = 0;
  s21_decimal nol;
  s21_decimal_null(&nol);
  if (s21_is_equal_bits(nol, num1) && (s21_is_equal_bits(nol, num2))) {
    sol = 0;
  } else if (!s21_getbit(num1, 127) && s21_getbit(num2, 127)) {
    sol = 0;
  } else if (s21_getbit(num1, 127) && !s21_getbit(num2, 127)) {
    sol = 1;
  } else {
    int flag = 0;
    minus = !!s21_getbit(num1, 127);
    flag = s21_one_scale_comparse(&num1, &num2);
    if (s21_is_equal_bits(num1, num2) && flag == -1) {
      sol = 1;
    } else {
      sol = s21_is_less_bits(num1, num2);
    }
  }
  return minus ? !sol : sol;
}

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_is_equal(num1, num2) || s21_is_less(num1, num2));
}

int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  return (!s21_is_equal(num1, num2) && !s21_is_less(num1, num2));
}

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  return (!s21_is_less(num1, num2));
}

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  return (!s21_is_equal(num1, num2));
}

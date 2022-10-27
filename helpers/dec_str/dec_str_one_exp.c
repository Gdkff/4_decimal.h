#include "../../s21_decimal.h"

void dec_str_zero_exp(str_decimal* value_1, str_decimal* value_2) {
  int big_exp = value_1->exp >= value_2->exp ? value_1->exp : value_2->exp;
  int len1 = strlen(value_1->dec);
  int len2 = strlen(value_2->dec);
  for (int i = 0; i < big_exp; i++) {
    value_1->exp--;
    value_2->exp--;
    if (value_1->exp < 0) {
      value_1->dec[len1++] = '0';
      value_1->dec[len1] = '\0';
      value_1->exp++;
    }
    if (value_2->exp < 0) {
      value_2->dec[len2++] = '0';
      value_2->dec[len2] = '\0';
      value_2->exp++;
    }
  }
}

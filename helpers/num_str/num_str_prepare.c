#include "../../s21_decimal.h"

void num_str_prepare(char* value_1, char* value_2) {
  reverse_str(value_1);
  num_str_delete_right_zeros(value_1);
  reverse_str(value_2);
  num_str_delete_right_zeros(value_2);
  unsigned len_val1 = strlen(value_1);
  unsigned len_val2 = strlen(value_2);
  unsigned len_more = len_val1 < len_val2 ? len_val2 : len_val1;
  unsigned i = len_val1;
  for (; i < len_more + 1; i++) {
    value_1[i] = '0';
  }
  value_1[i] = '\0';
  i = len_val2;
  for (; i < len_more + 1; i++) {
    value_2[i] = '0';
    value_2[i + 1] = '\0';
  }
}

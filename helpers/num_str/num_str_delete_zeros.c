#include "../../s21_decimal.h"

void num_str_delete_right_zeros(char* num_str) {
  if (strcmp("0", num_str)) {
    int i = strlen(num_str) - 1;
    while (num_str[i--] == '0' && i > 0) {
      num_str[i + 1] = '\0';
    }
  }
}

void num_str_delete_all_right_zeros(char* num_str) {
  if (strcmp("0", num_str)) {
    int i = strlen(num_str) - 1;
    while (num_str[i] == '0' && i > 0) {
      num_str[i] = '\0';
      i--;
    }
  }
}

void num_str_delete_left_zeros(char* num_str) {
  reverse_str(num_str);
  num_str_delete_right_zeros(num_str);
  reverse_str(num_str);
}

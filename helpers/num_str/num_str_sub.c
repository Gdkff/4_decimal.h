#include "../../s21_decimal.h"

int num_str_sub_simple(char* value_1, char* value_2, char* result,
                       int num_system) {
  char val1[340];
  char val2[340];
  snprintf(val1, sizeof(val1), "%s", value_1);
  snprintf(val2, sizeof(val2), "%s", value_2);
  num_str_prepare(val1, val2);
  unsigned len = strlen(value_1);
  unsigned i = 0;
  int temp_res = 0;
  int add_razr = 0;
  for (; i < len; i++) {
    temp_res = val1[i] - val2[i] - add_razr;

    if (temp_res < 0) {
      temp_res = num_system + temp_res;
      add_razr = 1;
    } else {
      add_razr = 0;
    }
    result[i] = temp_res % num_system + '0';
    result[i + 1] = '\0';
  }
  num_str_delete_right_zeros(result);
  reverse_str(result);
  return 0;
}

#include "../../s21_decimal.h"

int num_str_mul(char* value_1, char* value_2, char* result, int num_system) {
  char temp_res[350];
  int temp_num = 0, add_razr = 0;
  char val1[340] = {'\0'};
  char val2[340] = {'\0'};
  snprintf(val1, sizeof(val1), "%s", value_1);
  snprintf(val2, sizeof(val2), "%s", value_2);
  reverse_str(val1);
  reverse_str(val2);
  snprintf(result, sizeof(val1), "0");
  int i1, i2, pl;
  for (i2 = 0; val2[i2]; i2++) {
    if (val2[i2] != '0') {
      add_razr = 0;
      for (pl = 0; pl < i2; pl++) {
        temp_res[pl] = '0';
      }
      for (i1 = 0; val1[i1]; i1++) {
        temp_num = (val1[i1] - '0') * (val2[i2] - '0') + add_razr;
        temp_res[pl++] = temp_num % num_system + '0';
        add_razr = temp_num / num_system;
      }
      if (add_razr) temp_res[pl++] = add_razr + '0';
      temp_res[pl] = '\0';
      reverse_str(temp_res);
      num_str_add(temp_res, result, result, num_system);
    }
  }
  return 0;
}

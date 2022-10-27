#include "../../s21_decimal.h"

int num_str_is_greater(char* str1, char* str2) {
  int ret = 0;
  char str1_temp[340];
  char str2_temp[340];
  snprintf(str1_temp, sizeof(str1_temp), "%s", str1);
  snprintf(str2_temp, sizeof(str2_temp), "%s", str2);
  num_str_prepare(str1_temp, str2_temp);
  int len = strlen(str1_temp);
  for (int i = len - 1; i >= 0; i--) {
    if (str1_temp[i] > str2_temp[i]) {
      ret = 1;
      break;
    } else if (str1_temp[i] < str2_temp[i]) {
      break;
    }
  }
  return ret;
}

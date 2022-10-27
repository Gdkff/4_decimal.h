#include "../../s21_decimal.h"

void reverse_str(char* str) {
  int len = strlen(str);
  char temp_str[340];
  for (int j = 0; str[j]; j++) {
    temp_str[j] = str[len - j - 1];
  }
  temp_str[len] = '\0';
  snprintf(str, sizeof(temp_str), "%s", temp_str);
}

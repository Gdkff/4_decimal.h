#include "../../s21_decimal.h"

int num_str_mod(char *value_1, char *value_2, char *result) {
  int delimoe_pos = 0;
  char temp_delimoe[340];
  snprintf(temp_delimoe, sizeof(temp_delimoe), "0");
  size_t i = 0;
  for (; i < strlen(value_1); i++) {
    temp_delimoe[delimoe_pos] = value_1[i];
    temp_delimoe[delimoe_pos + 1] = '\0';
    while (num_str_is_greater_or_equal(temp_delimoe, value_2)) {
      num_str_sub_simple(temp_delimoe, value_2, temp_delimoe, 10);
    }
    delimoe_pos = strlen(temp_delimoe);
  }
  snprintf(result, sizeof(temp_delimoe), "%s", temp_delimoe);
  return 0;
}

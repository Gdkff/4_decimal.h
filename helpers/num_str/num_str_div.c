#include "../../s21_decimal.h"

int num_str_div(char *value_1, char *value_2, char *result) {
  char temp_delimoe[340] = {'\0'};
  int num_to_result = 0, delimoe_pos = 0;
  size_t i = 0;
  // деление целой части
  for (; i < strlen(value_1); i++) {
    temp_delimoe[delimoe_pos] = value_1[i];
    temp_delimoe[delimoe_pos + 1] = '\0';
    num_to_result = 0;
    for (; num_str_is_greater_or_equal(temp_delimoe, value_2);
         num_to_result++) {
      num_str_sub_simple(temp_delimoe, value_2, temp_delimoe, 10);
    }
    delimoe_pos = strlen(temp_delimoe);
    result[i] = num_to_result + '0';
    result[i + 1] = '\0';
    // printf("%d", num_to_result);
  }
  result[i] = '\0';
  num_str_delete_left_zeros(result);
  i = strlen(result);
  // printf(".");

  // if (num_str_is_greater(temp_delimoe, zero)) result[i++] = '.';

  // деление дробной части
  int exp = 0;
  for (; i < 30 && !num_str_is_equal(temp_delimoe, "0"); i++) {
    delimoe_pos = strlen(temp_delimoe);
    temp_delimoe[delimoe_pos] = '0';
    temp_delimoe[delimoe_pos + 1] = '\0';
    num_to_result = 0;
    for (; num_str_is_greater_or_equal(temp_delimoe, value_2);
         num_to_result++) {
      num_str_sub_simple(temp_delimoe, value_2, temp_delimoe, 10);
    }
    delimoe_pos = strlen(temp_delimoe);
    result[i] = num_to_result + '0';
    exp++;
    // printf("%d", num_to_result);
  }
  result[i] = '\0';
  // printf("\n");
  return exp;
}

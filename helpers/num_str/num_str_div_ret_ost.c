#include "../../s21_decimal.h"

unsigned div_by_int_ret_ost(char* delimoe, int devisor, int num_system,
                            char* result) {
  unsigned temp_del = 0;
  unsigned pos_res = 0;
  for (int i = 0; delimoe[i]; i++) {
    temp_del = temp_del * num_system + delimoe[i] - '0';
    result[pos_res++] = (unsigned)(temp_del / devisor) + '0';

    temp_del -= devisor * (unsigned)(temp_del / devisor);
  }
  result[pos_res] = '\0';
  num_str_delete_left_zeros(result);
  return temp_del;
}

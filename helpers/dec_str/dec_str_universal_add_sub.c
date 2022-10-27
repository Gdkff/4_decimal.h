#include "../../s21_decimal.h"

int dec_str_universal_add_sub(str_decimal value_1, str_decimal value_2,
                              str_decimal* result) {
  char t1[340], t2[340];
  result->exp = value_1.exp > value_2.exp ? value_1.exp : value_2.exp;
  dec_str_zero_exp(&value_1, &value_2);
  if ((value_1.sign + value_2.sign) % 2 == 1) {
    if (num_str_is_greater(value_1.dec, value_2.dec)) {
      snprintf(t1, sizeof(t1), "%s", value_1.dec);
      snprintf(t2, sizeof(t2), "%s", value_2.dec);
      result->sign = value_1.sign;
    } else {
      snprintf(t1, sizeof(t1), "%s", value_2.dec);
      snprintf(t2, sizeof(t2), "%s", value_1.dec);
      result->sign = value_2.sign;
    }
    num_str_sub_simple(&t1[0], &t2[0], result->dec, 10);
  } else {
    snprintf(t1, sizeof(t1), "%s", value_1.dec);
    snprintf(t2, sizeof(t2), "%s", value_2.dec);
    result->sign = value_1.sign;
    num_str_add(&t1[0], &t2[0], result->dec, 10);
  }
  int err = dec_str_pack_result(result);
  return err;
}

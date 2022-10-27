#include "../../s21_decimal.h"

int dec_str_div(str_decimal* value_1, str_decimal* value_2,
                str_decimal* result) {
  int err = 0;
  str_decimal_to_zero(result);
  if (num_str_is_equal(value_2->dec, "0")) err = 3;
  if (!err) {
    result->sign = (value_1->sign + value_2->sign) % 2;
    result->exp = value_1->exp - value_2->exp;
    result->exp += num_str_div(value_1->dec, value_2->dec, result->dec);
    err = dec_str_pack_result(result);
  }
  return err;
}

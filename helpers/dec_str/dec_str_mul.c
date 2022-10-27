#include "../../s21_decimal.h"

int dec_str_mul(str_decimal* value_1, str_decimal* value_2,
                str_decimal* result) {
  str_decimal_to_zero(result);
  result->sign = (value_1->sign + value_2->sign) % 2;
  result->exp = value_1->exp + value_2->exp;
  num_str_mul(value_1->dec, value_2->dec, result->dec, 10);
  int err = dec_str_pack_result(result);
  return err;
}

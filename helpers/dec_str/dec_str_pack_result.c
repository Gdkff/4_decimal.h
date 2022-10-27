#include "../../s21_decimal.h"

int dec_str_pack_result(str_decimal* result) {
  int err = 0;
  if (num_str_is_equal(result->dec, "0")) {
    result->exp = 0;
  } else {
    int len = strlen(result->dec);
    char temp[340];
    while (result->exp < 0) {
      result->dec[len++] = '0';
      result->dec[len] = '\0';
      result->exp++;
    }
    int round = -1;
    snprintf(temp, sizeof(temp), "%s", result->dec);
    while (num_str_is_greater(temp, "79228162514264337593543950335") &&
           result->exp > 0) {
      snprintf(temp, sizeof(temp), "%s", result->dec);
      num_str_bank_round(temp, round--);
      result->exp--;
    }
    snprintf(result->dec, sizeof(result->dec), "%s", temp);
    round = -1;
    while (!num_str_is_equal(temp, "0") && result->exp > 28) {
      snprintf(temp, sizeof(temp), "%s", result->dec);
      num_str_bank_round(temp, round--);
      result->exp--;
    }
    snprintf(result->dec, sizeof(result->dec), "%s", temp);
    if (num_str_is_greater(temp, "79228162514264337593543950335")) {
      str_decimal_to_zero(result);
      err = 1;
    }
    if (result->exp > 28) {
      str_decimal_to_zero(result);
      err = 2;
    }
  }
  return err;
}

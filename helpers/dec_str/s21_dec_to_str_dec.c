#include "../../s21_decimal.h"

void s21_dec_to_bit_str(s21_decimal* in, char* out) {
  int razr = 0;
  int ost = 0;
  for (int i = 0; i < 96; i++) {
    razr = i / 32;
    ost = i % 32;
    out[i] = (in->bits[razr] >> ost & 1) + '0';
  }
  out[96] = '\0';
}

short s21_dec_exp_to_short(s21_decimal* in) {
  short ret = 0;
  for (int i = 16; i <= 23; i++) {
    ret |= ((in->bits[3] >> i) & 1) << (i - 16);
  }
  return ret;
}

void bit_str_to_str_dec(char* in, char* out) {
  int len = strlen(in);
  char res[340], exp2[340];
  snprintf(exp2, sizeof(exp2), "1");
  snprintf(res, sizeof(res), "0");
  for (int i = 0; i < len; i++) {
    if (in[i] == '1') {
      num_str_add(&res[0], &exp2[0], &res[0], 10);
    }
    num_str_mul(&exp2[0], "2", &exp2[0], 10);
  }
  snprintf(out, sizeof(res), "%s", &res[0]);
}

int s21_dec_to_str_dec(s21_decimal in, str_decimal* out) {
  str_decimal_to_zero(out);
  if (in.bits[3] >> 31 & 1) out->sign = 1;
  char temp[340] = {0};
  out->exp = s21_dec_exp_to_short(&in);
  s21_dec_to_bit_str(&in, &temp[0]);
  bit_str_to_str_dec(&temp[0], &temp[0]);
  reverse_str(temp);
  num_str_delete_all_right_zeros(temp);
  reverse_str(temp);
  snprintf(out->dec, sizeof(out->dec), "%s", &temp[0]);
  return 0;
}

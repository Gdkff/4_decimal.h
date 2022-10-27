#include "../../s21_decimal.h"

int str_dec_to_s21_dec(str_decimal in, s21_decimal* out) {
  for (int i = 0; i < 4; i++) out->bits[i] = 0;
  char temp_str[340];
  from_str_to_binary(in.dec, temp_str, 10);
  int razr = 0;
  int ost = 0;
  for (int i = 0; temp_str[i]; i++) {
    razr = i / 32;
    ost = i % 32;
    out->bits[razr] |= (temp_str[i] - '0') << ost;
  }
  for (int i = 0; i < 8; i++) {
    out->bits[3] |= (in.exp >> i & 1) << (i + 16);
  }
  if (in.sign) {
    out->bits[3] |= 1 << 31;
  }
  return 0;
}

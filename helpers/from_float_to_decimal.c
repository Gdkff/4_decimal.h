#include "../s21_decimal.h"

void str_decimal_to_zero(str_decimal *str_dec) {
  str_dec->dec[0] = '\0';
  str_dec->sign = 0;
  str_dec->exp = 0;
}

// short read_float_exponent(float num) {
//   short result = 0;
//   int *temp = (int *)&num;
//   for (int i = 30; i > 22; --i) {
//     result = (result << 1) | ((*temp) >> i & 1);
//   }
//   return result - 127;
// }

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {
//   int ret = 0;
//   str_decimal str_dec;
//   for (int i = 0; i < 4; i++) dst->bits[i] = 0;
//   if (dst == NULL || src - src != 0) {
//     ret = 1;
//     // printf("BAD FLOAT2\n");
//   } else {
//     if (src != 0) {
//       int err = float_to_str_dec(src, &str_dec);
//       if (err) {
//         // printf("BAD FLOAT3\n");
//         ret = 1;
//       } else {
//         str_dec_to_s21_dec(str_dec, dst);
//       }
//     }
//   }
//   return ret;
// }

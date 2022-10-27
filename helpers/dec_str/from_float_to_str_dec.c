#include "../../s21_decimal.h"

// void str_dec_normalizator(char *str_dec, int *exp) {
//   // printf("normo in: %s\n", str_dec);
//   int pos = strlen(str_dec) - 1;
//   if (*exp) {
//     while (str_dec[pos] == '0' && *exp > 0) {
//       str_dec[pos--] = '\0';
//       (*exp)--;
//     }
//   }
//   pos = 0;
//   while (str_dec[pos++] == '0') {
//   }
//   pos--;
//   int start = 0;
//   while (str_dec[pos]) {
//     str_dec[start++] = str_dec[pos++];
//   }
//   str_dec[start] = '\0';
//   // printf("normo out: %s\n", str_dec);
// }

// int float_to_str_dec(float num, str_decimal *str_dec) {
//   int ret = 0;
//   str_decimal_to_zero(str_dec);
//   if (num < 0) {
//     str_dec->sign = 1;
//     num = -num;
//   }
//   if (num - num != 0 || num < 1e-28 || read_float_exponent(num) > 95) {
//     // printf("BAD FLOAT\n");
//     str_dec->sign = 0;
//     ret = 1;
//   } else {
//     sprintf(&str_dec->dec[0], "%.28f", num);
//     int point = 0, position = 0;
//     for (int i = 0; str_dec->dec[i]; i++) {
//       if (str_dec->dec[i] == '.') {
//         point = i;
//         break;
//       }
//     }
//     sprintf(&str_dec->dec[0], "%.*f", 29 - point, num);
//     for (int i = 0; str_dec->dec[i] && position < 29; i++) {
//       if (i == point) {
//         continue;
//       }
//       str_dec->dec[position++] = str_dec->dec[i];
//       if (point < i) str_dec->exp++;
//     }
//     str_dec->dec[position] = '\0';
//     str_dec_normalizator(&str_dec->dec[0], &str_dec->exp);
//   }
//   return ret;
// }

void from_str_to_binary(char *in, char *out, int in_num_system) {
  char temp_str[1024] = {'\0'};
  out[0] = '0';
  out[1] = '\0';
  int ostatok = 0;
  snprintf(temp_str, sizeof(temp_str), "%s", in);
  int i = 0;
  while (num_str_is_greater(temp_str, "0")) {
    ostatok = div_by_int_ret_ost(temp_str, 2, in_num_system, temp_str);
    out[i++] = ostatok + '0';
    out[i] = '\0';
  }
}

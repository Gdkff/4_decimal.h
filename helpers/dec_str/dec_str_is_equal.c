// #include "../../s21_decimal.h"

// int dec_str_is_equal(str_decimal* dec1, str_decimal* dec2) {
//   int ret = 0;
//   int exp_move = 0;
//   char temp_str1[340] = {'\0'}, temp_str2[340] = {'\0'};
//   strcpy(temp_str1, dec1->dec);
//   strcpy(temp_str2, dec2->dec);
//   if (dec1->sign == 0 && dec2->sign == 1) {
//     ret = 1;
//   } else if (dec1->sign == dec2->sign) {
//     int i = 0, len = 0;
//     if (dec1->exp > dec2->exp) {
//       exp_move = dec1->exp - dec2->exp;
//       // printf("exp move: %d, dec1_exp: %d, dec2_exp: %d\n", exp_move,
//       dec1->exp,
//       //        dec2->exp);
//       len = strlen(dec2->dec);
//       for (i = len; i < len + exp_move; i++) {
//         dec2->dec[i] = '0';
//       }
//       dec2->dec[i] = '\0';
//     } else if (dec2->exp > dec1->exp) {
//       exp_move += dec2->exp - dec1->exp;
//       len = strlen(dec1->dec);
//       for (i = len; i < len + exp_move; i++) {
//         dec1->dec[i] = '0';
//       }
//       dec1->dec[i] = '\0';
//     }
//     if (dec1->sign == 0 && dec2->sign == 0) {
//       ret = num_str_is_greater(dec1->dec, dec2->dec);
//     } else {
//       ret = num_str_is_greater(dec2->dec, dec1->dec);
//     }
//   }
//   return ret;
// }

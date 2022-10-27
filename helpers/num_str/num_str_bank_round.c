#include "../../s21_decimal.h"

void num_str_bank_round(char *num_str, int position) {
  // даем строку-число и позицию цифры с конца строки (-1 - последняя цифра,
  // -2 - вторая с конца), по которой будет округление и обрезка строки
  size_t len = strlen(num_str);
  position = len + position;
  if (num_str[position] - '0' > 5 || (num_str[position] - '0' == 5 &&
                                      (num_str[position - 1] - '0') % 2 == 1)) {
    for (int i = position - 1; i > 0; i--) {
      if (num_str[i] == '9') {
        num_str[i] = '0';
      } else {
        num_str[i] += 1;
        break;
      }
    }
  }
  num_str[position] = '\0';
}

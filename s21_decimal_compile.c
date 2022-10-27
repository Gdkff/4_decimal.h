
#include "s21_decimal.h"

static int s21_float_scale(float src);
static int s21_is_min_int(int a);

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) return 1;
  if (s21_is_min_int(src)) {
    dst->bits[0] = src;
    s21_setbit(dst, 127);
    return 0;
  }
  s21_decimal_null(dst);
  int minus = 0;
  if (src < 0) {
    minus = 1;
    src *= -1;
  }
  dst->bits[0] = src;
  if (minus) s21_setbit(dst, SCALE * 32 + 31);
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL) return 1;
  int minus = 1;
  s21_truncate(src, &src);
  if (s21_is_min_int(src.bits[0]) && s21_getbit(src, 127)) {
    *dst = src.bits[0];
    return 0;
  }
  if (s21_getbit(src, SCALE * 32 + 31)) {
    minus = -1;
    s21_inversebit(&src, SCALE * 32 + 31);
  }
  for (int i = 31; i < 96; i++) {
    if (s21_getbit(src, i)) return 1;
  }
  *dst = src.bits[0] * minus;
  return 0;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (dst == NULL) return 1;
  int minus = 1;
  long double result = 0, two = 1;
  if ((s21_getbit(src, 127))) minus = -1;
  for (int k = 0; k < 96; k++) {
    if (s21_getbit(src, k)) {
      result += two;
    }
    two *= 2;
  }
  for (int k = 0; k < s21_getscale(src); k++) {
    result /= 10;
  }
  *dst = minus * result;
  return 0;
}

static int s21_float_scale(float src) {
  union dec chislo;
  int sol = 0;
  s21_decimal_null(&chislo.in);
  if (src < 0) src *= -1;
  chislo.fl = src;
  sol = chislo.inn >> 23;
  return sol - 127;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_decimal_null(dst);
  if (src >= DECIMAL_MAX || src <= -DECIMAL_MAX || isnan(src)) {
    return 1;
  }
  if (fabs(src) < 1e-28 && fabs(src) > 0) return 1;
  int sol = 0, fexp = 0, minus = 0;
  union dec chislo;
  s21_decimal_null(&chislo.in);
  if (src < 0) {
    minus = 1;
    src = -src;
  }
  chislo.fl = src;
  for (int i = 0; i < 23; i++) {
    if (s21_getbit(chislo.in, i)) s21_setbit(dst, i);
  }
  s21_setbit(dst, 23);
  fexp = 23 - s21_float_scale(src);
  while (fexp > 0) {
    while (!s21_getbit(*dst, 0) && fexp) {
      right_shift(dst, 1);
      fexp--;
    }
    if (!fexp) break;
    s21_mnog_ten(dst);
    s21_setscale(dst, s21_getscale(*dst) + 1);
    if (s21_getscale(*dst) >= 28) break;
  }
  right_shift(dst, fexp);
  if (minus) s21_setbit(dst, SCALE * 32 + 31);
  return sol;
}

void right_shift(s21_decimal *num, int c) {
  while (c > 0) {
    for (int i = 0; i < 95; i++) {
      if (s21_getbit(*num, i + 1)) {
        s21_setbit(num, i);
      } else {
        s21_setbit(num, i);
        s21_inversebit(num, i);
      }
    }
    s21_setbit(num, 95);
    s21_inversebit(num, 95);
    c--;
  }
  while (c < 0) {
    for (int i = 95; i > 0; i--) {
      if (s21_getbit(*num, i - 1)) {
        s21_setbit(num, i);
      } else {
        s21_setbit(num, i);
        s21_inversebit(num, i);
      }
    }
    s21_setbit(num, 0);
    s21_inversebit(num, 0);
    c++;
  }
}

static int s21_is_min_int(int a) {
  int sol = 1;
  union dec buff;
  buff.inn = a;
  if (!s21_getbit(buff.in, 31)) {
    sol = 0;
  } else {
    for (int i = 0; i < 31; i++) {
      if (s21_getbit(buff.in, i)) {
        sol = 0;
        break;
      }
    }
  }
  return sol;
}

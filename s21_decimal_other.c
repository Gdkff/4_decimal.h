#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
    int sol = 0;
    if (result == NULL) sol = 1;
    if (!sol) {
        s21_decimal_copy(value, result);
        s21_inversebit(result, 127);
    }
    return sol;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
    int sol = 0;
    int minus = 0;
    if (result == NULL) sol = 1;
    if (!sol) {
        if (s21_getbit(value, 127)) {
            minus = 1;
            s21_inversebit(&value, 127);
        }
        int scale = s21_getscale(value);
        for (; scale > 0; scale--) {
            s21_del_ten(&value);
            s21_setscale(&value, s21_getscale(value)-1);
        }
        s21_decimal_copy(value, result);
        if (minus) s21_setbit (result, SCALE*32 + 31);
    }
    return sol;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
    int sol = 0;
    int buff = 0;
    if (result == NULL) sol = 1;
    if (!sol) {
        int scale = s21_getscale(value);
        int minus = s21_getbit(value, 127);
        for (; scale > 0; scale--) {
            buff += s21_del_ten(&value);
        }
        s21_setscale(&value, 0);
        if (buff && minus) {
            s21_from_int_to_decimal(1, result);
            s21_add_bit(value, *result, &value);
        }
        s21_decimal_copy(value, result);
        if (minus) s21_setbit(result, 127);
    }
    return sol;
}

int s21_round(s21_decimal value, s21_decimal *result) {
    int sol = 0;
    if (result == NULL) sol = 1;
    if (!sol) {
        s21_decimal one, five, mod_ten, ten;
        s21_from_int_to_decimal(1, &one);
        s21_from_int_to_decimal(5, &five);
        s21_from_int_to_decimal(10, &ten);

        s21_div(five, ten, &five);
        s21_mod(value, one, &mod_ten);

        s21_truncate(value, &value);
        s21_setbit(&mod_ten, 127);
        s21_inversebit(&mod_ten, 127);

        if (s21_is_less_or_equal(five, mod_ten)) {
            if (!s21_getbit(value, 127)) {
                s21_add(value, one, &value);
            } else {
                s21_sub(value, one, &value);
            }
        }
        s21_decimal_copy(value, result);
    }
    return sol;
}

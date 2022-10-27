#include "s21_decimal.h"

int s21_add_bit(s21_decimal num1, s21_decimal num2, s21_decimal *ans) {
    int sol = 0;
    int bit_buf = 0;
    s21_decimal_null(ans);

    for (int i = 0; i < 96; i++) {              // складываем буферы
        bit_buf += (!!s21_getbit(num1, i)) + (!!s21_getbit(num2, i));       // складываем биты
        if (bit_buf % 2 == 1) {     // если стоит 1 или 3 бита то мы проставляем бит
            s21_setbit(ans, i);
        }
        if (bit_buf == 1) {
            bit_buf = 0;
        }
        if (bit_buf > 1) {                      // уменьшаем количество, которое нужно проставить
            bit_buf = 1;
        }
    }
    if (bit_buf > 0) sol = 1;
    return sol;
}

int s21_sub_bit(s21_decimal num1, s21_decimal num2, s21_decimal *ans) {
    int sol = 0;
    // int flag = 1;
    int buf = 0;
    s21_decimal_null(ans);
    if (s21_is_less_bits(num1, num2)) sol = 1;

    for (int i = 0; i < 96; i++) {          // идем по числу
        if (s21_getbit(num2, i)) buf++;     // если в вычитаемом есть бит то прибавляем к вычитаемому
        if (buf) {                          // смотрим, нужно ли вычитать
            if (s21_getbit(num1, i)) {      // если бит есть то нужно ег занулить и уменьшить вычитаемое
                if (buf % 2 == 1) s21_inversebit(&num1, i);
                if (buf == 1) buf = 0;
                if (buf > 1) buf = 1;
            } else {                        // если нет то просто меняем бит
                if (buf % 2 == 1) s21_inversebit(&num1, i);
                if (buf > 1) buf = 1;
            }
        }
    }
    for (int i = 0; i < 96; i++) {
        if (s21_getbit(num1, i)) s21_setbit(ans, i);
    }
    return sol;
}

int s21_mnog_ten(s21_decimal * num) {
    int sol = 0;
    s21_decimal d_buff;
    int scale = s21_getscale(*num);
    int minus = s21_getbit(*num, 127);
    s21_decimal_copy(*num, &d_buff);
    s21_decimal buf1, buf2;
    if ((s21_getbit(*num, 95)) ||  \
            (s21_getbit(*num, 94)) || (s21_getbit(*num, 93))) {       // если число большое то не умножим
        sol = 1;
    } else {
        s21_decimal_null(&buf1);
        s21_decimal_null(&buf2);
        for (int i = 92; i >= 0; i--) {
            if (s21_getbit(*num, i)) {
                s21_setbit(&buf1, i+1);             // делаем буфер * 2
                s21_setbit(&buf2, i+3);             // делаем буфер * 8
            }
        }
        s21_decimal_null(num);

        sol = s21_add_bit(buf1, buf2, num);
    }
    if (sol) s21_decimal_copy(d_buff, num);
    s21_setscale(num, scale);
    if (minus) {
        s21_setbit(num, 127);
    } else {
        s21_setbit(num, 127);
        s21_inversebit(num, 127);
    }
    return sol;
}

int s21_del_ten(s21_decimal * num) {
    int sol = 0;
    int scale = s21_getscale(*num);
    int flag = 27;
    int minus = s21_getbit(*num, 127);
    s21_decimal ans, ten, nol, one;
    s21_decimal d_buff;

    s21_decimal_copy(*num, &d_buff);

    s21_decimal_null(&nol);
    s21_decimal_null(&ans);
    s21_decimal_ten(&ten, flag);
    s21_decimal_ten(&one, flag-1);


    while (flag > 0) {
        if (s21_is_less_bits(*num, ten)) {
            flag--;
            s21_decimal_ten(&ten, flag);
            s21_decimal_ten(&one, flag-1);
            continue;
        }
        s21_sub_bit(*num, ten, num);
        s21_add_bit(ans, one, &ans);
    }
    if (!s21_is_equal_bits(nol, *num)) sol = 1;

    s21_decimal_copy(ans, num);
    s21_setscale(num, scale);
    if (minus) s21_setbit(num, 127);
    return sol;
}

int s21_one_scale_comparse(s21_decimal * num1, s21_decimal * num2) {
    int znak1 = s21_getbit(*num1, 127);
    int znak2 = s21_getbit(*num2, 127);
    int sc1 = s21_getscale(*num1);
    int sc2 = s21_getscale(*num2);
    int flag = 1, sol = 0;
    while (flag && abs(sc1-sc2)) {
        if (sc1 < sc2) {
            flag = !s21_mnog_ten(num1);
            if (!flag) continue;
            s21_setscale(num1, s21_getscale(*num1)+1);
            sc1 = s21_getscale(*num1);
        } else {
            flag = !s21_mnog_ten(num2);
            if (!flag) continue;
            s21_setscale(num2, s21_getscale(*num2)+1);
            sc2 = s21_getscale(*num2);
        }
    }
    while (abs(sc1 - sc2)) {
        if (sc1 < sc2) {
            sol = (s21_del_ten(num2) || sol);
            s21_setscale(num2, s21_getscale(*num2)-1);
            sc2 = s21_getscale(*num2);
        } else {
            sol = (s21_del_ten(num1) || sol);
            s21_setscale(num1, s21_getscale(*num1)-1);
            sol = -1 * abs(sol);
            sc1 = s21_getscale(*num1);
        }
    }
    if (znak1) s21_setbit(num1, 127);
    if (znak2) s21_setbit(num2, 127);
    return sol;
}

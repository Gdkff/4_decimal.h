#include "s21_decimal.h"

int s21_decimal_ten(s21_decimal *num, int count) {
    s21_decimal_null(num);
    switch (count) {
    case 1:
        s21_setbit(num, 1);
        s21_setbit(num, 3);
        break;
    case 2:
        s21_setbit(num, 2);
        s21_setbit(num, 5);
        s21_setbit(num, 6);
        break;
    case 3:
        s21_setbit(num, 3);
        s21_setbit(num, 5);
        s21_setbit(num, 6);
        s21_setbit(num, 7);
        s21_setbit(num, 8);
        s21_setbit(num, 9);
        break;
    case 4:
        s21_setbit(num, 4);
        s21_setbit(num, 8);
        s21_setbit(num, 9);
        s21_setbit(num, 10);
        s21_setbit(num, 13);
        break;
    case 5:
        s21_setbit(num, 5);
        s21_setbit(num, 7);
        s21_setbit(num, 9);
        s21_setbit(num, 10);
        s21_setbit(num, 15);
        s21_setbit(num, 16);
        break;
    case 6:
        s21_setbit(num, 6);
        s21_setbit(num, 9);
        s21_setbit(num, 14);
        s21_setbit(num, 16);
        s21_setbit(num, 17);
        s21_setbit(num, 18);
        s21_setbit(num, 19);
        break;
    case 7:
        s21_setbit(num, 7);
        s21_setbit(num, 9);
        s21_setbit(num, 10);
        s21_setbit(num, 12);
        s21_setbit(num, 15);
        s21_setbit(num, 19);
        s21_setbit(num, 20);
        s21_setbit(num, 23);
        break;
    case 8:
        s21_setbit(num, 8);
        s21_setbit(num, 13);
        s21_setbit(num, 14);
        s21_setbit(num, 15);
        s21_setbit(num, 16);
        s21_setbit(num, 18);
        s21_setbit(num, 20);
        s21_setbit(num, 21);
        s21_setbit(num, 22);
        s21_setbit(num, 23);
        s21_setbit(num, 24);
        s21_setbit(num, 26);
        break;
    case 9:
        s21_setbit(num, 9);
        s21_setbit(num, 11);
        s21_setbit(num, 14);
        s21_setbit(num, 15);
        s21_setbit(num, 17);
        s21_setbit(num, 19);
        s21_setbit(num, 20);
        s21_setbit(num, 23);
        s21_setbit(num, 24);
        s21_setbit(num, 25);
        s21_setbit(num, 27);
        s21_setbit(num, 28);
        s21_setbit(num, 29);
        break;
    case 10:
        s21_setbit(num, 10);
        s21_setbit(num, 13);
        s21_setbit(num, 14);
        s21_setbit(num, 15);
        s21_setbit(num, 16);
        s21_setbit(num, 17);
        s21_setbit(num, 19);
        s21_setbit(num, 26);
        s21_setbit(num, 28);
        s21_setbit(num, 30);
        s21_setbit(num, 33);
        break;
    case 11:
        s21_setbit(num, 11);
        s21_setbit(num, 13);
        s21_setbit(num, 14);
        s21_setbit(num, 15);
        s21_setbit(num, 17);
        s21_setbit(num, 18);
        s21_setbit(num, 20);
        s21_setbit(num, 21);
        s21_setbit(num, 22);
        s21_setbit(num, 27);
        s21_setbit(num, 30);
        s21_setbit(num, 32);
        s21_setbit(num, 33);
        s21_setbit(num, 34);
        s21_setbit(num, 36);
        break;
    case 12:
        s21_setbit(num, 12);
        s21_setbit(num, 16);
        s21_setbit(num, 18);
        s21_setbit(num, 21);
        s21_setbit(num, 23);
        s21_setbit(num, 26);
        s21_setbit(num, 28);
        s21_setbit(num, 30);
        s21_setbit(num, 31);
        s21_setbit(num, 35);
        s21_setbit(num, 37);
        s21_setbit(num, 38);
        s21_setbit(num, 39);
        break;
    case 13:
        s21_setbit(num, 13);
        s21_setbit(num, 15);
        s21_setbit(num, 17);
        s21_setbit(num, 20);
        s21_setbit(num, 21);
        s21_setbit(num, 22);
        s21_setbit(num, 25);
        s21_setbit(num, 26);
        s21_setbit(num, 27);
        s21_setbit(num, 30);
        s21_setbit(num, 35);
        s21_setbit(num, 36);
        s21_setbit(num, 40);
        s21_setbit(num, 43);
        break;
    case 14:
        s21_decimal_ten(num, 13);
        s21_mnog_ten(num);
        break;
    case 15:
        s21_decimal_ten(num, 14);
        s21_mnog_ten(num);
        break;
    case 16:
        s21_decimal_ten(num, 15);
        s21_mnog_ten(num);
        break;
    case 17:
        s21_decimal_ten(num, 16);
        s21_mnog_ten(num);
        break;
    case 18:
        s21_decimal_ten(num, 17);
        s21_mnog_ten(num);
        break;
    case 19:
        s21_decimal_ten(num, 18);
        s21_mnog_ten(num);
        break;
    case 20:
        s21_decimal_ten(num, 19);
        s21_mnog_ten(num);
        break;
    case 21:
        s21_decimal_ten(num, 20);
        s21_mnog_ten(num);
        break;
    case 22:
        s21_decimal_ten(num, 21);
        s21_mnog_ten(num);
        break;
    case 23:
        s21_decimal_ten(num, 22);
        s21_mnog_ten(num);
        break;
    case 24:
        s21_decimal_ten(num, 23);
        s21_mnog_ten(num);
        break;
    case 25:
        s21_decimal_ten(num, 24);
        s21_mnog_ten(num);
        break;
    case 26:
        s21_decimal_ten(num, 25);
        s21_mnog_ten(num);
        break;
    case 27:
        s21_decimal_ten(num, 26);
        s21_mnog_ten(num);
        break;
    case 28:
        s21_decimal_ten(num, 27);
        s21_mnog_ten(num);
        break;
    default:
        s21_setbit(num, 0);
        break;
    }
    return 0;
}

#include "s21_decimal.h"

int s21_getrow(int i) {
    return i / 32;
}

int s21_getcol(int i) {
    return i % 32;
}

int s21_getbit(s21_decimal number, int i) {
    unsigned int mask = 1 << (s21_getcol(i));
    return number.bits[s21_getrow(i)] & mask;
}

int s21_setbit(s21_decimal * number, int i) {
    unsigned int mask = 1 << (s21_getcol(i));
    number->bits[s21_getrow(i)] |= mask;
    return 0;
}

int s21_inversebit(s21_decimal * number, int i) {
    unsigned int mask = 1 << (s21_getcol(i));
    number->bits[s21_getrow(i)] ^= mask;
    return 0;
}

// void s21_dprint(s21_decimal * number) {
//     for (int i = 127; i >=0; i--) {
//         printf("%d", !!s21_getbit(*number, i));
//         if ((i) % 32 == 0) printf(" ");
//     }
//     printf("\n");

//     printf("Num:\nLOW=%u\nMID=%u\nHIGH=%u\n", number->bits[LOW], number->bits[MID], number->bits[HIGH]);
//     if (s21_getbit(*number, SCALE * 32 + 31)) printf("-\n");
//     for (int i = 23; i >15; i--) {
//         printf("%d", !!(s21_getbit(*number, SCALE*32 + i)));
//     }
//     printf("\n");
// }

int s21_decimal_null(s21_decimal * number) {
    for (int i = 0; i < 4; i++) {
        number->bits[i] &= 0;
    }
    return 0;
}

int s21_getscale(s21_decimal number) {
    int sol = 0;
    int buf = 0;

    for (int i = 16; i < 24; i++) {
        buf = !!(s21_getbit(number, (SCALE*32 + i)));
        sol +=  buf * pow(2, i-16);
    }
    return sol;
}

void s21_setscale(s21_decimal * number, int n) {
    int buff = 0;
    for (int i = 0; i < 8; i++) {
        buff = n & 1 << i;
        if (buff) {
            s21_setbit(number, (SCALE*32 + 16 + i));
        } else {
            s21_setbit(number, (SCALE*32 + 16 + i));
            s21_inversebit(number, (SCALE*32 + 16 + i));
        }
    }
}

void s21_decimal_copy(s21_decimal src, s21_decimal * dst) {
    s21_decimal_null(dst);
    for (int i = 0; i < 128; i++) {
        if (s21_getbit(src, i)) s21_setbit(dst, i);
    }
}

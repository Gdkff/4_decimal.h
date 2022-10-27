#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { LOW, MID, HIGH, SCALE } mas;

#define DECIMAL_MAX 79228162514264337593543950336.0
#define DECIMAL_MIN 1e-28

typedef struct s21_decimal {
  int bits[4];
} s21_decimal;

union dec {
  s21_decimal in;
  float fl;
  int inn;
};

#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0

int s21_getrow(int i);
int s21_getcol(int i);

int s21_getbit(s21_decimal number, int i);
int s21_setbit(s21_decimal *number, int i);
int s21_inversebit(s21_decimal *number, int i);
int s21_getscale(s21_decimal number);
void s21_setscale(s21_decimal *number, int n);
void s21_dprint(s21_decimal *number);
int s21_decimal_null(s21_decimal *number);
void s21_decimal_copy(s21_decimal src, s21_decimal *dst);

//------------------------------------------

int s21_decimal_ten(s21_decimal *num, int count);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_add_bit(s21_decimal num1, s21_decimal num2, s21_decimal *ans);
int s21_sub_bit(s21_decimal num1, s21_decimal num2, s21_decimal *ans);

int s21_is_less_bits(s21_decimal num1, s21_decimal num2);
int s21_is_equal_bits(s21_decimal num1, s21_decimal num2);

int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);

int s21_mnog_ten(s21_decimal *num);
int s21_del_ten(s21_decimal *num);

int s21_one_scale_comparse(s21_decimal *num1, s21_decimal *num2);

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);

void right_shift(s21_decimal *num, int c);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// ARIFMETICS
typedef struct {
  char dec[340];
  int sign;
  int exp;
} str_decimal;
int s21_dec_to_str_dec(s21_decimal in, str_decimal *out);
int dec_str_div(str_decimal *value_1, str_decimal *value_2,
                str_decimal *result);
int str_dec_to_s21_dec(str_decimal in, s21_decimal *out);
int dec_str_mod(str_decimal *value_1, str_decimal *value_2,
                str_decimal *result);
int dec_str_mul(str_decimal *value_1, str_decimal *value_2,
                str_decimal *result);
void num_str_prepare(char *value_1, char *value_2);
void num_str_delete_right_zeros(char *num_str);
void num_str_delete_all_right_zeros(char *num_str);
void num_str_delete_left_zeros(char *num_str);
void reverse_str(char *str);
int num_str_is_equal(char *str1, char *str2);
int num_str_is_greater(char *str1, char *str2);
int num_str_is_greater_or_equal(char *str1, char *str2);
int num_str_sub_simple(char *value_1, char *value_2, char *result,
                       int num_system);
int num_str_add(char *value_1, char *value_2, char *result, int num_system);
int num_str_div(char *value_1, char *value_2, char *result);
int dec_str_pack_result(str_decimal *result);
void str_decimal_to_zero(str_decimal *str_dec);
void dec_str_zero_exp(str_decimal *value_1, str_decimal *value_2);
int num_str_mod(char *value_1, char *value_2, char *result);
int num_str_mul(char *value_1, char *value_2, char *result, int num_system);
void num_str_bank_round(char *num_str, int position);
void from_str_to_binary(char *in, char *out, int in_num_system);
short read_float_exponent(float num);
unsigned div_by_int_ret_ost(char *delimoe, int devisor, int num_system,
                            char *result);
int float_to_str_dec(float num, str_decimal *str_dec);
int print_decimal_binary(s21_decimal dst);
int dec_str_universal_add_sub(str_decimal value_1, str_decimal value_2,
                              str_decimal *result);

#endif  // SRC_S21_DECIMAL_H_

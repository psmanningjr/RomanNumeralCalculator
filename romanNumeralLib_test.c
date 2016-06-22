#include <stdlib.h>
#include <check.h>
#include "romanNumeralLib.h"
#define SINGLE_DIGIT_NUMERAL_STR "I"
#define ROMAN_NUMERAL_ONE_STR "I"
#define ROMAN_NUMERAL_FIVE_STR "V"
#define ROMAN_NUMERAL_TEN_STR "X"
#define ROMAN_NUMERAL_FIFTY_STR "L"
#define ROMAN_NUMERAL_ONE_HUNDRED_STR "C"
#define ROMAN_NUMERAL_FIVE_HUNDRED_STR "D"
#define ROMAN_NUMERAL_ONE_THOUSAND_STR "M"

START_TEST (test_roman_numeral_buid_with_null_string_returns_null) 
{
   RomanNumeral *rn = romanNumeral_new(NULL);
   ck_assert_msg(rn == NULL, "Null string should return null roman numeral pointer");
}
END_TEST

START_TEST (test_roman_numeral_buid_returns_non_null) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_TEN_STR);
   ck_assert_msg(rn != NULL, "Should return non-null roman numeral pointer");
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_buid_with_empty_string_returns_null) 
{
   RomanNumeral *rn = romanNumeral_new("");
   ck_assert_msg(rn == NULL, "Null string should return null roman numeral pointer");
}
END_TEST

START_TEST (test_roman_numeral_buid_sets_value_and_numeral_str_method_returns_the_original_string) 
{
   RomanNumeral *rn = romanNumeral_new(SINGLE_DIGIT_NUMERAL_STR);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), SINGLE_DIGIT_NUMERAL_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_I) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_ONE_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 1);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_V) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_FIVE_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 5);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_X) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_TEN_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 10);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_L) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_FIFTY_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 50);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_C) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_ONE_HUNDRED_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 100);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_D) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_FIVE_HUNDRED_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 500);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_M) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_ONE_THOUSAND_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 1000);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_repeat_two_digits) 
{
   RomanNumeral *rn = romanNumeral_new("II");
   ck_assert_int_eq(romanNumeral_value(rn), 2);
   romanNumeral_free(rn);
   
   rn = romanNumeral_new("XX");
   ck_assert_int_eq(romanNumeral_value(rn), 20);
   romanNumeral_free(rn);

   rn = romanNumeral_new("CC");
   ck_assert_int_eq(romanNumeral_value(rn), 200);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_repeat_three_digits) 
{
   RomanNumeral *rn = romanNumeral_new("III");
   ck_assert_int_eq(romanNumeral_value(rn), 3);
   romanNumeral_free(rn);
   
   rn = romanNumeral_new("XXX");
   ck_assert_int_eq(romanNumeral_value(rn), 30);
   romanNumeral_free(rn);

   rn = romanNumeral_new("CCC");
   ck_assert_int_eq(romanNumeral_value(rn), 300);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_encodes_letter_V) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_FIVE_STR);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERAL_FIVE_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_encodes_letter_X) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_TEN_STR);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERAL_TEN_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_encodes_letter_L) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_FIFTY_STR);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERAL_FIFTY_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_encodes_letter_C) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_ONE_HUNDRED_STR);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERAL_ONE_HUNDRED_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_encodes_letter_M) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERAL_ONE_THOUSAND_STR);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERAL_ONE_THOUSAND_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_subtraction_pair_IV)
{
   RomanNumeral *rn = romanNumeral_new("IV");
   ck_assert_int_eq(romanNumeral_value(rn), 4);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_subtraction_pair_IX)
{
   RomanNumeral *rn = romanNumeral_new("IX");
   ck_assert_int_eq(romanNumeral_value(rn), 9);
   romanNumeral_free(rn);
}
END_TEST

Suite * roman_numeral_input_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman numeral tests");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_roman_numeral_buid_with_null_string_returns_null) ;
    tcase_add_test(tc_core, test_roman_numeral_buid_returns_non_null) ;
    tcase_add_test(tc_core, test_roman_numeral_buid_with_empty_string_returns_null) ;
    tcase_add_test(tc_core, test_roman_numeral_buid_sets_value_and_numeral_str_method_returns_the_original_string);
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_I);
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_V);
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_X);
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_L);
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_C);
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_D);
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_M);
    tcase_add_test(tc_core, test_roman_numeral_decodes_repeat_two_digits);
    tcase_add_test(tc_core, test_roman_numeral_decodes_repeat_three_digits);
    tcase_add_test(tc_core, test_roman_numeral_encodes_letter_V);
    tcase_add_test(tc_core, test_roman_numeral_encodes_letter_X);
    tcase_add_test(tc_core, test_roman_numeral_encodes_letter_L);
    tcase_add_test(tc_core, test_roman_numeral_encodes_letter_C);
    tcase_add_test(tc_core, test_roman_numeral_encodes_letter_M);
    tcase_add_test(tc_core, test_roman_numeral_decodes_subtraction_pair_IV);
    tcase_add_test(tc_core, test_roman_numeral_decodes_subtraction_pair_IX);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_numeral_input_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

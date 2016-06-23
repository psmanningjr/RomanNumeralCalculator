#include <stdlib.h>
#include <check.h>
#include "romanNumeralLib.h"
#define SINGLE_DIGIT_NUMERAL_STR "I"
#define ROMAN_NUMERAL_ONE_STR "I"
#define ROMAN_NUMERALS_TWO_STR "II"
#define ROMAN_NUMERALS_THREE_STR "III"
#define ROMAN_NUMERALS_FOUR_STR "IV"
#define ROMAN_NUMERAL_FIVE_STR "V"
#define ROMAN_NUMERALS_SIX_STR "VI"
#define ROMAN_NUMERALS_SEVEN_STR "VII"
#define ROMAN_NUMERALS_EIGHT_STR "VIII"
#define ROMAN_NUMERALS_NINE_STR "IX"
#define ROMAN_NUMERAL_TEN_STR "X"
#define ROMAN_NUMERALS_ELEVEN_STR "XI"
#define ROMAN_NUMERALS_TWELVE_STR "XII"
#define ROMAN_NUMERALS_THIRTEEN_STR "XIII"
#define ROMAN_NUMERALS_TWENTY_STR "XX"
#define ROMAN_NUMERALS_FOURTY_STR "XL"
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
   ck_assert_int_eq(romanNumeral_value(rn), 1);
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
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERAL_FIVE_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_one_letter_addition) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_SIX_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 6);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_SIX_STR);
   romanNumeral_free(rn);
   
   rn = romanNumeral_new(ROMAN_NUMERALS_SEVEN_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 7);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_SEVEN_STR);
   romanNumeral_free(rn);
   
   rn = romanNumeral_new(ROMAN_NUMERALS_EIGHT_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 8);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_EIGHT_STR);
   romanNumeral_free(rn);

   rn = romanNumeral_new(ROMAN_NUMERALS_ELEVEN_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 11);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_ELEVEN_STR);
   romanNumeral_free(rn);

   rn = romanNumeral_new(ROMAN_NUMERALS_TWELVE_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 12);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_TWELVE_STR);
   romanNumeral_free(rn);

   rn = romanNumeral_new(ROMAN_NUMERALS_THIRTEEN_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 13);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_THIRTEEN_STR);
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
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_TWO_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 2);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_TWO_STR);
   romanNumeral_free(rn);
   
   rn = romanNumeral_new(ROMAN_NUMERALS_TWENTY_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 20);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_TWENTY_STR);
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
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_THREE_STR);
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
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FOUR_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 4);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FOUR_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_subtraction_pair_IX)
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_NINE_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 9);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_NINE_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_subtraction_pair_XL)
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FOURTY_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 40);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FOURTY_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_subtraction_pair_XC)
{
   RomanNumeral *rn = romanNumeral_new("XC");
   ck_assert_int_eq(romanNumeral_value(rn), 90);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_subtraction_pair_CD)
{
   RomanNumeral *rn = romanNumeral_new("CD");
   ck_assert_int_eq(romanNumeral_value(rn), 400);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_subtraction_pair_CM)
{
   RomanNumeral *rn = romanNumeral_new("CM");
   ck_assert_int_eq(romanNumeral_value(rn), 900);
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
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_one_letter_addition);
    tcase_add_test(tc_core, test_roman_numeral_decodes_subtraction_pair_IV);
    tcase_add_test(tc_core, test_roman_numeral_decodes_subtraction_pair_IX);
    tcase_add_test(tc_core, test_roman_numeral_decodes_subtraction_pair_XL);
    tcase_add_test(tc_core, test_roman_numeral_decodes_subtraction_pair_XC);
    tcase_add_test(tc_core, test_roman_numeral_decodes_subtraction_pair_CD);
    tcase_add_test(tc_core, test_roman_numeral_decodes_subtraction_pair_CM);
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

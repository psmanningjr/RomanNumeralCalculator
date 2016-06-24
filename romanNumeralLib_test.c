#include <stdlib.h>
#include <check.h>
#include "romanNumeralLib.h"
#define SINGLE_DIGIT_NUMERAL_STR "I"
#define ROMAN_NUMERALS_ONE_STR "I"
#define ROMAN_NUMERALS_TWO_STR "II"
#define ROMAN_NUMERALS_THREE_STR "III"
#define ROMAN_NUMERALS_FOUR_STR "IV"
#define ROMAN_NUMERALS_FIVE_STR "V"
#define ROMAN_NUMERALS_SIX_STR "VI"
#define ROMAN_NUMERALS_SEVEN_STR "VII"
#define ROMAN_NUMERALS_EIGHT_STR "VIII"
#define ROMAN_NUMERALS_NINE_STR "IX"
#define ROMAN_NUMERALS_TEN_STR "X"
#define ROMAN_NUMERALS_ELEVEN_STR "XI"
#define ROMAN_NUMERALS_TWELVE_STR "XII"
#define ROMAN_NUMERALS_THIRTEEN_STR "XIII"
#define ROMAN_NUMERALS_FOURTEEN_STR "XIV"
#define ROMAN_NUMERALS_FIFTEEN_STR "XV"
#define ROMAN_NUMERALS_SIXTEEN_STR "XVI"
#define ROMAN_NUMERALS_NINETEEN_STR "XIX"
#define ROMAN_NUMERALS_TWENTY_STR "XX"
#define ROMAN_NUMERALS_TWENTYONE_STR "XXI"
#define ROMAN_NUMERALS_THIRTY_STR "XXX"
#define ROMAN_NUMERALS_FORTY_STR "XL"
#define ROMAN_NUMERALS_FIFTY_STR "L"
#define ROMAN_NUMERALS_NINETY_STR "XC"
#define ROMAN_NUMERALS_ONE_HUNDRED_STR "C"
#define ROMAN_NUMERALS_THREE_HUNDRED_STR "CCC"
#define ROMAN_NUMERALS_FOUR_HUNDRED_STR "CD"
#define ROMAN_NUMERALS_FIVE_HUNDRED_STR "D"
#define ROMAN_NUMERALS_NINE_HUNDRED_STR "CM"
#define ROMAN_NUMERALS_ONE_THOUSAND_STR "M"
#define ROMAN_NUMERALS_BIGNUM_STR "MCMXLVIII"
#define ROMAN_NUMERALS_ONE_HUNDRED_FORTY_STR "CXL"

START_TEST (test_roman_numeral_buid_with_null_string_returns_null) 
{
   RomanNumeral *rn = romanNumeral_new(NULL);
   ck_assert_msg(rn == NULL, "Null string should return null roman numeral pointer");
}
END_TEST

START_TEST (test_roman_numeral_buid_returns_non_null) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_TEN_STR);
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

START_TEST (test_roman_numeral_handles_letter_I) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_ONE_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 1);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_ONE_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_letter_V) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FIVE_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 5);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FIVE_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_digit_letter_addition) 
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

   rn = romanNumeral_new(ROMAN_NUMERALS_SIXTEEN_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 16);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_SIXTEEN_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_XIX) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_NINETEEN_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 19);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_NINETEEN_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_XXI) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_TWENTYONE_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 21);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_TWENTYONE_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_XV) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FIFTEEN_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 15);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FIFTEEN_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_XIV) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FOURTEEN_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 14);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FOURTEEN_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_letter_X) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_TEN_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 10);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_TEN_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_letter_L) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FIFTY_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 50);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FIFTY_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_letter_C) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_ONE_HUNDRED_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 100);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_ONE_HUNDRED_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_letter_D) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FIVE_HUNDRED_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 500);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FIVE_HUNDRED_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_letter_M) 
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_ONE_THOUSAND_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 1000);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_ONE_THOUSAND_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_repeat_two_digits) 
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

START_TEST (test_roman_numeral_handles_repeat_three_digits) 
{
   RomanNumeral *rn = romanNumeral_new("III");
   ck_assert_int_eq(romanNumeral_value(rn), 3);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_THREE_STR);
   romanNumeral_free(rn);
   
   rn = romanNumeral_new(ROMAN_NUMERALS_THIRTY_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 30);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_THIRTY_STR);
   romanNumeral_free(rn);

   rn = romanNumeral_new(ROMAN_NUMERALS_THREE_HUNDRED_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 300);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_THREE_HUNDRED_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_subtraction_pair_IV)
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FOUR_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 4);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FOUR_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_subtraction_pair_IX)
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_NINE_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 9);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_NINE_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_subtraction_pair_XL)
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FORTY_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 40);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FORTY_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_subtraction_pair_XC)
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_NINETY_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 90);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_NINETY_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_subtraction_pair_CD)
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_FOUR_HUNDRED_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 400);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_FOUR_HUNDRED_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_subtraction_pair_CM)
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_NINE_HUNDRED_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 900);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_NINE_HUNDRED_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_subtraction_pair_MCMXLVIII)
{
   RomanNumeral *rn = romanNumeral_new(ROMAN_NUMERALS_BIGNUM_STR);
   ck_assert_int_eq(romanNumeral_value(rn), 1948);
   ck_assert_str_eq(romanNumeral_numeral_str(rn), ROMAN_NUMERALS_BIGNUM_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_handles_addition)
{
   RomanNumeral *rn1 = romanNumeral_new(ROMAN_NUMERALS_ONE_HUNDRED_STR);
   RomanNumeral *rn2 = romanNumeral_new(ROMAN_NUMERALS_FORTY_STR);

   romanNumeral_add(rn1,rn2);
   ck_assert_int_eq(romanNumeral_value(rn1), 140);
   ck_assert_str_eq(romanNumeral_numeral_str(rn1), ROMAN_NUMERALS_ONE_HUNDRED_FORTY_STR);
   romanNumeral_free(rn1);
   romanNumeral_free(rn2);
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
    tcase_add_test(tc_core, test_roman_numeral_handles_letter_I);
    tcase_add_test(tc_core, test_roman_numeral_handles_letter_V);
    tcase_add_test(tc_core, test_roman_numeral_handles_letter_X);
    tcase_add_test(tc_core, test_roman_numeral_handles_letter_L);
    tcase_add_test(tc_core, test_roman_numeral_handles_letter_C);
    tcase_add_test(tc_core, test_roman_numeral_handles_letter_D);
    tcase_add_test(tc_core, test_roman_numeral_handles_letter_M);
    tcase_add_test(tc_core, test_roman_numeral_handles_repeat_two_digits);
    tcase_add_test(tc_core, test_roman_numeral_handles_repeat_three_digits);
    tcase_add_test(tc_core, test_roman_numeral_handles_digit_letter_addition);
    tcase_add_test(tc_core, test_roman_numeral_handles_subtraction_pair_IV);
    tcase_add_test(tc_core, test_roman_numeral_handles_subtraction_pair_IX);
    tcase_add_test(tc_core, test_roman_numeral_handles_subtraction_pair_XL);
    tcase_add_test(tc_core, test_roman_numeral_handles_subtraction_pair_XC);
    tcase_add_test(tc_core, test_roman_numeral_handles_subtraction_pair_CD);
    tcase_add_test(tc_core, test_roman_numeral_handles_subtraction_pair_CM);
    tcase_add_test(tc_core, test_roman_numeral_handles_XV);
    tcase_add_test(tc_core, test_roman_numeral_handles_XIV);
    tcase_add_test(tc_core, test_roman_numeral_handles_XIX); 
    tcase_add_test(tc_core, test_roman_numeral_handles_XXI); 
    tcase_add_test(tc_core, test_roman_numeral_handles_addition); 
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

#include <stdlib.h>
#include <check.h>
#include "romanNumeralLib.h"
#define NUMERAL_STR "XXII"

START_TEST (test_roman_numeral_buid_with_null_string_returns_null) 
{
   RomanNumeral *rn = romanNumeral_new(NULL);
   ck_assert_msg(rn == NULL, "Null string should return null roman numeral pointer");
}
END_TEST

START_TEST (test_roman_numeral_buid_returns_non_null) 
{
   RomanNumeral *rn = romanNumeral_new("X");
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
   RomanNumeral *rn = romanNumeral_new("XXII");
   ck_assert_str_eq(romanNumeral_numeral_str(rn), NUMERAL_STR);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_I) 
{
   RomanNumeral *rn = romanNumeral_new("I");
   ck_assert_int_eq(romanNumeral_value(rn), 1);
   romanNumeral_free(rn);
}
END_TEST

START_TEST (test_roman_numeral_decodes_letter_V) 
{
   RomanNumeral *rn = romanNumeral_new("V");
   ck_assert_int_eq(romanNumeral_value(rn), 5);
   romanNumeral_free(rn);
}
END_TEST

Suite * roman_numeral_input_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman numeral input tests");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_roman_numeral_buid_with_null_string_returns_null) ;
    tcase_add_test(tc_core, test_roman_numeral_buid_returns_non_null) ;
    tcase_add_test(tc_core, test_roman_numeral_buid_with_empty_string_returns_null) ;
    tcase_add_test(tc_core, test_roman_numeral_buid_sets_value_and_numeral_str_method_returns_the_original_string);
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_I);
    tcase_add_test(tc_core, test_roman_numeral_decodes_letter_V);
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

#include <stdlib.h>
#include <check.h>
#include "romanNumeralLib.h"

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

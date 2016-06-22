#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

#include <stdint.h>
#define MAX_ROMAN_NUMERAL_SIZE 13

typedef struct RomanNumeral RomanNumeral;

RomanNumeral *romanNumeral_new(char *valueStr);
char *romanNumeral_numeral_str(RomanNumeral *rn);
int32_t romanNumeral_value(RomanNumeral *rn);
void romanNumeral_free(RomanNumeral *rn);

#endif /* ROMAN_NUMERAL_H */

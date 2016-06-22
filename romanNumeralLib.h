#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

#include <stdint.h>

typedef struct RomanNumeral RomanNumeral;

RomanNumeral *romanNumeral_new(char *valueStr);
char *romanNumeral_numeral_str(RomanNumeral *rn);
void romanNumeral_free(RomanNumeral *rn);

#endif /* ROMAN_NUMERAL_H */

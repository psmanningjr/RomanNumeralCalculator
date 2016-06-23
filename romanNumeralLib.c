#include <stdlib.h>
#include <string.h>
#include "romanNumeralLib.h"

#define ROMAN_DIGITS 7
#define ROMAN_NUMERALS "IVXLCDM"
#define ONES_DENOMINATION 0
#define TENS_DENOMINATION 2
#define HUNDREDS_DENOMINATION 4
#define INVALID_DENOMINATION -1

struct RomanNumeral
{
   char *inputString;
   int32_t value;
   char *valueString;
};

int denominationValues[ROMAN_DIGITS] = {1, 5, 10, 50, 100, 500, 1000}; 

void initializeVariables(RomanNumeral *rn, char *valueStr);
char *encode_value(int32_t value);
int32_t decode_value(char *value_str);
int32_t numeralValue(int denomination, char *digits);


RomanNumeral *romanNumeral_new(char *valueStr) 
{
   RomanNumeral *rn;

   if (emptyInput(valueStr)) { return NULL; }
   rn = malloc(sizeof(RomanNumeral));
   if (rn != NULL) 
   {
      initializeVariables(rn, valueStr);
   }

   return rn;
}

int emptyInput(char *valueStr)
{
   return (valueStr == NULL || valueStr[0] == '\0');
}

void initializeVariables(RomanNumeral *rn, char *valueStr)
{
   rn->inputString = malloc(strlen(valueStr)); 
   strcpy(rn->inputString, valueStr);
   rn->value = decode_value(rn->inputString);
   rn->valueString = encode_value(rn->value);
}

int32_t decode_value(char *value_str)
{
   return decode_char(value_str);
}

char *encode_value(int32_t value)
{
   char *result = malloc(MAX_ROMAN_NUMERAL_SIZE);
   if (value == 1000) 
   {
      *result = 'M';
   }
   else if (value == 100) 
   {
      *result = 'C';
   }
   else if (value == 50) 
   {
      *result = 'L';
   }
   else if (value == 10) 
   {
      *result = 'X';
   }
   else if (value == 5) 
   {
      *result = 'V';
   } 
   else
   {
      *result = 'I';
   }
   result[1] = '\0';
   return  result;
}

int32_t decode_char(char *character)
{
   int denomination = denominationOfNumeral(character); 
   if (index <0) {  return 0; }
   return numeralValue(denomination, character);
}

int denominationOfNumeral(char *character)
{
   int index = strcspn(ROMAN_NUMERALS,character); 
   if (isRomanNumeral(index)) 
   {  
      return index;
   }
   else
   {
      return INVALID_DENOMINATION;
   }
}

int isRomanNumeral(int strcspnResult)
{
   return (strcspnResult != ROMAN_DIGITS);
}

int32_t numeralValue(int denomination, char *digits)
{
   int secondDigitDenomination =  nextDigitDenomination(digits, 
                                                         denomination);
   if (subtractionNeeded(secondDigitDenomination))
   {
      return denominationValues[secondDigitDenomination] - 
                                         denominationValues[denomination];
   }
   return denominationValues[denomination]*strlen(digits);
}

int nextDigitDenomination(char *digits, int denomination)
{
   int nextDenomination = INVALID_DENOMINATION;
   if (subtractableDenomination(denomination))
   {
      nextDenomination = subtractionDenomination(digits, denomination);
   }
   return nextDenomination;
}

int subtractableDenomination(int denomination)
{
   return (denomination == ONES_DENOMINATION || 
           denomination == TENS_DENOMINATION || 
           denomination == HUNDREDS_DENOMINATION);
}

int subtractionDenomination(char *digits,int denomination)
{
   char *nextNumeral = ++digits;
   if (*nextNumeral == ROMAN_NUMERALS[denomination+1]) 
   {
      return denomination+1;
   }
   else if (*nextNumeral == ROMAN_NUMERALS[denomination+2])  
   {
      return denomination+2;
   }
   return INVALID_DENOMINATION;
}

int subtractionNeeded(int nextDigitDenomination)
{
   return nextDigitDenomination > INVALID_DENOMINATION;
}

char *romanNumeral_numeral_str(RomanNumeral *rn)
{
   return rn->valueString;
}

int32_t romanNumeral_value(RomanNumeral *rn)
{
   return rn->value;
}

void romanNumeral_free(RomanNumeral *rn)
{
   free(rn->inputString);
   free(rn->valueString);
   free(rn);
}

#include <stdlib.h>
#include <string.h>
#include "romanNumeralLib.h"

struct RomanNumeral
{
   char *valueString;
   int32_t value;
};

RomanNumeral *romanNumeral_new(char *valueStr) 
{
   RomanNumeral *rn;

   if (valueStr == NULL || valueStr[0] == '\0')
   {
      return NULL;
   }
  
   rn = malloc(sizeof(RomanNumeral));

   if (rn != NULL) 
   {
      rn->valueString = malloc(strlen(valueStr)); 
      strcpy(rn->valueString, valueStr);
      rn->value = decode_value(rn->valueString);
   }

   return rn;
}

int32_t decode_value(char *value_str)
{
   return decode_char(value_str);
}
#define ROMAN_DIGITS 7
int32_t decode_char(char *character)
{
   int value[ROMAN_DIGITS] = {1, 5, 10, 50, 100, 500, 1000}; 
   int index = strcspn("IVXLCDM",character); 
   if (index != ROMAN_DIGITS) 
   {  
      return value[index];
   } 
   else 
   {
      return 0;
   }
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
   free(rn->valueString);
   free(rn);
}


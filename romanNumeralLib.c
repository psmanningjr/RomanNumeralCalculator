#include <stdlib.h>
#include <string.h>
#include "romanNumeralLib.h"

#define ROMAN_DIGITS 7

struct RomanNumeral
{
   char *inputString;
   int32_t value;
   char *valueString;
};

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
      rn->inputString = malloc(strlen(valueStr)); 
      strcpy(rn->inputString, valueStr);
      rn->value = decode_value(rn->inputString);
      rn->valueString = encode_value(rn->value);
   }

   return rn;
}

int32_t decode_value(char *value_str)
{
   return decode_char(value_str);
}

int32_t decode_char(char *character)
{
   int index = strcspn("IVXLCDM",character); 
   if (index != ROMAN_DIGITS) 
   {  
      return calcValue(index, character);
   } 
   else 
   {
      return 0;
   }
}

int32_t calcValue(int denomination, char *digits)
{
   int value[ROMAN_DIGITS] = {1, 5, 10, 50, 100, 500, 1000}; 
   char *ptr = digits;
   ptr++;
   if ((denomination == 0) && (*ptr == 'V'))  
   {
      return value[1] - value[0];
   }
   else if ((denomination == 0) && (*ptr == 'X'))  
   {
      return value[2] - value[0];
   }
   else
   {
      return value[denomination]*strlen(digits);
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
   free(rn->inputString);
   free(rn->valueString);
   free(rn);
}

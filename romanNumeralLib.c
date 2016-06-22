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

   return rn;
}


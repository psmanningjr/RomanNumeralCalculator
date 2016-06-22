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

   if (valueStr == NULL )
   {
      return NULL;
   }
}


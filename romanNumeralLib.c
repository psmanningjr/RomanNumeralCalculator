#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "romanNumeralLib.h"

#define TRUE 1
#define FALSE 0
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

int32_t numeralDigitValues[ROMAN_DIGITS] = {1, 5, 10, 50, 100, 500, 1000}; 

RomanNumeral *createRomanNumeral(char *valueStr);
void initializeVariables(RomanNumeral *rn, char *valueStr);
char *encode_value(int32_t value);
int32_t decode_value(char *value_str);
int32_t numeralValue(char *digits);
char * outputSpecifedNumberOfUnits(int numUnits, char *ptr,int baseDenomination);


RomanNumeral *romanNumeral_new(char *valueStr) 
{
   RomanNumeral *rn;

   rn = createRomanNumeral(valueStr);
   if (rn != NULL) 
   {
      initializeVariables(rn, valueStr);
   }
   return rn;
}

RomanNumeral *createRomanNumeral(char *valueStr)
{
   if (emptyInput(valueStr)) 
   { 
      return NULL; 
   }
   return malloc(sizeof(RomanNumeral));
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

char *encode_value(int32_t value)
{
   char *result = malloc(MAX_ROMAN_NUMERAL_SIZE);
   char *ptr = result; 
   if (value == 1000) 
   {
      *ptr++ = 'M';
      value -=  value/1000 * 1000;
   }
   if (value > 99) 
   {
      ptr = outputSpecifedNumberOfUnits(value/100, ptr,4);
      value -=  value/100 * 100;
   }
   if (value > 9) 
   {
      ptr = outputSpecifedNumberOfUnits(value/10, ptr,2);
      value -=  value/10 * 10;
   }
   ptr = outputSpecifedNumberOfUnits(value, ptr,0);
   *ptr = '\0';
   return  result;
}

char * outputSpecifedNumberOfUnits(int numUnits, char *ptr,int baseDenomination)
{
      char letterI = ROMAN_NUMERALS[baseDenomination];
      char letterV = ROMAN_NUMERALS[baseDenomination+1];
      char letterX = ROMAN_NUMERALS[baseDenomination+2];
      if (numUnits == 4) 
      {
         *ptr++ = letterI;
         *ptr++ = letterV;
      }
      else if (numUnits == 9) 
      {
         *ptr++ = letterI;
         *ptr++ = letterX;
      }
      else 
      {
         if (numUnits >= 5) 
         {
            *ptr++ = letterV;
            numUnits -= 5;
         }
         int count;
         for (count = 0; count < numUnits; count++)
         {
            *ptr++ = letterI; 
         }
      }
   return ptr;
}

int32_t decode_value(char *digits)
{
   int32_t value = 0;
   int denomination = denominationOfNumeral(digits); 
   if (denomination == INVALID_DENOMINATION) {  return 0; }
   int subtractionSecondDigitDenomination =  nextDigitDenominationForSubtraction(digits, 
                                                         denomination);
   if (strlen(digits) == 2 && subtractionNeeded(subtractionSecondDigitDenomination))
   {
      value += numeralDigitValues[subtractionSecondDigitDenomination] - 
                                         numeralDigitValues[denomination];
   }
   else
   {
      value += numeralDigitValues[denomination];
      char *currentLetter = digits;
      currentLetter++;
      while(*currentLetter != '\0' && 
         (digitIsRepeat(currentLetter, denomination)))
      {
            value += numeralDigitValues[denomination];
            currentLetter++;
      }
      if (*currentLetter != '\0') 
      {
         value += decode_value(currentLetter);
      }
   }
   return value;
}

int denominationOfNumeral(char *character)
{
   char singleLetterStr[] = " ";
   singleLetterStr[0] = *character;
   int index = strcspn(ROMAN_NUMERALS, singleLetterStr); 
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

int nextDigitDenominationForSubtraction(char *digits, int denomination)
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

int digitIsRepeat(char *digits,int prevDenomination)
{
   return (*digits == ROMAN_NUMERALS[prevDenomination]); 
}

int denominationValid(int denomination)
{
   return denomination > INVALID_DENOMINATION;
}

int subtractionNeeded(int nextDigitDenomination)
{
   return denominationValid(nextDigitDenomination);
}

char *romanNumeral_numeral_str(RomanNumeral *rn)
{
   return rn->valueString;
}

int32_t romanNumeral_value(RomanNumeral *rn)
{
   return rn->value;
}

void romanNumeral_add(RomanNumeral *rn_dest, RomanNumeral *rn_added)
{
   rn_dest->value += rn_added->value;
   rn_dest->valueString = encode_value(rn_dest->value);
}

void romanNumeral_subtract(RomanNumeral *rn_dest, RomanNumeral *rn_added)
{
   rn_dest->value -= rn_added->value;
   rn_dest->valueString = encode_value(rn_dest->value);
}

void romanNumeral_free(RomanNumeral *rn)
{
   free(rn->inputString);
   free(rn->valueString);
   free(rn);
}

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

int32_t denominationValues[ROMAN_DIGITS] = {1, 5, 10, 50, 100, 500, 1000}; 

void initializeVariables(RomanNumeral *rn, char *valueStr);
char *encode_value(int32_t value);
int32_t decode_value(char *value_str);
int32_t numeralValue(char *digits);
char * outputSpecifedNumberOfUnits(int numUnits, char *ptr,int baseDenomination);


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
   printf(" value %d created new string '%s'\n",value, result);
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

int32_t decode_char(char *character)
{
//   int denomination = denominationOfNumeral(character); 
//printf("denom %d digits %s\n",denomination, character);
//   if (denomination < 0) {  return 0; }
//   if (denomination == 0) 
//   {
      int32_t result = numeralValue(character);
printf("================final result === %d\n",result);
      return result;
//   }
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

int32_t numeralValue(char *digits)
{
printf("numeralValue_____________________________________________________\n");
   int32_t value = 0;
   int denomination = denominationOfNumeral(digits); 
   if (denomination == INVALID_DENOMINATION) {  return 0; }
printf("denom %d digits %s\n",denomination, digits);
   int subtractionSecondDigitDenomination =  nextDigitDenominationForSubtraction(digits, 
                                                         denomination);
   if (strlen(digits) == 2 && subtractionNeeded(subtractionSecondDigitDenomination))
   {
      value += denominationValues[subtractionSecondDigitDenomination] - 
                                         denominationValues[denomination];
   }
   else
   {
      value += denominationValues[denomination];
      char *currentLetter = digits;
      currentLetter++;
      while(*currentLetter != '\0' && 
         (nextDigitIsRepeat(currentLetter, denomination)))
      {
            printf("----- adding repeat \n");
            value += denominationValues[denomination];
            currentLetter++;
      }
      if (*currentLetter != '\0') 
      {
         value += numeralValue(currentLetter);
      }
   }
   return value;
}

int32_t numeralValueold(char *digits)
{
      int32_t value = 0;
printf("numeralValue_____________________________________________________\n");
   int denomination = denominationOfNumeral(digits); 
printf("denom %d digits %s\n",denomination, digits);
   if (denomination == INVALID_DENOMINATION) {  return 0; }
   int subtractionSecondDigitDenomination =  nextDigitDenominationForSubtraction(digits, 
                                                         denomination);
   if (strlen(digits) == 2 && subtractionNeeded(subtractionSecondDigitDenomination))
   {
      return denominationValues[subtractionSecondDigitDenomination] - 
                                         denominationValues[denomination];
   }
   else
   {
      char *currentLetter = digits;
      value += denominationValues[denomination];
      int repeatedNextDenomination;
      while(*currentLetter != '\0') 
      {
            repeatedNextDenomination = denominationRepeated(currentLetter, 
                                                               denomination); 
   printf("-----top of loop denom = %d  repeatedNextDenom %d\n",denomination, repeatedNextDenomination);
         currentLetter++;
         if (repeatedDigits(repeatedNextDenomination))
         {
printf("************************ adding repeated %s \n", currentLetter);
            // V value
            value += denominationValues[denomination] + 
                      numeralValue(currentLetter);
// denominationValues[repeatedNextDenomination]
//                       *(strlen(digits)-1) + denominationValues[denomination];
         }
         else
         {
            // I value
            value += denominationValues[denomination];
         }
      }
   printf("^^^^^^^^^^^^^^^^^^^^ returning value of %d\n", value);
   }
   return value;
//   return denominationValues[denomination]*strlen(digits);
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

int nextDigitIsRepeat(char *digits,int prevDenomination)
{
   char *nextNumeral = ++digits;
   return (*nextNumeral == ROMAN_NUMERALS[prevDenomination]); 
}

int denominationRepeated(char *digits,int denomination)
{
printf("denom = %d next string in repeat is %s\n",denomination, digits);
//printf("--------------unitdenom = %d \n",unitDenomination(denomination));
   char *nextNumeral = ++digits;
//   int unitDenom = unitDenomination(denomination);
   int unitDenom = denomination-1;
   if (denomination > 0 &&
       *nextNumeral == ROMAN_NUMERALS[unitDenom]) 
   {
      return unitDenom;
   }
   return INVALID_DENOMINATION;
}

int unitDenomination(int denomination)
{
   return (denomination % 2 == 0) ? denomination-2 : denomination-1;
}

int denominationValid(int denomination)
{
   return denomination > INVALID_DENOMINATION;
}

int subtractionNeeded(int nextDigitDenomination)
{
   return denominationValid(nextDigitDenomination);
}

int repeatedDigits(int repeatedNextDenomination)
{
   return denominationValid(repeatedNextDenomination);
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

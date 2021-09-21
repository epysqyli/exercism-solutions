#include <stdio.h>
#include <math.h>
#include "armstrong_numbers.h"

static int count_digits(int candidate)
{
  int digits = 0;
  while (candidate != 0)
  {
    candidate /= 10;
    digits++;
  }

  return digits;
}

bool is_armstrong_number(int candidate)
{
  int candidate_1 = candidate;
  int digits = count_digits(candidate), digits_1 = count_digits(candidate);
  int digitsArray[digits];
  int pos = digits - 1;

  // compute array
  while (digits > 0)
  {
    int digit = candidate % 10;
    digitsArray[pos] = digit;
    digits--;
    pos--;
    candidate /= 10;
  }

  // compute combination
  int combination = 0;
  for (int i = 0; i < digits_1; ++i)
  {
    combination += pow(digitsArray[i], digits_1);
  }

  return (candidate_1 == combination);
}
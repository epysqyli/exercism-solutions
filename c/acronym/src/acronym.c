#include "acronym.h"

char *abbreviate(const char *phrase)
{
  if (phrase == NULL || strlen(phrase) == 0)
  {
    return NULL;
  }

  int delimiters = 0;

  for (size_t i = 0; i < strlen(phrase); i++)
  {
    if (phrase[i] == ' ' || phrase[i] == '-')
    {
      delimiters++;
    }
  }

  char *acronim = calloc(delimiters, sizeof(char));

  int j = 1;
  acronim[0] = phrase[0];
  
  for (size_t i = 1; i < strlen(phrase); i++)
  {
    if (!isalpha((unsigned char)phrase[i]))
    {
      if (phrase[i + 1] == ' ' || (ispunct((unsigned char)phrase[i + 1])) || phrase[i] == '\'') {
        continue;
      }
      acronim[j] = toupper(phrase[i + 1]);
      j++;
    }
  }

  return (char *)acronim;
}
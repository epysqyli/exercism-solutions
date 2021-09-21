#include "isogram.h"

bool is_isogram(const char phrase[])
{
  if (phrase == NULL)
  {
    return false;
  }

  size_t len = strlen(phrase);
  char *lowerstring = calloc(len, sizeof(char));
  bool chars[26] = { false };

  // string to lower case
  for (size_t i = 0; phrase[i]; i++)
  {
    lowerstring[i] = tolower((unsigned char)phrase[i]);
  }

  bool res = true;
  // check string for duplicate characters
  for (size_t i = 0; i < len; i++)
  {
    if (isalpha((unsigned)lowerstring[i]))
    {
      if (!chars[lowerstring[i] - 'a']) {
        chars[lowerstring[i] - 'a'] = true;
      }
      else {
        res = false;
        break;
      }
    }
  }
  free(lowerstring);
  return res;
}
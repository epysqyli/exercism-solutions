#include "pangram.h"

bool is_pangram(const char *sentence)
{
  if (sentence == NULL) {
    return false;
  }

  bool res = true;
  int ascii_base = 97;
  int ascii_length = 26;

  size_t len = strlen(sentence);
  int pangram[ascii_length];
  memset(pangram, 0, ascii_length * sizeof(int));

  for (size_t i = 0; i < len; i++)
  {
    if (isalpha((unsigned char)(sentence[i])))
    {
      int index = tolower((unsigned char)(sentence[i])) - ascii_base;
      if (pangram[index] == 0)
        pangram[index] = tolower((unsigned char)(sentence[i]));
    }
  }

  for (int i = 0; i < ascii_length; i++)
  {
    if (pangram[i] == 0)
    {
      res = false;
      break;
    }
  }

  return res;
}
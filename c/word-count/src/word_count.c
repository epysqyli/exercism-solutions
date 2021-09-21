#include "word_count.h"

void remove_punct_and_make_lower_case(char *p)
{
  char *src = p, *dst = p;

  while (*src)
  { 
    if (*src == *",") {
      *dst = *" ";
    }
    else if (ispunct((unsigned char)*src) && *src != *"'")
    {
      /* Skip this character */
      src++;
    }
    else if (isupper((unsigned char)*src))
    {
      /* Make it lowercase */
      *dst++ = tolower((unsigned char)*src);
      src++;
    }
    else if (src == dst)
    {
      /* Increment both pointers without copying */
      src++;
      dst++;
    }
    else
    {
      /* Copy character */
      *dst++ = *src++;
    }
  }

  *dst = 0;
}

int count_words(const char *sentence, word_count_word_t *words)
{
  int str_len = strlen(sentence);
  char delim[] = "\n, '";
  int total_words = 0;
  for (int i = 0; i < str_len; i++)
  {
    if (*delim == sentence[i])
    {
      total_words++;
    }
  }

  total_words++; // n blank chars mean n+1 words

  // avoid strtok removing the const char of sentence
  char sentence_copy[str_len];
  strncpy(sentence_copy, sentence, str_len + 1);

  remove_punct_and_make_lower_case(sentence_copy);
  char *ptr = strtok(sentence_copy, delim);

  int length = 0;
  int counter = 0;
  int found = 0;
  while (ptr != NULL)
  {
    while (*(ptr + length) != 0)
    {
      length++;
    }

    for (int i = 0; i < counter; i++)
    {
      if (strcmp(words[i].text, ptr) == 0)
      {
        words[i].count++;
        found = 1;
        break;
      }
    }

    if (!found)
    {
      strncpy(words[counter].text, ptr, length);
      words[counter].count = 1;
      counter++;
    }

    found = 0;
    length = 0;
    ptr = strtok(NULL, delim);
  }

  return counter;
}
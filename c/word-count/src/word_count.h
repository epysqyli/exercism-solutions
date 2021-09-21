#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 50

// results structure
typedef struct word_count_word
{
   char text[MAX_WORD_LENGTH + 1]; // allow for the string to be null-terminated
   int count;
} word_count_word_t;

void remove_punct_and_make_lower_case(char *p);

#define EXCESSIVE_LENGTH_WORD -1
#define EXCESSIVE_NUMBER_OF_WORDS -2

int count_words(const char *sentence, word_count_word_t *words);

#endif

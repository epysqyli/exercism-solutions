// no refactoring was performed
#include "matching_brackets.h"

bool is_paired(const char *input)
{
  typedef struct Pair
  {
    char first;
    char second;
  } Pair_t;

  int len = strlen(input);
  int opening_items = 0;
  int closing_items = 0;

  // return false if first found item is a closing one
  for (int i = 0; i < len; i++)
  {
    if (input[i] == '(' || input[i] == ')' || input[i] == '[' || input[i] == ']' || input[i] == '{' || input[i] == '}')
    {
      if (i == 0)
      {
        if (input[i] == ')' || input[i] == ']' || input[i] == '}')
        {
          return false;
        }
      }
    }
  }

  // return false if a closing item comes immediately after a different opening one
  for (int i = 0; i < len; i++)
  {
    for (int j = 1; j < len; j++)
    {
      if (j - i == 1)
      {
        if (input[i] == '(')
        {
          if (input[j] == ']' || input[j] == '}')
            return false;
        }
        else if (input[i] == '[')
        {
          if (input[j] == ')' || input[j] == '}')
          {
            return false;
          }
        }
        else if (input[i] == '{')
        {
          if (input[j] == ')' || input[j] == ']')
          {
            return false;
          }
        }
      }
    }
  }

  // identify the number of items
  for (int i = 0; i < len; i++)
  {
    if (input[i] == '(' || input[i] == '[' || input[i] == '{')
    {
      opening_items++;
    }
  }

  for (int i = 0; i < len; i++)
  {
    if (input[i] == ')' || input[i] == ']' || input[i] == '}')
    {
      closing_items++;
    }
  }

  // return false if pairs cannot be built
  if (opening_items != closing_items)
  {
    return false;
  }

  // initialize Pair_t array to 0 entries based on items length and set items back to 0
  int items = opening_items;
  Pair_t pairs_array[items];
  for (int i = 0; i < items; i++)
  {
    pairs_array[i].first = 0;
    pairs_array[i].second = 0;
  }

  // assign opening items to the pairs_array
  items = 0;
  for (int i = 0; i < len; i++)
  {
    if (input[i] == '(' || input[i] == '[' || input[i] == '{')
    {
      pairs_array[items].first = input[i];
      items++;
    }
  }

  // assign closing items to existing Pair_t elements matching with opening items
  for (int i = 0; i < len; i++)
  {
    if (input[i] == ')' || input[i] == ']' || input[i] == '}')
    {
      for (int j = 0; j < items; j++)
      {
        if (!pairs_array[j].second && pairs_array[j].first == '(' && input[i] == ')')
        {
          pairs_array[j].second = input[i];
        }
        else if (!pairs_array[j].second && pairs_array[j].first == '[' && input[i] == ']')
        {
          pairs_array[j].second = input[i];
        }
        else if (!pairs_array[j].second && pairs_array[j].first == '{' && input[i] == '}')
        {
          pairs_array[j].second = input[i];
        }
      }
    }
  }

  // check whether all pairs are complete
  items = opening_items;
  for (int i = 0; i < items; i++)
  {
    if (!pairs_array[i].first || !pairs_array[i].second)
      return false;
  }

  return true;
}
#include "rail_fence_cipher.h"

char *encode(char *text, size_t rails)
{
  int length = strlen(text);
  char strings[rails][length];

  int i = 0;
  int level = 0;
  int depth = rails - 1;
  int flip = 0;
  char dot = '.';

  // build rails
  while (i < length)
  {

    if (level == 0)
    {
      strings[level][i] = text[i];
      for (int y = 1; y <= depth; y++)
      {
        strings[level + y][i] = dot;
      }
    }

    if (level > 0 && level < depth)
    {
      strings[level][i] = text[i];

      for (int y = level - 1; y >= 0; y--)
      {
        strings[y][i] = dot;
      }

      for (int y = level + 1; y <= depth; y++)
      {
        strings[y][i] = dot;
      }
    }

    if (level == depth)
    {
      strings[level][i] = text[i];
      for (int y = depth; y > 0; y--)
      {
        strings[level - y][i] = dot;
      }
    }

    // update level value, implement flow switch
    if (!flip)
    {
      if (level < depth)
      {
        level++;
      }
      else
      {
        level--;
        flip = 1;
      }
    }
    else
    {
      if (level < depth && level != 0)
      {
        level--;
      }
      else if (level == 0)
      {
        level++;
        flip = 0;
      }
    }

    i++;
  }

  // build encoded string
  char *encodedString = calloc(length, sizeof(char));

  int l = 0;
  for (size_t i = 0; i < rails; i++)
  {
    for (int y = 0; y < length; y++)
    {
      if (isalpha((unsigned char)strings[i][y]))
      {
        encodedString[l] = strings[i][y];
        l++;
      }
    }
  }

  return encodedString;
}

char *decode(char *ciphertext, size_t rails)
{
  int length = strlen(ciphertext);
  char strings[rails][length];

  int i = 0;
  int depth = rails - 1;
  int level = 0;
  char dot = '.';
  int flip = 0;
  char marker = '?';

  // build dotted rails scheme with markers = '?'
  while (i < length)
  {

    if (level == 0)
    {
      strings[level][i] = marker;
      for (int y = 1; y <= depth; y++)
      {
        strings[level + y][i] = dot;
      }
    }

    if (level > 0 && level < depth)
    {
      strings[level][i] = marker;

      for (int y = level - 1; y >= 0; y--)
      {
        strings[y][i] = dot;
      }

      for (int y = level + 1; y <= depth; y++)
      {
        strings[y][i] = dot;
      }
    }

    if (level == depth)
    {
      strings[level][i] = marker;
      for (int y = depth; y > 0; y--)
      {
        strings[level - y][i] = dot;
      }
    }

    // update level value, implement flow switch
    if (!flip)
    {
      if (level < depth)
      {
        level++;
      }
      else
      {
        level--;
        flip = 1;
      }
    }
    else
    {
      if (level < depth && level != 0)
      {
        level--;
      }
      else if (level == 0)
      {
        level++;
        flip = 0;
      }
    }

    i++;
  }

  // replace markers with actual chars
  int y = 0;
  for (size_t l = 0; l < rails; l++)
  {
    for (int i = 0; i < length; i++)
    {
      if (strings[l][i] != dot)
      {
        strings[l][i] = ciphertext[y];
        y++;
      }
    }
  }

  // build decoded string traversing the levels in correct order
  i = 0;
  level = 0;
  char *decodedStr = calloc(length, sizeof(char));

  while (i < length)
  {
    decodedStr[i] = strings[level][i];
    i++;

    // update level value, implement flow switch
    if (!flip)
    {
      if (level < depth)
      {
        level++;
      }
      else
      {
        level--;
        flip = 1;
      }
    }
    else
    {
      if (level < depth && level != 0)
      {
        level--;
      }
      else if (level == 0)
      {
        level++;
        flip = 0;
      }
    }
  }

  return decodedStr;
}

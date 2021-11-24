#include "binary_search.h"

bool in_array(int value, const int *arr, size_t length)
{
  bool res = false;
  for (size_t i = 0; i < length; i++)
  {
    res = (arr[i] == value) ? true : false;
    if (res)
      break;
  }

  return res;
}

int *address = NULL;

int *binary_search(int value, const int *arr, size_t length)
{
  if (!in_array(value, arr, length))
    return NULL;

  size_t half = length / 2;

  if (value == arr[half])
  {
    address = (int *)&arr[half];
  }

  if (value < arr[half])
  {
    const int *left[half];
    for (size_t i = 0; i < half; i++)
    {
      left[i] = &arr[i];
    }

    binary_search(value, *left, half);
  }

  if (value > arr[half])
  {
    const int *right[half];
    for (size_t i = 0; i < half; i++)
    {
      right[i] = &arr[half + i + 1];
    }

    binary_search(value, *right, half);
  }

  return address;
}
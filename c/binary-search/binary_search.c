#include "binary_search.h"

int *address = NULL;

int *binary_search(int value, const int *arr, size_t length)
{
  size_t half = length / 2;

  if ((half == 0 && value != arr[half]) || length == 0)
  {
    address = NULL;
  }
  else if (value == arr[half])
  {
    address = (int *)&arr[half];
  }
  else if (value < arr[half])
  {
    const int *left[half];
    for (size_t i = 0; i < half; i++)
    {
      left[i] = &arr[i];
    }

    binary_search(value, *left, half);
  }
  else if (value > arr[half])
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
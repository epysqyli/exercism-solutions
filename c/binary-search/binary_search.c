#include "binary_search.h"

int counter = 0;

int *binary_search(int value, const int *arr, size_t length)
{
  int *address = NULL;

  // even and odd cases?
  size_t half = length / 2;

  if (value == arr[half])
  {
    address = (int *)&arr[half];
  }
  else if (value == arr[0] && length == 1)
  {
    address = (int *)&arr[0];
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

  printf("Returned: %p - counter: %d\n", (void *)&arr[half], counter);
  counter++;

  return address;
}
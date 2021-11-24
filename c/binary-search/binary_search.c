#include "binary_search.h"

int counter = 0;
int *global_address = NULL;

int *binary_search(int value, const int *arr, size_t length)
{
  int *address;

  // even and odd cases?
  size_t half = length / 2;

  if (value == arr[half])
  {
    address = (int *)&arr[half];
  }

  if (value == arr[0] && length == 1)
  {
    address = (int *)&arr[0];
    global_address = address;
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

  printf("Returned: %p - counter: %d - half value: %ld\n", (void *)&arr[half], counter, half);
  printf("Global address: %p\n", (void *)global_address);
  counter++;

  if (global_address != NULL)
  {
    return global_address;
  }
  else
  {
    return NULL;
  }
}
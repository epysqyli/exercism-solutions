#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

int *binary_search(int value, const int *arr, size_t length);

bool in_array(int value, const int *arr, size_t length);

#endif

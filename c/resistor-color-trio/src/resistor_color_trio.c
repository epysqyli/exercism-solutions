#include <math.h>
#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *colors)
{
  resistor_value_t item;
  
  // calculate item value
  item.value = colors[0] * pow(10, colors[2] + 1) + colors[1] * pow(10, colors[2]);

  // assign ohms or kiloohms to item.unit
  item.unit = OHMS;

  // adjust item value and unit if greater than 1000
  if (item.value > 1000) {
    item.value /= 1000;
    item.unit = KILOOHMS;
  }

  // return resistor_value_t item
  return item;
}
#include "resistor_color.h"

int color_code(resistor_band_t color)
{
  return color;
}

resistor_band_t *colors(void)
{
  static resistor_band_t values[] = {BLACK,
                                     BROWN,
                                     RED,
                                     ORANGE,
                                     YELLOW,
                                     GREEN,
                                     BLUE,
                                     VIOLET,
                                     GREY,
                                     WHITE};
  return values;
}
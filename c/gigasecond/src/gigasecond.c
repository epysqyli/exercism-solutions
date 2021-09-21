#include "gigasecond.h"
#define GIGASECOND 1000000000 // a billion seconds

time_t gigasecond_after(time_t var) {
  return var + GIGASECOND;
}

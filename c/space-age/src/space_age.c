#include "space_age.h"
#define EARTH_SECONDS 31557600;
#define ORBITAL_MERCURY 0.2408467 / EARTH_SECONDS;
#define ORBITAL_VENUS 0.61519726 / EARTH_SECONDS;
#define ORBITAL_MARS 1.8808158 / EARTH_SECONDS;
#define ORBITAL_JUPITER 11.862615 / EARTH_SECONDS;
#define ORBITAL_SATURN 29.447498 / EARTH_SECONDS;
#define ORBITAL_URANUS 84.016846 / EARTH_SECONDS;
#define ORBITAL_NEPTUNE 164.79132 / EARTH_SECONDS;

float age(planet_t planet, int64_t seconds)
{
  float res = 0.0;
  if (planet == EARTH)
  {
    res = seconds / EARTH_SECONDS;
  }
  else if (planet == MERCURY)
  {
    res = seconds / ORBITAL_MERCURY;
  }
  else if (planet == VENUS)
  {
    res = seconds / ORBITAL_VENUS;
  }
  else if (planet == MARS)
  {
    res = seconds / ORBITAL_MARS;
  }
  else if (planet == JUPITER)
  {
    res = seconds / ORBITAL_JUPITER;
  }
  else if (planet == SATURN)
  {
    res = seconds / ORBITAL_SATURN;
  }
  else if (planet == URANUS)
  {
    res = seconds / ORBITAL_URANUS;
  }
  else if (planet == NEPTUNE)
  {
    res = seconds / ORBITAL_NEPTUNE;
  }
  return res;
}
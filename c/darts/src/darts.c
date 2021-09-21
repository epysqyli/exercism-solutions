#include <math.h>
#include "darts.h"

int score(coordinate_t landing_position)
{
  int score;
  float distance = sqrt(pow(landing_position.x, 2) + pow(landing_position.y, 2));

  // check landing position to assing the score
  // find the distance bewteen a point and the center

  if (distance <= 1)
  {
    score = 10;
  }
  else if (distance <= 5)
  {
    score = 5;
  }
  else if (distance <= 10)
  {
    score = 1;
  }
  else
  {
    score = 0;
  }

  return score;
}
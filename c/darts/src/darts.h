#ifndef DARTS_H
#define DARTS_H

typedef struct coordinate_t
{
  float x;
  float y;
} coordinate_t;

int score(coordinate_t landing_position);

#endif
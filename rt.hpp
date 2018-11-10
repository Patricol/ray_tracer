//Patrick Collins (patricol)
//This file lays out structs for rays and colors.

#include "Vector.hpp"
#ifndef RT_HPP
#define RT_HPP

//RAY_T with origin and direction fields
typedef struct {
  Vector org;//origin
  Vector dir;//direction
}RAY_T;

//COLOR_T with R, G, B fields
//Colors should be between 0 and 1.
typedef struct {
  double R;
  double G;
  double B;
}COLOR_T;


#endif
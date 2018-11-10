//Patrick Collins (patricol)
//This file lays out the Object struct, which is used to tie colors and spheres together.

#include "rt.hpp"
#include "Sphere.hpp"
#ifndef OBJ_HPP
#define OBJ_HPP

//OBJ_T with sphere, color, and next fields
typedef struct OBJ {
  Sphere sphere;
  COLOR_T color;
  struct OBJ *next;
}OBJ_T;


#endif
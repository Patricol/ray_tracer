//Patrick Collins (patricol)
//This file lays out the Sphere class, including prototypes for its methods.

#include "rt.hpp"
#include "Vector.hpp"
#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere {
    Vector ctr;
    double radius;
  public:
    void set(Vector ctr, double radius);
    bool intersect_sphere (RAY_T ray, double &t, Vector &int_pt, Vector &normal);
};


#endif
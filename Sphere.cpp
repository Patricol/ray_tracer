//Patrick Collins (patricol)
//This file implements the Sphere class with its methods.

#include <cmath>
#include "Vector.hpp"
#include "Sphere.hpp"

//sets parameters for an instance of the sphere class.
void Sphere::set (Vector input_ctr, double input_radius)
{
  this->ctr = input_ctr;
  this->radius = input_radius;
}

//computes intersection of ray and sphere; returns true if intersection; false otherwise. t is set to distance from camera to sphere intersection. Also computes the intersection point and normal.
bool Sphere::intersect_sphere (RAY_T ray, double &t, Vector &int_pt, Vector &normal)
{
  //&t is a reference paramter.
  double A = 1;
  
  //redone to account for hidden x,y,z.
  double B = 2.0 * ray.dir.dot(ray.org - ctr);
  
  //redone to account for hidden x,y,z.
  double C = (ray.org - ctr).dot(ray.org - ctr) - radius*radius;

  //Quadratic formula. because of plus and minus, gives two distances. t0 and t1. One of them is closer/smaller, and that's the only one we can actually see.
  //remember we can't take a square root of a negative number. If B^2 - 4AC is negative, we return zero because we couldn't find a soution/intersection.
  if ((B*B - 4*A*C)<0) {
    return false;
    
  } else if ((B*B - 4*A*C) == 0){
    //just grazes the edge, only one intersection.
    return false;//as advised by email.
    
  } else {
    double t0 = ((0 - B + sqrt(B*B - 4*A*C))/2*A);
    double t1 = ((0 - B - sqrt(B*B - 4*A*C))/2*A);
    if (t0<0 && t1<0) {return false;}//intersection is behind us
    
    //there won't be any cases where one is positive and one is negative.
    
    if (t0<t1){t = t0;}
    else {t = t1;}
    
    int_pt = ray.org + ray.dir*t;
    normal = (int_pt - ctr)/radius;
    return true;
  }
}
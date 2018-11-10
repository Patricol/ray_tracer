//Patrick Collins (patricol)
//This file implements the Light class, used for ambient, diffuse, and specular lighting for raytracing.

#include <cmath>
#include "Light.hpp"

//constructor for Light
Light::Light(double x,double y,double z) {
  this->loc = Vector(x,y,z);
}

//Illuminate function for the light class, which calculates ambient, diffuse, and specular lighting.
COLOR_T Light::illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal) {
  COLOR_T col;
  
  //Ambient calculations
  col.R = surface_col.R * 0.1;
  col.G = surface_col.G * 0.1;
  col.B = surface_col.B * 0.1;
  
  //Diffuse calculations
  double dot;
  Vector L;
  L = loc - int_pt;
  L.normalize();
  dot = L.dot(normal);
  if (dot > 0) {
    col.R += dot * surface_col.R;
    col.G += dot * surface_col.G;
    col.B += dot * surface_col.B;
  }
  //Specular calculations
  Vector R;
  R = L - (normal * 2 * normal.dot(L));
  R.normalize();
  double dot2 = R.dot(ray.dir);
  if (dot2 > 0) {
    col.R += pow(dot2, 200);
    col.G += pow(dot2, 200);
    col.B += pow(dot2, 200);
  }
  
  return col;
}
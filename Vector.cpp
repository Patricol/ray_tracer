//Patrick Collins (patricol)
//This file defines functions that use the newly defined vectors.

#include <cmath>
#include "Vector.hpp"


//constructor with no paramters.
Vector::Vector (void) {}

//constructor when given three doubles.
Vector::Vector (double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

//sets the components of the vector.
void Vector::set(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

//computes and returns normalized vector v
void Vector::normalize (void) {
  //Normalized means the length is equal to 1.
  //If our vector is 1,2,3, we have to divide each of those components by the vector's length.
  //How do we get the vector's length? Root of 1^2 + 2^2 + 3^2 in this case.
  double initial_length = sqrt(x*x + y*y + z*z);
  if (initial_length!=0) {
    x = x/initial_length;
    y = y/initial_length;
    z = z/initial_length;
  }
}

//computes and returns dot product of the two vectors.
double Vector::dot (Vector v) {
  return (x * v.x + y * v.y + z * v.z);
}

//overloads the + operator when used with two vectors.
Vector Vector::operator+ (Vector v) {
  return Vector(x+v.x,y+v.y,z+v.z);
}

//overloads the - operator when used with two vectors.
Vector Vector::operator- (Vector v) {
  return Vector(x-v.x,y-v.y,z-v.z);
}

//overloads the * operator when used with two vectors.
Vector Vector::operator* (Vector v) {
  return Vector(x*v.x,y*v.y,z*v.z);
}

//overloads the * operator when used with a vector and a double.
Vector Vector::operator* (double number) {
  return Vector(x*number,y*number,z*number);
}

//overloads the / operator when used with a vector and a double.
Vector Vector::operator/ (double number) {
  return Vector(x/number,y/number,z/number);
}

//sums the scalar values of the x y and z components.
double Vector::sum_components (void) {
  return (x + y + z);
}

//gives the length of the vector.
double Vector::length (void) {
  return sqrt(x*x + y*y + z*z);
}

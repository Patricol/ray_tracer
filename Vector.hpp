//Patrick Collins (patricol)
//This file creates the Vector class, laying out its characteristics x,y and z, and prototyping methods used as a part of it.

#ifndef VECTOR_HPP
#define VECTOR_HPP


class Vector {
  private:
    double x;
    double y;
    double z;

  public:
    Vector (void);
    Vector (double x, double y, double z);
    void set(double x, double y, double z);
    void normalize (void);
    double dot (Vector v);
    Vector operator+ (Vector v);
    Vector operator- (Vector v);
    Vector operator* (Vector v);
    Vector operator* (double number);
    Vector operator/ (double number);
    double sum_components (void);
    double length (void);
};

#endif
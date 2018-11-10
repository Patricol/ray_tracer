//Patrick Collins (patricol)
//This project implements a simple ray tracing renderer and produces a 1000x1000 PPM image of shaded spheres, using a file with sphere information.

#include <cmath>
#include "obj.hpp"
#include "rt.hpp"
#include "Vector.hpp"
#include "Light.hpp"
#include <iostream>

//reads spheres from std::cin; creates linked list
void read_objs (OBJ_T **list){
  double cx, cy, cz, rad, R, G, B;
  OBJ_T *node;
  OBJ_T *newlist;
  
  newlist = NULL;
  while (std::cin >> cx >> cy >> cz >> rad >> R >> G >> B) {
    node = new(OBJ_T);
    
    //Create a sphere with the proper properties, and attach it to the new OBJ_T object.
    Sphere newsphere;
    Vector ctr;
    ctr.set(cx,cy,cz);
    newsphere.set(ctr, rad);
    node->sphere = newsphere;
    
    //Create a color with the proper properties, and attach it to the new OBJ_T object.
    COLOR_T newcolor;
    newcolor.R = R;
    newcolor.G = G;
    newcolor.B = B;
    node->color = newcolor;
    
    //Move the new OBJ_T object to the front of the linked list.
    node->next = newlist;
    newlist = node;
  }
  *list = newlist;
}

 

//iterates through linked list; finds closest intersection point and closest normal. Calls the illuminate method for light and returns lighted color of the closest sphere.
COLOR_T trace(RAY_T ray, OBJ_T *list, Light light){
  OBJ_T *curr;
  
  double t;
  double min_t = 10001;//good enough, considering our input files.
  
  Vector int_pt;
  Vector normal;
  Vector closest_int_pt;
  Vector closest_normal;
  
  //Initialize to black.
  COLOR_T pixel;
  pixel.R = 0;
  pixel.G = 0;
  pixel.B = 0;
  
  //Check each sphere to see if the current ray intersects with it.
  for (curr = list; curr !=NULL; curr = curr->next){
    if (curr->sphere.intersect_sphere(ray, t, int_pt, normal)){
      if (t<min_t){
	//New closest sphere is found, so we must modify the color and remember how far away it is.
	min_t = t;
	pixel.R = curr->color.R;
	pixel.G = curr->color.G;
	pixel.B = curr->color.B;
	//also save the closest intersection point and normal.
	closest_int_pt = int_pt;
	closest_normal = normal;
      }
    }
  }
  
  if (min_t < 10001) {//if you found a closest object
    pixel = light.illuminate(ray, pixel, closest_int_pt, closest_normal);
  }
  return pixel;
}


//creates list of spheres from input, initializes image file and light; loops through pixels; sets ray; prints pixels; frees linked list
int main(){
  //create list of spheres
  OBJ_T *list;
  read_objs(&list);
  
  //Initialize the light based on the provided location.
  Light light = Light(5.0, 10.0, 0.0);
  
  //write ppm header, initializing the image file.
  std::cout << "P6\n 1000 1000 255\n";
  
  //loop through pixels
  int y;
  int x;
  for (y = 0; y<1000; y++){
    for (x = 0; x<1000; x++){
      
      //set ray
      RAY_T ray;
      ray.org = Vector(0,0,0);
      ray.dir = Vector(-0.5 + x/1000.0, 0.5 - y/1000.0, 1);
      
      //normalize ray.dir
      ray.dir.normalize();
      
      //Start the actual tracing.
      COLOR_T pixel = trace(ray, list, light);
      
      //cap color values
      if (pixel.R > 1.0) {pixel.R = 1.0;}
      if (pixel.G > 1.0) {pixel.G = 1.0;}
      if (pixel.B > 1.0) {pixel.B = 1.0;}
      
      //print a pixel to the file
      std::cout << (unsigned char)(pixel.R * 255) << (unsigned char)(pixel.G * 255) << (unsigned char)(pixel.B * 255);
    }
  }
  //free/delete the linked list nodes.
  OBJ_T *tofree = list;
  while(tofree != NULL){
  list = list->next;
  delete(tofree);
  tofree = list;
  }
  return 0;
}
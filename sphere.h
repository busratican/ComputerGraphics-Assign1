
#ifndef __SPHERE_H_INCLUDED__
#define __SPHERE_H_INCLUDED__

class Object3D;

#include "object3d.h"

class Sphere : public Object3D
{
    public:
      
       Sphere(Vec3f center, float radius, Vec3f color);
    Vec3f getC(){
      return color;
     }
        bool intersect(const Ray &r, Hit &h, float tmin);
        bool geometric_solution_intersect(const Ray &r, Hit &h, float tmin);
    private:
        Vec3f center;
        float radius;
		Vec3f color;
       
};

#endif // __SPHERE_H_INCLUDED__



















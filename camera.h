#ifndef __CAMERA_H_INCLUDED__
#define __CAMERA_H_INCLUDED__

#include <cmath>
#include <cfloat>
#include "ray.h"
#include "vectors.h"

class Camera
{
    public:
        virtual Ray generateRay(Vec2f point) = 0;
       
};

class OrthographicCamera : public Camera
{
    public:
        OrthographicCamera(Vec3f c, Vec3f direction, Vec3f u, float s);
        ~OrthographicCamera();
        Ray generateRay(Vec2f point);
      

    private:
        Vec3f center;
        Vec3f dir;
        Vec3f up;
        Vec3f horz;
        float size;

};


#endif //__CAMERA_H_INCLUDED__

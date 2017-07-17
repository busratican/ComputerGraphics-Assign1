#include "camera.h"

/* Orthographic Camera */
OrthographicCamera::OrthographicCamera(Vec3f c, Vec3f direction, Vec3f u, float s)
{
    center = c;
    dir = direction; dir.Normalize(); 

    if(u.Dot3(dir) != 0)
    {
        Vec3f t;
        Vec3f::Cross3(t,u,dir);
        Vec3f::Cross3(up,dir,t);
    }
    else
        up = u;

    up.Normalize();
    
    size = s;
    Vec3f::Cross3(horz, dir, up);
    horz.Normalize();
}

OrthographicCamera::~OrthographicCamera() {}

Ray OrthographicCamera::generateRay(Vec2f point)
{
  
    Vec3f p(center + (point.y()-.5f)*(size*up) + (point.x()-.5f)*(size*horz));
    return (Ray(dir,p));
}



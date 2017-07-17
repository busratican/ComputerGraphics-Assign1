#include "sphere.h"

Sphere::Sphere(Vec3f center, float radius, Vec3f color)
{
   this-> center = center;
     this->radius = radius;
    this-> color= color;
}
 


bool Sphere::intersect(const Ray &r, Hit &h, float tmin)
{     
		float sphere_radius=this->radius;
		float a=1;
		float b=2*r.getDirection().Dot3(r.getOrigin()-center);
		float c=(r.getOrigin()-center).Dot3(r.getOrigin()-center)-(sphere_radius*sphere_radius);
		float disc=sqrt(b*b-4*a*c);
		
		if(b*b-4*a*c>=0)
      	{
		float newVal=(-b-disc)/(2*a);	
		float oldVal=h.getT();
		Vec3f color_new=getC();
    		   if(newVal>=tmin && newVal<oldVal){
        			h.set(newVal,color_new);
        			return true;
    					  }
   						 return false;
    					 }

				if(disc <0) return false;
   		

   }




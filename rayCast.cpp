#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <vector>
#include <cfloat> // FLT_MAX
#include <iostream>
#include <limits>
#include <cstddef>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <malloc.h>
using namespace std;

#include "object3d.h"
#include "scene_parser.h"

#include "image.h"
#include "vectors.h"
#include "sphere.h"
#include "camera.h"
#include "ray.h"
#include "hit.h"
#include "group.h"
#include "matrix.h"

float clamp(float a)
{
    if(a > 1.0f)
        return 1.0f;
    else if(a < 0.0f)
        return 0.0f;
    else
        return a;
}



int main(int argc, char * argv[])
{

	char *input_file =NULL;
	int width = 100;
	int height = 100;
	char *output_file = NULL;
	float depth_min = 0;
	float depth_max = 1;
	char *depth_file = NULL;
	
	
	// sample command lines:
	//-input scene.txt -size 100 100 -output image.tga
	//raycast -input scene.txt -size 100 100 -depth 8.5 10.5 depth.tga

	for (int i = 1; i < argc; i++) {
	  if (!strcmp(argv[i],"-input")) {
	    i++; assert (i < argc); 
	    input_file = argv[i];
	    
	  } else if (!strcmp(argv[i],"-size")) {
	    i++; assert (i < argc); 
	    width = atoi(argv[i]);
	    i++; assert (i < argc); 
	    height = atoi(argv[i]);
	  } else if (!strcmp(argv[i],"-output")) {
	    i++; assert (i < argc); 
	    output_file = argv[i];
	  } else if (!strcmp(argv[i],"-depth")) {
	    i++; assert (i < argc); 
	    depth_min = atof(argv[i]);
	    i++; assert (i < argc); 
	    depth_max = atof(argv[i]);
	    i++; assert (i < argc); 
	    depth_file = argv[i];
	  } else {
	    printf ("whoops error with command line argument %d: '%s'\n",i,argv[i]);
	    assert(0);
	  }
	
	}	
	
	 bool  depthout=false,out=false;
     if(depth_file != NULL)
        depthout = true;
     if(output_file != NULL)
        out = true;
	
	SceneParser* s= new SceneParser(input_file);
	Group* g=s->getGroup();    
	Camera* c=s->getCamera();
	
	
	Image* depth_image=new Image(width,height);
	Image* out_image=new Image(width,height);
	
		const Vec3f background=s->getBackgroundColor();
		depth_image->SetAllPixels(background);
		out_image->SetAllPixels(background);
		
		




	
		for(int i=0;i<width;i++){
		
			for(int j=0;j<height;j++) {
				
				 float xi = (float)i / width; 
            		float yj = (float)j / height;
            			Vec2f p(xi,yj); //0,0 to 1,1
            				Ray r = c->generateRay(p);
            			
          	Hit hit=Hit(numeric_limits<float>::max(),Vec3f(1,0,0));
            			
            			
	         	int tmin=numeric_limits<float>::min(); 
				
				bool isNearest=g->intersect(r,hit,tmin);
				
				if(depthout) {
					int tmin=numeric_limits<float>::min(); 
							Hit hit=Hit(numeric_limits<float>::max(),Vec3f(1,0,0));
								bool isNearest=g->intersect(r,hit,tmin);
				
						if(isNearest==true){
				 		float dc = clamp((depth_max-hit.getT())/(depth_max-depth_min));
                		 depth_image->SetPixel(i,j,Vec3f(dc,dc,dc));
                		 }
                    }
                    
				if(depthout==false && isNearest==true){
				  Vec3f color=hit.getColor();
			      out_image->SetPixel(i,j,color);
			      
			        }
			     
			
	 	        }
	 	
       }
       cout<<"Hello world!"<<endl;
       
      if(depthout)
      {
      	depth_image->SaveTGA(depth_file);
      	cout<<depth_file<<endl;
	  }
        	
   			if(out)
   			{
   			out_image->SaveTGA(output_file);
   				cout<<output_file<<endl;
		   }
           
	return 0;
}

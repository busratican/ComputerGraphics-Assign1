#ifndef _SceneParser_H_
#define _SceneParser_H_

#include "vectors.h"
#include <string.h>
class Group;
class Camera;
class Sphere;

#define MAX_PARSER_TOKEN_LENGTH 100

// ====================================================================
// ====================================================================

class SceneParser {

public:
/*void parseFile() {
  //
  // at the top level, the scene can have a camera, 
  // background color and a group of objects
  // (we will add lights and other things in future assignments)
  //
  char token[MAX_PARSER_TOKEN_LENGTH];    
  while (getToken(token)) { 
    if (!strcmp(token, "OrthographicCamera")) {
      camera = parseOrthographicCamera();
    } else if (!strcmp(token, "Background")) {
      parseBackground();
    } else if (!strcmp(token, "Group")) {
      group = parseGroup();
    } else {
      printf ("Unknown token in parseFile: '%s'\n", token);
      exit(0);
    }
  }
}
void initialize() {
  // initialize some reasonable default values
  group = NULL;
  camera = NULL;
  background_color = Vec3f(0.5,0.5,0.5);
  current_object_color = Vec3f(1,1,1);
  file = NULL;
}
  // CONSTRUCTORS, DESTRUCTOR & INITIALIZE
  SceneParser();
  SceneParser(const char *filename){
  	
  	
  	
  	 initialize();

  // open the file
  assert(filename != NULL);
  const char *ext = &filename[strlen(filename)-4];
  assert(!strcmp(ext,".txt"));
  file = fopen(filename,"r");
  assert (file != NULL);

  // parse the scene
  parseFile();

  // close the file
  fclose(file); 
  file = NULL;


  	
  	
  	
  	
  }
  */
  SceneParser();
  SceneParser(const char *filename);
  	
  ~SceneParser();

  // ACCESSORS
  Group* getGroup() { return group; }
  Camera* getCamera() { return camera; }
  Vec3f getBackgroundColor() { return background_color; }

public:

  // HELPER FUNCTIONS
  void initialize();
  int getToken(char token[MAX_PARSER_TOKEN_LENGTH]);
  void parseFile();
  Group* parseGroup();
  Camera* parseOrthographicCamera();
  void parseBackground();
  void parseMaterial();
  Sphere* parseSphere();
  
  // REPRESENTATION
  Group *group;
  Camera *camera;
  Vec3f background_color;

  Vec3f current_object_color;
  FILE *file;

};

// ====================================================================
// ====================================================================

#endif



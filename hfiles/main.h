#ifndef MAIN_H
#define MAIN_H
using namespace std;
#include <glm/glm.hpp>
#include <vector>



struct Tri{
    glm::vec3 v1;
    glm::vec3 v2;
    glm::vec3 v3;
};

struct Mesh{
    vector<Tri> tris;
};




extern Mesh myMesh;
extern glm::vec3 cameraPos, cameraForward, cameraUp;


#endif
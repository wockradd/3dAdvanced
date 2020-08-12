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

class Mesh{
    public:
        vector<Tri> tris;
        float r,g,b;
        void updateColor(float newR, float newG, float newB){
            r = newR;
            g = newG;
            b = newB;
        }
};





extern glm::vec3 cameraPos, cameraForward, cameraUp;


#endif
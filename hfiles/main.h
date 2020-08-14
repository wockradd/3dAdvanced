#ifndef MAIN_H
#define MAIN_H
using namespace std;
#include <glm/glm.hpp>
#include <vector>



struct Tri{
    glm::vec3 v1;
    glm::vec3 v2;
    glm::vec3 v3;
    glm::vec3 normal;
};

class Mesh{
    public:
        vector<Tri> tris;
        glm::vec3 color;
        void updateColor(float newR, float newG, float newB){
            color.x = newR;
            color.y = newG;
            color.z = newB;
        }
};





extern glm::vec3 cameraPos, cameraForward, cameraUp;


#endif
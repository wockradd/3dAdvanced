#include "./hfiles/controls.h"
#include "./hfiles/main.h"
#include <GL/glut.h>
#include <glm/ext.hpp>
#include <iostream>


//camera rotation is really gross but it works so meh, idk anymore
float yAngle = 0.05;
glm::mat4 Identity = glm::mat4(1);
glm::mat4 rotateYClockwise = glm::rotate(Identity,yAngle,glm::vec3{0,-1,0});
glm::mat4 rotateYCounterClockwise = glm::rotate(Identity,yAngle,glm::vec3{0,1,0});

void buttons(unsigned char key, int x, int y){
    glm::vec3 cameraRight = glm::cross(cameraUp, cameraForward);
    switch(key){
        case 'd':
            {
            glm::vec4 test = {cameraForward.x, cameraForward.y, cameraForward.z,1};
            test = rotateYClockwise*test;
            cameraForward.x = test.x;
            cameraForward.y = test.y;
            cameraForward.z = test.z;
            }
            break;
        case 'a':
            {
            glm::vec4 test = {cameraForward.x, cameraForward.y, cameraForward.z,1};
            test = rotateYCounterClockwise*test;
            cameraForward.x = test.x;
            cameraForward.y = test.y;
            cameraForward.z = test.z;
            }
            break;
        case 'w':
            cameraPos += cameraForward*0.1f;
            break;
        case 's':
            cameraPos -= cameraForward*0.1f;
        break;
        case '8':
            cameraPos += cameraUp*0.1f;
        break;
        case '2':
            cameraPos -= cameraUp*0.1f;
        break;
    }
    glutPostRedisplay();//force redraw
}

#include "./hfiles/controls.h"
#include "./hfiles/main.h"
#include <GL/glut.h>
#include <iostream>


void mouse(int button, int state, int x, int y){

}

void buttons(unsigned char key, int x, int y){
    glm::vec3 cameraRight = glm::cross(cameraUp, cameraForward);
    switch(key){
        case 'd':
            cameraPos -= cameraRight*0.1f;
            break;
        case 'a':
            cameraPos += cameraRight*0.1f;
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

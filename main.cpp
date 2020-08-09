#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>

#include "./hfiles/main.h"
#include "./hfiles/fileStuff.h"
#include "./hfiles/controls.h"

#define WINDOW_HEIGHT 512
#define WINDOW_WIDTH 1024







/*
    TODO
    mouse movements
    lighting / shading
    textures
*/




//global variables
Mesh myMesh;
glm::vec3 cameraPos(0,1,6);
glm::vec3 cameraForward(0,0,-1);
glm::vec3 cameraUp(0,1,0);


void draw(float r, float g, float b){
    glColor3f(r,g,b);
    //drawing
    for(auto tri : myMesh.tris){
        glBegin(GL_POLYGON);
		glVertex3f(tri.v1.x,tri.v1.y,tri.v1.z);
		glVertex3f(tri.v2.x,tri.v2.y,tri.v2.z);
		glVertex3f(tri.v3.x,tri.v3.y,tri.v3.z);
	    glEnd();
    }
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear the buffers
    
    //project
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)WINDOW_WIDTH/(float)WINDOW_HEIGHT, 0.1f, 1000.0f);

	
    //camera postioning
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //do this instead
    glm::vec3 c = cameraForward + cameraPos;
    gluLookAt(cameraPos.x,cameraPos.y,cameraPos.z,c.x, c.y, c.z, cameraUp.x, cameraUp.y, cameraUp.z);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex3f(5,0,5);
        glVertex3f(5,0,-5);
        glVertex3f(-5,0,-5);
        glVertex3f(-5,0,5);
    glEnd();
	draw(1,0,0);
    glPushMatrix();
			glTranslatef(0,0,-2);
			draw(0,1,0);
	glPopMatrix();
     glPushMatrix();
			glTranslatef(1,0,0.0);
			draw(0,0,1);
	glPopMatrix();
    
	
    
    glutSwapBuffers();
}







void init(){
    myMesh = generateMeshFromFile();
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);//not sure
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("3ddddddd");
}




int main(int argc, char** argv){
    glutInit(&argc, argv);
    init();
   
    
    glutDisplayFunc(display);
    glViewport(0,0,WINDOW_WIDTH, WINDOW_HEIGHT);
    glutKeyboardFunc(buttons);
    glutMouseFunc(mouse);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
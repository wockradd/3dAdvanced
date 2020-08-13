#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <glm/ext.hpp>

#include "./hfiles/main.h"
#include "./hfiles/fileStuff.h"
#include "./hfiles/controls.h"

#define WINDOW_HEIGHT 512
#define WINDOW_WIDTH 1024





/*
    TODO
    mouse movements
    lighting
*/




//global variables
Mesh cartMesh,cubeMesh,lightMesh,benchMesh,treeMesh,windmillMesh;
glm::vec3 cameraPos(0,1,0);
glm::vec3 cameraForward(0,0,-1);
glm::vec3 cameraUp(0,1,0);

float windmillAngle = 0.0;



void draw(Mesh m){
    glColor3f(m.r,m.g,m.b);
    //drawing
    for(auto tri : m.tris){
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
    glm::vec3 c = cameraForward + cameraPos;
    gluLookAt(cameraPos.x,cameraPos.y,cameraPos.z,c.x, c.y, c.z, cameraUp.x, cameraUp.y, cameraUp.z);


    //draw the scene
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
        glVertex3f(5,0,5);
        glVertex3f(5,0,-5);
        glVertex3f(-5,0,-5);
        glVertex3f(-5,0,5);
    glEnd();
	glPushMatrix();
		glTranslatef(0,0,4);
		draw(lightMesh);
	glPopMatrix();
    glPushMatrix();
		glTranslatef(0,0,-4);
		draw(treeMesh);
        glTranslatef(1,0,0);
		draw(treeMesh);
        glTranslatef(1,0,0);
		draw(treeMesh);
	glPopMatrix();
    glPushMatrix();
		glTranslatef(-4,0,-4);
        glRotatef(-45,0,1,0);
		draw(cubeMesh);
        glTranslatef(0,1,0);
        draw(cubeMesh);
        glTranslatef(0,1,0);
        draw(cubeMesh);
        glTranslatef(0.6,0.5,0);
        glRotatef(-windmillAngle,1,0,0);
        draw(windmillMesh);
	glPopMatrix();
    glPushMatrix();
		glTranslatef(3,0,0);
        cartMesh.updateColor(1,0,0);
        draw(cartMesh);
        glTranslatef(0,0,3);
        glRotatef(-30,0,1,0);
        cartMesh.updateColor(0,0,1);
        draw(cartMesh);
	glPopMatrix();
    glPushMatrix();
        glTranslatef(3,0.1,-3);
        glRotatef(30,1,1,0);
        cartMesh.updateColor(0,0,1);
        draw(cartMesh);
    glPopMatrix();
    glPushMatrix();
		glTranslatef(-3,0,0);
		draw(benchMesh);
        glTranslatef(0,0,2);
		draw(benchMesh);
	glPopMatrix();
    
    if(windmillAngle >= 360){
        windmillAngle = 0;
    }else{
        windmillAngle+=0.05;
    }
    
    glutPostRedisplay();//force it to redraw, just so the windmill spins
    glutSwapBuffers();
}





void init(){
    
    cartMesh = generateMeshFromFile("./resources/cart.obj");
    cubeMesh = generateMeshFromFile("./resources/cube.obj");
    treeMesh = generateMeshFromFile("./resources/tree.obj");
    lightMesh = generateMeshFromFile("./resources/light.obj");
    benchMesh = generateMeshFromFile("./resources/bench.obj");
    windmillMesh = generateMeshFromFile("./resources/propellor.obj");

    cartMesh.updateColor(1,0,0);
    cubeMesh.updateColor(0,1,0);
    treeMesh.updateColor(0,1,0);
    lightMesh.updateColor(1,1,1);
    benchMesh.updateColor(0,0,1);
    windmillMesh.updateColor(1,0,0);


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
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"

const int WIDTH = 600;
const int HEIGHT = 600;

unsigned char pixels[HEIGHT][WIDTH][3]; //the 3 is rgb

void init()
{
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // clean frame buffer

	glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);

	glutSwapBuffers(); // show all
}

void idle() 
{
	glutPostRedisplay();
}


void main(int argc, char* argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("Pixels Example");

	glutDisplayFunc(display);
	glutIdleFunc(idle);

	init();

	glutMainLoop();
}

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"

const int WIDTH = 600;
const int HEIGHT = 600;

unsigned char pixels[HEIGHT][WIDTH][3]; //the 3 is rgb

double offset = 0.0;

void init()
{
	int i, j;
	double distance;


	//background
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			pixels[i][j][0] = 0;
			pixels[i][j][1] = 0;
			pixels[i][j][2] = 255;
		}
	}

	//yellow circle
	for (i = 0;  i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			distance = sqrt(pow(i - HEIGHT / 2, 2) + pow(j - HEIGHT / 2, 2));
			if (distance < 210)
			{
				pixels[i][j][0] = 255;
				pixels[i][j][1] = 255;
				pixels[i][j][2] = 0;
			}
			
		}
	}

	//small circle for mouth
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			distance = sqrt(pow(i - HEIGHT / 2, 2) + pow(j - HEIGHT / 2, 2));
			if (distance < 140 && distance > 130)
			{
				pixels[i][j][0] = 0;
				pixels[i][j][1] = 0;
				pixels[i][j][2] = 0;
			}

		}
	}

	//rectengle for mouth 
	for (i = 250; i < 440; i++)
	{
		for (j = 150; j < 450; j++)
		{
				pixels[i][j][0] = 255;
				pixels[i][j][1] = 255;
				pixels[i][j][2] = 0;
			
		}
	}

	// left eye
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			distance = sqrt(pow(i - 60 - HEIGHT / 2, 2) + pow(j + 90 - HEIGHT / 2, 2));
			if (distance < 30)
			{
				pixels[i][j][0] = 0;
				pixels[i][j][1] = 0;
				pixels[i][j][2] = 0;
			}

		}
	}

	//right eye
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			distance = sqrt(pow(i - 60 - HEIGHT / 2, 2) + pow(j - 90 - HEIGHT / 2, 2));
			if (distance < 30)
			{
				pixels[i][j][0] = 0;
				pixels[i][j][1] = 0;
				pixels[i][j][2] = 0;
			}

		}
	}


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
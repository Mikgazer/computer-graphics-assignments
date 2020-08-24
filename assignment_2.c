/*

 Grafico rudimentale con la relazione tra il numero delle linee usate e gli FPS a schermo.
 Come è logico pensare, all'aumentare delle linee il numero degli FPS diminuisce, con una relazione simil lineare.
 I miei dati sono diversi da quello del professore forse perchè(?) sto eseguendo da una vm che quindi ha a disposizione meno
 memoria(?).
 Con colori uguali il grafico assumomiglia di più ad una curva, "quasi quadratica"
 Mi sarei aspettato che usando colori diversi la differenza in FPS sarebbe stata maggiore.

 */

#define SAME_COLOR
//#define DIFFERENT_COLORS

#include <stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>

void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(-0.5,-0.5,0.0);

	//draw Axis
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(0.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(1.0,0.0,0.0);
	glEnd();

	#ifdef DIFFERENT_COLORS
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 0.0, 0.0);
		glScalef(2.0,2.0,2.0);
		glPointSize(2.0);
		glVertex3f(0.1,0.53,0.0);
		glVertex3f(0.2,0.51,0.0);
		glVertex3f(0.3,0.475,0.0);
		glVertex3f(0.4,0.420,0.0);
		glVertex3f(0.5,0.378,0.0);
		glVertex3f(0.6,0.350,0.0);
		glVertex3f(0.7,0.316,0.0);
		glVertex3f(0.8,0.296,0.0);
		glVertex3f(0.9,0.280,0.0);
		glVertex3f(1.0,0.261,0.0);
		glEnd();
	#endif

	#ifdef SAME_COLOR
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 0.0, 1.0);
		glScalef(2.0,2.0,2.0);
		glPointSize(2.0);
		glVertex3f(0.1,0.594,0.0);
		glVertex3f(0.2,0.502,0.0);
		glVertex3f(0.3,0.440,0.0);
		glVertex3f(0.4,0.396,0.0);
		glVertex3f(0.5,0.375,0.0);
		glVertex3f(0.6,0.350,0.0);
		glVertex3f(0.7,0.317,0.0);
		glVertex3f(0.8,0.305,0.0);
		glVertex3f(0.9,0.293,0.0);
		glVertex3f(1.0,0.278,0.0);
		glEnd();
	#endif

	glPopMatrix();
	glFlush();
}

void init (void)
{

    // select clearing color
    glClearColor (1.0, 1.0, 1.0, 0.0);

    /* initialize viewing values */
    //initialize model view transforms
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Orthographic projection
    //glOrtho(-1.0, 1.0, -1.0, 1.0, 0.5, 5.0);

}

// Window size and mode
int main(int argc, char** argv)
{

    // pass potential input arguments to glutInit
    glutInit(&argc, argv);

    // set display mode
    // GLUT_SINGLE = single buffer window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow ("My graph");

    // Call initialization routines
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;   /* ANSI C requires main to return int. */

}

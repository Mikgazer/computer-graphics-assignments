//Draw a cube with a square hole in each face.

#include <GL/glut.h>
#include <stdio.h>
#define NFACES 4
#define NVERTICES 24

#define DRAW_ARRAYS

GLfloat angle = 10;

GLfloat vertexArray[NFACES*NVERTICES*3]={

	/* FIRST FACE */
	/* 1 */
	0.5,1.0,1.0,
	0.5,-1.0,1.0,
	1.0,-1.0,1.0,
	
	1.0,-1.0,1.0,
	1.0,1.0,1.0,
	0.5,1.0,1.0,
	
	1.0,1.0,1.0,
	-1.0,1.0,1.0,
	-1.0,0.5,1.0,
	
	-1.0,0.5,1.0,
	1.0,0.5,1.0,
	1.0,1.0,1.0,
	
	-1.0,1.0,1.0,
	-1.0,-1.0,1.0,
	-0.5,-1.0,1.0,
	
	-0.5,-1.0,1.0,
	-0.5,1.0,1.0,
	-1.0,1.0,1.0,
	
	1.0,-0.5,1.0,
	-1.0,-0.5,1.0,
	-1.0,-1.0,1.0,
	
	-1.0,-1.0,1.0,
	1.0,-1.0,1.0,
	1.0,-0.5,1.0,

	/* SECOND FACE */
	/* 1 */
	1.0,1.0,-0.5,
	1.0,-1.0,-0.5,
	1.0,-1.0,-1.0,
	
	1.0,-1.0,-1.0,
	1.0,1.0,-1.0,
	1.0,1.0,-0.5,
	
	1.0,1.0,-1.0,
	1.0,1.0,1.0,
	1.0,0.5,1.0,
	
	1.0,0.5,1.0,
	1.0,0.5,-1.0,
	1.0,1.0,-1.0,
	
	1.0,1.0,1.0,
	1.0,-1.0,1.0,
	1.0,-1.0,0.5,
	
	1.0,-1.0,0.5,
	1.0,1.0,0.5,
	1.0,1.0,1.0,
	
	1.0,-1.0,1.0,
	1.0,-1.0,-1.0,
	1.0,-0.5,-1.0,
	/* 8
	1.0,-0.5,-1.0,
	1.0,-0.5,1.0,
	1.0,-1.0,1.0,

	/* THIRD FACE */
	/* 1 */
	-1.0,1.0,-0.5,
	-1.0,-1.0,-0.5,
	-1.0,-1.0,-1.0,
	
	-1.0,-1.0,-1.0,
	-1.0,1.0,-1.0,
	-1.0,1.0,-0.5,
	
	-1.0,1.0,-1.0,
	-1.0,1.0,1.0,
	-1.0,0.5,1.0,
	
	-1.0,0.5,1.0,
	-1.0,0.5,-1.0,
	-1.0,1.0,-1.0,
	
	-1.0,1.0,1.0,
	-1.0,-1.0,1.0,
	-1.0,-1.0,0.5,
	
	-1.0,-1.0,0.5,
	-1.0,1.0,0.5,
	-1.0,1.0,1.0,
	
	-1.0,-1.0,1.0,
	-1.0,-1.0,-1.0,
	-1.0,-0.5,-1.0,
	//8 */
	-1.0,-0.5,-1.0,
	-1.0,-0.5,1.0,
	-1.0,-1.0,1.0,

	/* FOURTH FACE */
	/* 1 */
	0.5,1.0,-1.0,
	0.5,-1.0,-1.0,
	1.0,-1.0,-1.0,
	
	1.0,-1.0,-1.0,
	1.0,1.0,-1.0,
	0.5,1.0,-1.0,
	
	1.0,1.0,-1.0,
	-1.0,1.0,-1.0,
	-1.0,0.5,-1.0,
	
	-1.0,0.5,-1.0,
	1.0,0.5,-1.0,
	1.0,1.0,-1.0,
	
	-1.0,1.0,-1.0,
	-1.0,-1.0,-1.0,
	-0.5,-1.0,-1.0,
	
	-0.5,-1.0,-1.0,
	-0.5,1.0,-1.0,
	-1.0,1.0,-1.0,
	
	1.0,-0.5,-1.0,
	-1.0,-0.5,-1.0,
	-1.0,-1.0,-1.0,
	/* 8 */
	-1.0,-1.0,-1.0,
	1.0,-1.0,-1.0,
	1.0,-0.5,-1.0,
};

GLfloat colorArray[NFACES*NVERTICES*3*4]={
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    //////////////
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    //////////////
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    //////////////
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,
    0.5, 0.3, 0.3,

};

/*
glDraw Arrays(GL enum mode, GLint first, GLsizei count);
mode = ...
first = Specifies the starting index in the enabled arrays.
count= Specifies the number of indices to be rendered.
*/

void display(void){

	/* GLshort i=0; */
	GLshort indFace, indVertex;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(angle, 0.0, 1.0, 0.0);
	glPushMatrix();
 
	/* glTranslatef(0.0,1.0,-1.5); */
	glScalef(0.4,0.4,0.4);
	glTranslatef(0.0,-0.4,0.0);
	glRotatef(30.0,1.0,0.0,0.0);

	for(indFace=0; indFace<NFACES;indFace++){
	glDrawArrays(GL_TRIANGLES,indFace*NVERTICES,24);
	};

	glPopMatrix();
	glPopMatrix();

	/* Flush graphics objects */
	glFlush();

}

void init(void){

	glClearColor(1.0,1.0,1.0,0.0);

	/* Enable two vertex arrays */
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	/* Specify number of coordinates per vertex, type, stride, and pointer */
	glVertexPointer(3, GL_FLOAT, 0, vertexArray);
	glColorPointer(3,GL_FLOAT,0,colorArray);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.2,-0.2,-0.3,0.1,0.1,5.0);

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);
	glDepthFunc(GL_LESS);

	/* glEnable(GL_CULL_FACE); */

}

void keyInput(unsigned char key, int x, int y)
{
    int index=0;
    switch(key) {
        case 27:
            // ESC
            exit(0);
            break;

        case '+':
            if(angle<360)
                angle+=0.5;
            glutPostRedisplay();
            break;

        case '-':
            if(angle>1)
                angle-=0.5;
            glutPostRedisplay();
            break;

        default:
            /* Do nothing */
            break;
    }
}

int main(int argc,char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Cube with a hole in each face - DrawArrays");
	printf("Press + and - to rotate the scene\n");

    	glutKeyboardFunc(keyInput);
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

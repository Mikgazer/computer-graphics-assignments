/* Draw a cube with a square hole in each face. */

#include <GL/glut.h>

void display(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();

	/* glTranslatef(0.0,1.0,-1.5); */
	glScalef(0.4,0.4,0.4);
	glTranslatef(0.0,-0.4,0.0);
	glRotatef(30.0,0.0,1.0,0.0);
	glRotatef(15.0,1.0,0.0,0.0);
	
	/* Triangoli */
	glBegin(GL_TRIANGLES);

	
	/* FIRST FACE */
	glColor3f(1.0,0.0,0.0); 
	/* 1 */
	glVertex3f(0.5,1.0,1.0);
	glVertex3f(0.5,-1.0,1.0);
	glVertex3f(1.0,-1.0,1.0);
	
	glVertex3f(1.0,-1.0,1.0);
	glVertex3f(1.0,1.0,1.0);
	glVertex3f(0.5,1.0,1.0);
	
	glVertex3f(1.0,1.0,1.0);
	glVertex3f(-1.0,1.0,1.0);
	glVertex3f(-1.0,0.5,1.0);
	
	glVertex3f(-1.0,0.5,1.0);
	glVertex3f(1.0,0.5,1.0);
	glVertex3f(1.0,1.0,1.0);
	
	glVertex3f(-1.0,1.0,1.0);
	glVertex3f(-1.0,-1.0,1.0);
	glVertex3f(-0.5,-1.0,1.0);
	
	glVertex3f(-0.5,-1.0,1.0);
	glVertex3f(-0.5,1.0,1.0);
	glVertex3f(-1.0,1.0,1.0);
	
	glVertex3f(1.0,-0.5,1.0);
	glVertex3f(-1.0,-0.5,1.0);
	glVertex3f(-1.0,-1.0,1.0);
	/* 8 */
	glVertex3f(-1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,1.0);
	glVertex3f(1.0,-0.5,1.0);
	
	/* SECOND FACE */
	/* 1 */
	glColor3f(0.0,0.3,0.8);
	glVertex3f(1.0,1.0,-0.5);
	glVertex3f(1.0,-1.0,-0.5);
	glVertex3f(1.0,-1.0,-1.0);
	
	glVertex3f(1.0,-1.0,-1.0);
	glVertex3f(1.0,1.0,-1.0);
	glVertex3f(1.0,1.0,-0.5);
	
	glVertex3f(1.0,1.0,-1.0);
	glVertex3f(1.0,1.0,1.0);
	glVertex3f(1.0,0.5,1.0);
	
	glVertex3f(1.0,0.5,1.0);
	glVertex3f(1.0,0.5,-1.0);
	glVertex3f(1.0,1.0,-1.0);
	
	glVertex3f(1.0,1.0,1.0);
	glVertex3f(1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,0.5);
	
	glVertex3f(1.0,-1.0,0.5);
	glVertex3f(1.0,1.0,0.5);
	glVertex3f(1.0,1.0,1.0);
	
	glVertex3f(1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,-1.0);
	glVertex3f(1.0,-0.5,-1.0);
	/* 8 */
	glVertex3f(1.0,-0.5,-1.0);
	glVertex3f(1.0,-0.5,1.0);
	glVertex3f(1.0,-1.0,1.0);
	
	/* THIRD FACE */
	glColor3f(0.5,0.5,0.5);
	/* 1 */
	glVertex3f(-1.0,1.0,-0.5);
	glVertex3f(-1.0,-1.0,-0.5);
	glVertex3f(-1.0,-1.0,-1.0);
	
	glVertex3f(-1.0,-1.0,-1.0);
	glVertex3f(-1.0,1.0,-1.0);
	glVertex3f(-1.0,1.0,-0.5);
	
	glVertex3f(-1.0,1.0,-1.0);
	glVertex3f(-1.0,1.0,1.0);
	glVertex3f(-1.0,0.5,1.0);
	
	glVertex3f(-1.0,0.5,1.0);
	glVertex3f(-1.0,0.5,-1.0);
	glVertex3f(-1.0,1.0,-1.0);
	
	glVertex3f(-1.0,1.0,1.0);
	glVertex3f(-1.0,-1.0,1.0);
	glVertex3f(-1.0,-1.0,0.5);
	
	glVertex3f(-1.0,-1.0,0.5);
	glVertex3f(-1.0,1.0,0.5);
	glVertex3f(-1.0,1.0,1.0);
	
	glVertex3f(-1.0,-1.0,1.0);
	glVertex3f(-1.0,-1.0,-1.0);
	glVertex3f(-1.0,-0.5,-1.0);
	/* 8 */
	glVertex3f(-1.0,-0.5,-1.0);
	glVertex3f(-1.0,-0.5,1.0);
	glVertex3f(-1.0,-1.0,1.0);
	
	/* FOURTH FACE */
	glColor3f(0.5,0.4,0.3); 
	/* 1 */
	glVertex3f(0.5,1.0,-1.0);
	glVertex3f(0.5,-1.0,-1.0);
	glVertex3f(1.0,-1.0,-1.0);
	
	glVertex3f(1.0,-1.0,-1.0);
	glVertex3f(1.0,1.0,-1.0);
	glVertex3f(0.5,1.0,-1.0);
	
	glVertex3f(1.0,1.0,-1.0);
	glVertex3f(-1.0,1.0,-1.0);
	glVertex3f(-1.0,0.5,-1.0);
	
	glVertex3f(-1.0,0.5,-1.0);
	glVertex3f(1.0,0.5,-1.0);
	glVertex3f(1.0,1.0,-1.0);
	
	glVertex3f(-1.0,1.0,-1.0);
	glVertex3f(-1.0,-1.0,-1.0);
	glVertex3f(-0.5,-1.0,-1.0);
	
	glVertex3f(-0.5,-1.0,-1.0);
	glVertex3f(-0.5,1.0,-1.0);
	glVertex3f(-1.0,1.0,-1.0);
	
	glVertex3f(1.0,-0.5,-1.0);
	glVertex3f(-1.0,-0.5,-1.0);
	glVertex3f(-1.0,-1.0,-1.0);
	/* 8 */
	glVertex3f(-1.0,-1.0,-1.0);
	glVertex3f(1.0,-1.0,-1.0);
	glVertex3f(1.0,-0.5,-1.0);
	

	glEnd();
	glPopMatrix();
	
	glFlush();

}

void init(void){

	glClearColor(1.0,1.0,1.0,0.0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	glFrustum(-0.2,-0.2,-0.3,0.1,0.1,5.0);
	
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);
	glDepthFunc(GL_LESS);
	
	/* glEnable(GL_CULL_FACE); */

}

int main(int argc,char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Cube with a hole in each face");
	
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
		
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define PI 3.14
#define nslices 100
#define nstacks 100

GLfloat angleSun=0.0;
GLfloat angleMercury=0.0;
GLfloat angleVenus=0.0;
GLfloat angleEarth=0.0;
GLfloat angleMoon=0.0;
GLfloat angleMars=0.0;
GLfloat angleJupiter=0.0;
GLfloat angleSaturn=0.0;
GLfloat angleUranus=0.0;
GLfloat angleNeptune=0.0;

GLfloat sx=0.2,sy=0.2,sz=0.2;
GLfloat black[]={0.0f,0.0f,0.0f,1.0f};
GLfloat white[]={1.0f,1.0f,1.0f,1.0f};
GLfloat blue[]={0.0f,0.0f,0.9f,1.0f};
GLfloat er[]={0.0f,5.0f,0.9f,1.0f};
GLfloat yellow[]={0.7f,0.2f,0.0f,1.0f};

GLfloat mercury_shininess[]={80};
GLfloat venus_shininess[]={70};
GLfloat earth_shininess[]={60};
GLfloat moon_shininess[]={50};
GLfloat mars_shininess[]={40};
GLfloat jupiter_shininess[]={30};
GLfloat saturn_shininess[]={25};
GLfloat uranus_shininess[]={20};
GLfloat neptune_shininess[]={15};

GLfloat Ambient[]={0.1,0.1,0.1,1.0};
GLfloat Diffuse[]={1.0,1.0,1.0,1.0};
GLfloat Specular[]={.50,.50,.50,.10};

GLfloat Position[]={0,0,0,0.1};
//distance from the center * scale factor (sx,sy,sz)
GLfloat scale_vector[8]={0.3 , 0.40, 0.50, 0.60, 0.74, 0.88, 1.00, 1.12};
GLint mmseconds = 25;

double ang=2*PI/360;

// Routine to draw a stroke character string.
void writeStrokeString(void *font, char *string)
{
   char *c;
   for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
}

void init()
{
	glClearColor(0.01,0.01,0.01,0.0); //backgroundcolor is black
	glPointSize(1.0);
	glLineWidth(2.0);
}

void draw_orbit()
{

	glColor3f(1.0,1.0,1.0);
	int i=0;
	for(i=0;i<8;i++)
    {
		glPushMatrix();
            glRotatef(63,1.0,0.0,0.0);
            //ingrandisco la dimensione dell'orbita
            glScalef(scale_vector[i],scale_vector[i],scale_vector[i]);
            //iniziuo a disegnare, punti
            glBegin(GL_POINTS);
            double ang1=0.0;
            int z = 0;
            for(z=0;z<1440;z++)
            {
                //parametrizzazione di una circonferenza
                glVertex2d(cos(ang1),sin(ang1));
                ang1+=ang;
            }
            glEnd();
		glPopMatrix();
	}
}

void Lighting()
{

	glLightfv(GL_LIGHT0,GL_AMBIENT,Ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,Diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //GL_LIGHTi, i is 0

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //glClear sets the bitplane area of the window to values previously selected by glClearColor
	draw_orbit();

	glLoadIdentity();

	glPushMatrix();
        glEnable(GL_DEPTH_TEST); //Enable depth test
        glDepthFunc(GL_LESS);
        glEnable(GL_COLOR_MATERIAL); //If enabled, have one or more material parameters track the current color.

        //SUN
        glPushMatrix();
            glRotatef(angleSun,0.0,0.0,-0.5);
            glColor3f(0.7,0.5,0.0);
            glTranslatef(0.0,0.0,0.1);
            glScalef(sx,sy,sz);
            glLightfv(GL_LIGHT0,GL_POSITION,Position);
            glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,yellow);
            //EMISSION = The params parameter contains four floating-point values that specify the RGBA emitted light intensity of the material.
            glutSolidSphere(1.05,nslices,nstacks);
            glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
        glPopMatrix();

        //MERCURY
        glScalef(0.2,0.2,0.2);
        glPushMatrix();
            glRotatef(angleMercury,0.0,1.0,-0.5);
            glTranslatef(1.5,0.0,0.0);
            glColor3f(1.0,0.9,0.0);
            glScalef(0.08,0.08,0.08);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mercury_shininess);
            glutSolidSphere(1,nslices,nstacks);
            glTranslatef(1.0,0.0,-1.0);
            glScalef(0.01,0.01,0.01);
            glColor3f(1.0,1.0,1.0);
            writeStrokeString(GLUT_STROKE_ROMAN, "Mercury");
        glPopMatrix();

        //VENUS
        glPushMatrix();
            glRotatef(angleVenus,0.0,1.0,-0.5);
            glTranslatef(2.0,0.0,0.0);
            glColor3f(0.9,0.1,0.0);
            glScalef(0.1,0.1,0.1);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, venus_shininess);
            glutSolidSphere(1,nslices,nstacks);
            glTranslatef(1.0,0.0,-1.0);
            glScalef(0.01,0.01,0.01);
            glColor3f(1.0,1.0,1.0);
            writeStrokeString(GLUT_STROKE_ROMAN, "Venus");
        glPopMatrix();

        //EARTH
        glPushMatrix();
            glRotatef(angleEarth,0.0,1.0,-0.5);
            glTranslatef(2.5,0.0,0.0);
            glColor3f(0.0,0.1,0.7);
            glScalef(0.23,0.23,0.23);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, earth_shininess);
            glutSolidSphere(1,nslices,nstacks);
            glPushMatrix();
                //MOON
                glRotatef(angleMoon,1.0,-0.5,0.0);
                glTranslatef(0.0,0,1.1);
                glColor3f(1.0,1.0,1.0);
                glScalef(0.5,0.5,0.5);
                glTranslatef(1.0,0.0,0.0);
                glutSolidSphere(0.5,nslices,nstacks);
            glPopMatrix();
            glTranslatef(0.2,0.0,-1.0);
            glScalef(0.005,0.005,0.005);
            glColor3f(1.0,1.0,1.0);
            writeStrokeString(GLUT_STROKE_ROMAN, "Earth");
        glPopMatrix();

        //MARS
        glPushMatrix();
            glRotatef(angleMars,0.0,1.0,-0.5);
            glTranslatef(-3.0,0.0,0.0);
            glColor3f(0.35,0.05,0.01);
            glScalef(0.17,0.17,0.17);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mars_shininess);
            glutSolidSphere(1,nslices,nstacks);
            glTranslatef(0.2,0.0,-1.0);
            glScalef(0.007,0.007,0.007);
            glColor3f(1.0,1.0,1.0);
            writeStrokeString(GLUT_STROKE_ROMAN, "Mars");
        glPopMatrix();

        //JUPITER
        glPushMatrix();
            glRotatef(angleJupiter,0.0,1.0,-0.5);
            glTranslatef(-3.7,0.0,0.0);
            glColor3f(0.4,0.2,0.0);
            glScalef(0.5,0.5,0.5);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, jupiter_shininess);
            glutSolidSphere(1,nslices,nstacks);
            glTranslatef(0.2,0.0,-1.0);
            glScalef(0.003,0.003,0.003);
            glColor3f(1.0,1.0,1.0);
            writeStrokeString(GLUT_STROKE_ROMAN, "Jupiter");
        glPopMatrix();

        //SATURN
        glPushMatrix();
            glRotatef(angleSaturn,0.0,1.0,-0.5);
            glTranslatef(-4.4,0.0,0.0);
            glColor3f(0.5,0.3,0.3);
            glScalef(0.4,0.4,0.4);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, saturn_shininess);
            glutSolidSphere(1,nslices,nstacks);
            glTranslatef(0.2,0.0,-1.0);
            glScalef(0.003,0.003,0.003);
            glColor3f(1.0,1.0,1.0);
            writeStrokeString(GLUT_STROKE_ROMAN, "Saturn");
        glPopMatrix();

        //SATURN
        glPushMatrix();
            glRotatef(angleUranus,0.0,1.0,-0.5);
            glTranslatef(5.0,0.0,0.0);
            glColor3f(0.0,0.5,0.9);
            glScalef(0.23,0.23,0.23);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, uranus_shininess);
            glutSolidSphere(1,nslices,nstacks);
            glTranslatef(0.2,0.0,-1.0);
            glScalef(0.006,0.006,0.006);
            glColor3f(1.0,1.0,1.0);
            writeStrokeString(GLUT_STROKE_ROMAN, "Uranus");
        glPopMatrix();

        //NEPTUNE
        glPushMatrix();
            glRotatef(angleNeptune,0.0,1.0,-0.5);
            glTranslatef(-5.6,0.0,0.0);
            glColor3f(0.0,0.0,0.9);
            glScalef(0.2,0.2,0.2);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, neptune_shininess);
            glutSolidSphere(1,nslices,nstacks);
            glTranslatef(0.2,0.0,-1.0);
            glScalef(0.005,0.005,0.005);
            glColor3f(1.0,1.0,1.0);
            writeStrokeString(GLUT_STROKE_ROMAN, "Neptune");
        glPopMatrix();

	glPopMatrix();
    glutSwapBuffers();
}

void update(int value){

    angleSun+=0.1;
    if(angleSun>360)
        angleSun=-360;

	angleEarth+=0.7;
	if(angleEarth>360)
        angleEarth-=720;

    angleMoon+=2;
    if(angleMoon>360)
        angleMoon-=360;

	angleMercury+=2;
	if(angleMercury>360)
		angleMercury-=360;

	angleVenus+=0.9;
	if(angleVenus>360)
		angleVenus-=360;

	angleMars+=0.5;
	if(angleMars>360)
		angleMars-=360;

	angleJupiter+=0.3;
	if(angleJupiter>360)
		angleJupiter-=360;

	angleSaturn+=0.2;
	if(angleSaturn>360)
		angleSaturn-=360;

	angleUranus+=0.06;
	if(angleUranus>360)
		angleUranus-=360;

	angleNeptune+=0.03;
	if(angleNeptune>360)
		angleNeptune-=360;

	glutPostRedisplay();
	glutTimerFunc(mmseconds,update,0);
}

void keyInput(unsigned char key, int x, int y)
{

    switch(key) {
        case 27:
            // ESC
            exit(0);
            break;
        case '+':
            if(mmseconds < 30)
                mmseconds+=1;
            break;
        case '-':
            if(mmseconds > 1)
                mmseconds-=1;
            break;
        default:
            //do nothing
            break;
    }

}


int main(int argc, char **argv)
{

	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Solar System");
    printf("Press + and - to decrease/increase the speed at which the planet revolve around the sun.\n");
    printf("Press ESC to quit.\n");

    glutKeyboardFunc(keyInput);
    Lighting();
    init();
    glutDisplayFunc(display);
    glutTimerFunc(mmseconds,update,0);
    glutMainLoop();

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define nslices 100
#define nstacks 100
#define PI 3.1415926535

/* Initial angles, starting point in the orbit. Changing these factors doesn't affect the program */
GLfloat angle_s=0.0;
GLfloat angleSun=0.0;
GLfloat angleMercury=0.0;
GLfloat angleVenus=0.0;
GLfloat angleEarth=0.0;
GLfloat angleMoon=0.0;
GLfloat angleMars=0.0;
GLfloat angleJupiter=45.0;
GLfloat angleSaturn=0.0;
GLfloat angleUranus=60.0;
GLfloat angleNeptune=60.0;

GLint status = 1;
GLint camera = 0;

/* Light colours */
GLfloat black[]={0.0f,0.0f,0.0f,1.0f};
GLfloat white[]={1.0f,1.0f,1.0f,1.0f};
GLfloat blue[]={0.0f,0.0f,0.9f,1.0f};
GLfloat yellow[]={0.7f,0.2f,0.0f,1.0f};

/* Material light properties */
GLfloat mercury_shininess[]={80};
GLfloat venus_shininess[]={70};
GLfloat earth_shininess[]={60};
GLfloat moon_shininess[]={50};
GLfloat mars_shininess[]={40};
GLfloat jupiter_shininess[]={30};
GLfloat saturn_shininess[]={25};
GLfloat uranus_shininess[]={20};
GLfloat neptune_shininess[]={15};
/* GLfloat pluto_shininess[]={2}; */

/* Ambient, diffuse, and specular light properties */
GLfloat Ambient[]={0.1,0.1,0.1,1.0};
GLfloat Diffuse[]={1.0,1.0,1.0,1.0};
GLfloat Specular[]={.50,.50,.50,.10};

GLfloat Position[]={0,0,0,0.1};
/* Distance from the center * 0.2 */
GLfloat scale_vector[]={0.3 , 0.40, 0.50, 0.60, 0.74, 0.88, 1.00, 1.12,1.3};
/* Refresh time */
GLint mmseconds = 25; 
/* Orbit drawing factor */
GLdouble sum_angle=PI/360;

/* Routine to draw a stroke character string. */
void writeStrokeString(void *font, char *string)
{
   char *c;
   for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
}

void draw_orbit()
{

	glColor3f(1.0,1.0,1.0);
	int index=0;
	for(index=0;index<8;index++)
        {
	    glPushMatrix();
	    /* Rotation of 63 degrees around the vector [1, 0 ,0] */
            glRotatef(63,1.0,0.0,0.0);
            /* Make the orbit larger */
            glScalef(scale_vector[index],scale_vector[index],scale_vector[index]);
            /* Begin drawing points */
            glBegin(GL_POINTS); /* Treats each vertex as a single point. Vertex n defines point n. N points are drawn. */
            GLdouble angle=0.0;
            GLint z = 0;
            for(z=0;z<1080;z++)
            {
                /* Parametrizzazione di una circonferenza */
                glVertex2d(cos(angle),sin(angle));
                /* Angle increase */
                angle+=sum_angle; 
            }
            glEnd();
	    glPopMatrix();

	}
}

void initiate_lighting()
{

    glLightfv(GL_LIGHT0,GL_AMBIENT,Ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,Diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
    /* glLightModelf(GL_LIGHT_MODEL_AMBIENT,globalAmb); */
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);

    glShadeModel((GL_SMOOTH));
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); /* GL_LIGHTi, i is 0 */

}

void init()
{
        initiate_lighting();
	glClearColor(0.01,0.01,0.01,0.0); /* backgroundcolor is black */

}

void draw_planets(void){

    if(1==status)
        draw_orbit();

    glEnable(GL_DEPTH_TEST); /* Enable depth test */
    glDepthFunc(GL_LESS); /* Passes if the incoming depth value is less than the stored depth value. */
    glEnable(GL_COLOR_MATERIAL); /* If enabled, have one or more material parameters track the current color. */

    //SUN */
    glPushMatrix();
        glRotatef(angleSun,0.0,0.0,0.0);
        glColor3f(0.7,0.5,0.0);
        glTranslatef(0.0,0.0,0.1);
        glScalef(0.2,0.2,0.2);
        glLightfv(GL_LIGHT0,GL_POSITION,Position);
        glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,yellow);
        /* EMISSION = The params parameter contains four floating-point values that specify the RGBA emitted light intensity of the material. */
        glutSolidSphere(1.05,nslices,nstacks);
        glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

    glPopMatrix();

    /* MERCURY */
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

    /* VENUS */
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

    /* EARTH */
    glPushMatrix();
        glRotatef(angleEarth,0.0,1.0,-0.5);
        glTranslatef(2.5,0.0,0.0);
        glColor3f(0.0,0.1,0.7);
        glScalef(0.23,0.23,0.23);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, earth_shininess);
        glutSolidSphere(1,nslices,nstacks);
        glPushMatrix();
            /* MOON */
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
        writeStrokeString(GLUT_STROKE_ROMAN, "Earth and Moon");
    glPopMatrix();

    /* MARS */
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

    /* JUPITER */
    glPushMatrix();
        glRotatef(angleJupiter,0.0,1.0,-0.5);
        glTranslatef(-3.7,0.0,0.0);
        glColor3f(0.46,0.33,0.25);
        glScalef(0.5,0.5,0.5);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, jupiter_shininess);
        glutSolidSphere(1,nslices,nstacks);
        glTranslatef(-0.2,0.0,-1.0);
        glScalef(0.003,0.003,0.003);
        glColor3f(1.0,1.0,1.0);
        writeStrokeString(GLUT_STROKE_ROMAN, "Jupiter");
    glPopMatrix();

    /* SATURN */
    glPushMatrix();
        glRotatef(angleSaturn,0.0,1.0,-0.5);
        glTranslatef(-4.4,0.0,0.0);
        glColor3f(0.5,0.3,0.3);
        glScalef(0.4,0.4,0.4);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, saturn_shininess);
        glutSolidSphere(1,nslices,nstacks);
        glTranslatef(-0.2,0.0,-1.0);
        glScalef(0.003,0.003,0.003);
        glColor3f(1.0,1.0,1.0);
        writeStrokeString(GLUT_STROKE_ROMAN, "Saturn");
    glPopMatrix();

    /* SATURN */
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

    /* NEPTUNE */
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

    /* Sonda */
    glPushMatrix();
        glRotatef(angle_s, 0.0, 1.0, -0.3);
        glTranslatef(4.8, 0.0, 0.0);
        glColor3f(1.0, 1.0, 1.0);
        glScalef(0.03, 0.03, 0.03);
        glutSolidDodecahedron();
        glTranslatef(0.0,0.0,-3.0);
        glScalef(0.02,0.02,0.02);
        writeStrokeString(GLUT_STROKE_ROMAN, "Sonda");
    glPopMatrix();

}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); /* glClear sets the bitplane area of the window to values previously selected by glClearColor */
	glLoadIdentity();
        draw_planets();
        glutSwapBuffers();
}


void display_update(int value){

        angle_s+=0.5;

        angleSun+=0.3;
        if(angleSun>3)
            angleSun-=3;

	angleEarth+=0.7;
	angleMercury+=2;
        angleMoon+=2;
	angleVenus+=0.9;
	angleMars+=0.5;
	angleJupiter+=0.3;
	angleSaturn+=0.15;
	angleUranus+=0.06;
	angleNeptune+=0.03;

	glutPostRedisplay();
	glutTimerFunc(mmseconds,display_update,0);
}


void keyInput(unsigned char key, int x, int y)
{
    switch(key) {
        case 27:
            /*  ESC */
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
        case 'o':
            status = 1;
            break;
        case 'O':
            status = 0;
            break;
        case 'c':
            camera = 1;
            break;
        default:
            /* do nothing */
            break;
    }

}

int main(int argc, char **argv)
{

    GLint window_width = 1000;
    GLint window_height = 1000;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB  | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(window_width,window_height);
    glutCreateWindow("Solar System");
    printf("Press + and - to decrease/increase the speed at which the planet revolve around the sun.\n");
    printf("Press ESC to quit.\n");
    printf("Press 'o' to see the orbits, press 'O' to make them disappear.\n");

    glutKeyboardFunc(keyInput);
    init();
    glutDisplayFunc(display);
    glutTimerFunc(mmseconds,display_update,0);
    glutMainLoop();

    return 0;
}

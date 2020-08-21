#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define nslices 100
#define nstacks 100
#define PI 3.1415926535

//Uncomment only ONE of the following
//#define DEBUG
#define NOT_DEBUG

//Initial angles, starting point in the orbit. Changing these factors doesn't affect the program
GLfloat angle_sat=0.0;
GLfloat angle_sun=0.0;
GLfloat angle_mercury=0.0;
GLfloat angle_venus=0.0;
GLfloat angle_earth=0.0;
GLfloat angle_moon=0.0;
GLfloat angle_mars=0.0;
GLfloat angle_jupiter=45.0;
GLfloat angle_saturn=0.0;
GLfloat angle_uranus=60.0;
GLfloat angle_neptune=60.0;

//z factor of glrotatef
GLfloat angle_z=-0.5;
GLint status = 1;
//Only for debugging purposes
#ifdef DEBUG
GLfloat angleOrbit=63.0;
#endif

//Light colours
GLfloat black[]={0.0f,0.0f,0.0f,1.0f};
GLfloat white[]={1.0f,1.0f,1.0f,1.0f};
GLfloat blue[]={0.0f,0.0f,0.9f,1.0f};
GLfloat yellow[]={0.7f,0.2f,0.0f,1.0f};


//Material light properties
GLfloat mercury_shininess[]={80};
GLfloat venus_shininess[]={70};
GLfloat earth_shininess[]={60};
GLfloat moon_shininess[]={50};
GLfloat mars_shininess[]={40};
GLfloat jupiter_shininess[]={30};
GLfloat saturn_shininess[]={25};
GLfloat uranus_shininess[]={20};
GLfloat neptune_shininess[]={15};
//GLfloat pluto_shininess[]={2};

//Ambient, diffuse, and specular light properties
GLfloat Ambient[]={0.1,0.1,0.1,1.0};
GLfloat Diffuse[]={1.0,1.0,1.0,1.0};
GLfloat Specular[]={.50,.50,.50,1.0};
GLfloat globalAmb[]={0.1, 0.1, 0.1, 1.0};

GLfloat Position[]={0,0,0,0.1};
//Distance from the center * 0.2
GLfloat scale_vector[]={0.3 , 0.40, 0.50, 0.60, 0.74, 0.88, 1.00, 1.12,1.3};
//Refresh time
GLint mmseconds = 25;
//Orbit drawing factor
GLdouble sum_angle=PI/360;

// Routine to draw a stroke character string.
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
        #ifdef DEBUG
            //ONLY for debugging purposes
            //Rotation of alpha degrees around the vector [1, 0 ,0]
            glRotatef(angleOrbit, 1.0, 0.0, 0.0);
        #endif // DEBUG

        #ifdef NOT_DEBUG
            glRotatef(63.0, 1.0, 0.0, 0.0);
        #endif // NOT_DEBUG

        //Make the orbit larger
        //Scale or translate? if I translate the center from which I draw the orbits will move too.
        glScalef(scale_vector[index],scale_vector[index],scale_vector[index]);
        //Begin drawing points
        glBegin(GL_POINTS); //Treats each vertex as a single point. Vertex n defines point n. N points are drawn.
        GLdouble angle=0.0;
        GLint z = 0;
        for(z=0;z<1080;z++)
        {
            //Circumference parametrization
            glVertex2d(cos(angle),sin(angle));
            //Angle increase
            angle+=sum_angle;
        }
        glEnd();
		glPopMatrix();
	}
}

void initiate_lighting()
{
    //Set light properties
	glLightfv(GL_LIGHT0,GL_AMBIENT,Ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,Diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT,globalAmb);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
    glShadeModel((GL_SMOOTH));
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //GL_LIGHTi, i is 0

}

void init()
{

	glClearColor(0.01,0.01,0.01,0.0); //backgroundcolor is black-ish
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	initiate_lighting();
    glEnable(GL_DEPTH_TEST); //Enable depth test
    glDepthFunc(GL_LESS);
    glEnable(GL_COLOR_MATERIAL);

}

void draw_planets(void){

    int i=0;
    double angle = 0;
    double second_angle = 0;
    if(1==status)
        draw_orbit();

    //SUN
    glPushMatrix();
    glRotatef(angle_sun,0.0,0.0,0.0);
    glColor3f(0.7,0.5,0.0);
    glTranslatef(0.0,0.0,0.0);
    glScalef(0.2,0.2,0.2);
    glLightfv(GL_LIGHT0,GL_POSITION,Position);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,yellow);
    //EMISSION = The params parameter contains four floating-point values that specify the RGBA emitted light intensity of the material.
    glutSolidSphere(1.05,nslices,nstacks);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
    glPopMatrix();

    //MERCURY
    glScalef(0.2,0.2,0.2);
    glPushMatrix();
    glRotatef(angle_mercury,0.0,1.0,angle_z);
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
    glRotatef(angle_venus,0.0,1.0,angle_z);
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
    glRotatef(angle_earth,0.0,1.0,angle_z);
    glTranslatef(2.5,0.0,0.0);
    glColor3f(0.0,0.1,0.7);
    glScalef(0.23,0.23,0.23);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, earth_shininess);
    glutSolidSphere(1,nslices,nstacks);
    glPushMatrix();
    //MOON
    glRotatef(angle_moon,1.0,1.0,angle_z);
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

    //MARS
    glPushMatrix();
    glRotatef(angle_mars,0.0,1.0,angle_z);
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
    glRotatef(angle_jupiter,0.0,1.0,angle_z);
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

    //SATURN
    glPushMatrix();
    glRotatef(angle_saturn,0.0,1.0,angle_z);
    glTranslatef(-4.4,0.0,0.0);
    glColor3f(0.5,0.3,0.3);
    glScalef(0.4,0.4,0.4);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, saturn_shininess);
    glutSolidSphere(1,nslices,nstacks);
    //First Saturn ring
    glPushMatrix();
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glPointSize(1.0);
    glColor3f(0.7, 0.7, 0.7);
    glScalef(1.2, 1.2, 1.2);
    glBegin(GL_POINTS);
    for(i=0;i <720; i++){
        glVertex2d(cos(angle),sin(angle));
        angle+=sum_angle;
    }
    glEnd();
    glPopMatrix();
    //Second saturn ring
    glPushMatrix();
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glPointSize(1.0);
    glColor3f(0.7, 0.7, 0.7);
    glScalef(1.4, 1.4, 1.4);
    glBegin(GL_POINTS);
        for(i=0; i<720; i++){
        glVertex2d(cos(second_angle),sin(second_angle));
        second_angle+=sum_angle;
    }
    glEnd();
    glPopMatrix();
    //glPointSize(2.0);
    glTranslatef(-0.2,0.0,-1.0);
    glScalef(0.003,0.003,0.003);
    glColor3f(0.4,0.7,0.5);
    writeStrokeString(GLUT_STROKE_ROMAN, "Saturn");
    glPopMatrix();

    //URANUS
    glPushMatrix();
    glRotatef(angle_uranus,0.0,1.0,angle_z);
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
    glRotatef(angle_neptune,0.0,1.0,angle_z);
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

    //Sonda
    glPushMatrix();
    glRotatef(angle_sat, 0.0, 1.0, angle_z);
    glTranslatef(4.8, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glScalef(0.03, 0.03, 0.03);
    glutSolidDodecahedron();
    glTranslatef(0.0,0.0,-3.0);
    glScalef(0.03,0.03,0.03);
    writeStrokeString(GLUT_STROKE_ROMAN, "Satellite");
    glPopMatrix();

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //glClear sets the bitplane area of the window to values previously selected by glClearColor

	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

    draw_planets();
    glutSwapBuffers();
}

void display_update(int value){

    angle_sat+=0.5;
    angle_sun+=0.2;
    if(angle_sun>3) {angle_sun-=3;}
	angle_earth+=0.7;
	angle_mercury+=2;
    angle_moon+=2;
	angle_venus+=0.9;
	angle_mars+=0.5;
	angle_jupiter+=0.3;
	angle_saturn+=0.15;
	angle_uranus+=0.06;
	angle_neptune+=0.03;

	glutPostRedisplay();
	glutTimerFunc(mmseconds,display_update,0);
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
        case 'o':
            status = 1;
            break;
        case 'O':
            status = 0;
            break;

        #ifdef DEBUG
        case 'a':
            angleOrbit-=1;
            break;
        case 'A':
            angleOrbit+=1;
            break;
        #endif

        default:
            //do nothing
            break;
    }

}

int main(int argc, char **argv)
{

    GLint window_width = 1000;
    GLint window_height = 1000;
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB  | GLUT_DEPTH);
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


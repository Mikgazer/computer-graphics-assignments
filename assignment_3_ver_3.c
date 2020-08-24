//Draw a cube with a square hole in each face.


#include <stdio.h>
#include <glad/glad.h>
#include <GL/freeglut.h>
#define NFACES 4
#define NVERTICES 24

#define DRAW_ARRAYS

unsigned int buffers[2];

GLfloat vertexArray[NFACES*NVERTICES*3]={

	//FIRST FACE
	//1
	0.5,1.0,1.0,
	0.5,-1.0,1.0,
	1.0,-1.0,1.0,
	//2
	1.0,-1.0,1.0,
	1.0,1.0,1.0,
	0.5,1.0,1.0,
	//3
	1.0,1.0,1.0,
	-1.0,1.0,1.0,
	-1.0,0.5,1.0,
	//4
	-1.0,0.5,1.0,
	1.0,0.5,1.0,
	1.0,1.0,1.0,
	//5
	-1.0,1.0,1.0,
	-1.0,-1.0,1.0,
	-0.5,-1.0,1.0,
	//6
	-0.5,-1.0,1.0,
	-0.5,1.0,1.0,
	-1.0,1.0,1.0,
	//7
	1.0,-0.5,1.0,
	-1.0,-0.5,1.0,
	-1.0,-1.0,1.0,
	//8
	-1.0,-1.0,1.0,
	1.0,-1.0,1.0,
	1.0,-0.5,1.0,

	//SECOND FACE
	//1
	1.0,1.0,-0.5,
	1.0,-1.0,-0.5,
	1.0,-1.0,-1.0,
	//2
	1.0,-1.0,-1.0,
	1.0,1.0,-1.0,
	1.0,1.0,-0.5,
	//3
	1.0,1.0,-1.0,
	1.0,1.0,1.0,
	1.0,0.5,1.0,
	//4
	1.0,0.5,1.0,
	1.0,0.5,-1.0,
	1.0,1.0,-1.0,
	//5
	1.0,1.0,1.0,
	1.0,-1.0,1.0,
	1.0,-1.0,0.5,
	//6
	1.0,-1.0,0.5,
	1.0,1.0,0.5,
	1.0,1.0,1.0,
	//7
	1.0,-1.0,1.0,
	1.0,-1.0,-1.0,
	1.0,-0.5,-1.0,
	//8
	1.0,-0.5,-1.0,
	1.0,-0.5,1.0,
	1.0,-1.0,1.0,

	//THIRD FACE
	//1
	-1.0,1.0,-0.5,
	-1.0,-1.0,-0.5,
	-1.0,-1.0,-1.0,
	//2
	-1.0,-1.0,-1.0,
	-1.0,1.0,-1.0,
	-1.0,1.0,-0.5,
	//3
	-1.0,1.0,-1.0,
	-1.0,1.0,1.0,
	-1.0,0.5,1.0,
	//4
	-1.0,0.5,1.0,
	-1.0,0.5,-1.0,
	-1.0,1.0,-1.0,
	//5
	-1.0,1.0,1.0,
	-1.0,-1.0,1.0,
	-1.0,-1.0,0.5,
	//6
	-1.0,-1.0,0.5,
	-1.0,1.0,0.5,
	-1.0,1.0,1.0,
	//7
	-1.0,-1.0,1.0,
	-1.0,-1.0,-1.0,
	-1.0,-0.5,-1.0,
	//8
	-1.0,-0.5,-1.0,
	-1.0,-0.5,1.0,
	-1.0,-1.0,1.0,

	//FOURTH FACE
	//1
	0.5,1.0,-1.0,
	0.5,-1.0,-1.0,
	1.0,-1.0,-1.0,
	//2
	1.0,-1.0,-1.0,
	1.0,1.0,-1.0,
	0.5,1.0,-1.0,
	//3
	1.0,1.0,-1.0,
	-1.0,1.0,-1.0,
	-1.0,0.5,-1.0,
	//4
	-1.0,0.5,-1.0,
	1.0,0.5,-1.0,
	1.0,1.0,-1.0,
	//5
	-1.0,1.0,-1.0,
	-1.0,-1.0,-1.0,
	-0.5,-1.0,-1.0,
	//6
	-0.5,-1.0,-1.0,
	-0.5,1.0,-1.0,
	-1.0,1.0,-1.0,
	//7
	1.0,-0.5,-1.0,
	-1.0,-0.5,-1.0,
	-1.0,-1.0,-1.0,
	//8
	-1.0,-1.0,-1.0,
	1.0,-1.0,-1.0,
	1.0,-0.5,-1.0,
};

GLfloat colorArray[NFACES*NVERTICES*3]={
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
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    //////////////
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 0.0, 1.0,


};

/*
glDraw Arrays(GL enum mode, GLint first, GLsizei count);
mode = ...
first = Specifies the starting index in the enabled arrays.
count= Specifies the number of indices to be rendered.
*/

//vertex that contains indices
GLuint vertexIndices[NFACES*NVERTICES*3];

void display(void){

	GLint indFace;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
        //glTranslatef(0.0,1.0,-1.5);
        glScalef(0.4,0.4,0.4);
        glTranslatef(0.0,-0.4,-0.4);
        glRotatef(30.0,0.0,1.0,0.0);
        glRotatef(15.0,1.0,0.0,0.0);

        for(indFace=0; indFace<NFACES;indFace++){
            glDrawElements(GL_TRIANGLES,24,GL_UNSIGNED_INT,indFace*NVERTICES * sizeof(GLuint));
        };
	glPopMatrix();

	//Flush graphics objects
	glFlush();

}

void init(void){

	int current_index;

	glClearColor(1.0,1.0,1.0,0.0);

	//Enable two vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//Generate Buffer Ids
	//glGenBuffers returns n buffer object names in buffers
	glGenBuffers(2,buffers);
	//bind vertex buffer and reserve space
	//glBindBuffer binds a buffer object to the specified buffer binding point
	//GL_ARRAY_BUFFER = Vertex attributes
	//glBufferData and glNamedBufferData create a new data store for a buffer object
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexArray)+sizeof(colorArray),NULL,GL_STATIC_DRAW);

	//Copy vertex SubData into first half of vertex buffer
	//glBufferSubData and glNamedBufferSubData redefine some or all of the data store for the specified buffer object
	glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(vertexArray),vertexArray);
	glBufferSubData(GL_ARRAY_BUFFER,sizeof(vertexArray),sizeof(colorArray),colorArray);
	//sizeof(vertexArray) used here as an offset

	//buffers[1] is for indices
	//bind and fill indices buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,buffers[1]);
	//initialize vertex indices
	for(current_index=0; current_index < NFACES*NVERTICES*3; current_index++)
        vertexIndices[current_index] = current_index;
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertexIndices),vertexIndices,GL_STATIC_DRAW);

	//Specify number of coordinates per vertex, type, stride, and pointer
	glVertexPointer(3, GL_FLOAT, 0, vertexArray);
	glColorPointer(3, GL_FLOAT, 0, colorArray);

	glMatrixMode(GL_PROJECTION);
	glFrustum(-0.2,-0.2,-0.3,0.1,0.1,5.0);

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	// initialize model view transforms
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);
	glDepthFunc(GL_LESS);

	//glEnable(GL_CULL_FACE);

}

int main(int argc,char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Cube with a hole in each face - DrawArrays with vbo");

	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

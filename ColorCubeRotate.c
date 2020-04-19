#include<stdlib.h>
#include<GL/glut.h>

GLfloat vertices[][3] = {{-1.0,-1.0,-1.0}, {1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat normals[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};

void polygon(int a,int b ,int c, int d)
{
    //draw a polygon of the listed vertices
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glNormal3fv(normals[a]);
    glVertex3fv((vertices[a]));
    //vertex b
    glColor3fv(colors[b]);
    glNormal3fv(normals[b]);
    glVertex3fv((vertices[b]));
    //vertex c
    glColor3fv(colors[c]);
    glNormal3fv(normals[c]);
    glVertex3fv((vertices[c]));
    //vertex d
    glColor3fv(colors[d]);
    glNormal3fv(normals[d]);
    glVertex3fv((vertices[d]));
    glEnd();
}

void colorcube(void)
{
    //map the vertices to faces
    polygon(0,3,2,1); //extreme back face
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);
}
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;

void display(void)
{
    //display the call back, clear from the frame buffer and z buffer, rotate cube and swap buffers
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0],1.0,0.0,0.0);
    glRotatef(theta[1],0.0,1.0,0.0);
    glRotatef(theta[2],0.0,0.0,1.0);
    colorcube();
    glFlush();
    glutSwapBuffers();
}

void spinCube()
{
    //idle callback , spin cube 2 degress about the selected axis
    theta[axis]+=1.0;
    if(theta[axis] >360.0) theta[axis]-=360.0;
    glutPostRedisplay();
}

void mouse(int btn, int state,int x,int y)
{
    //mouse callback selects an axis about which to rotate
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
    if(btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)axis = 1;
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}

void myRedisplay(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat) w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
        glOrtho(-2.0*(GLfloat)w/(GLfloat)h, 2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    //need both double buffereing & z buffer
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("Rotation of a color cube");
    glutReshapeFunc(myRedisplay);
    glutDisplayFunc(display);
    glutIdleFunc(spinCube);
    glutMouseFunc(mouse);
    glEnable(GL_DEPTH_TEST|GL_NORMALIZE);
    glutMainLoop();
    return 0;
}
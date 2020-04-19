#include<GL/glut.h>
void myInit(void)
{
    glMatrixMode(GL_PROJECTION);
    glColor3f(1.0,1.0,0.0);
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}
void drawPoly(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(0.25,0.25,0.0);
    glVertex3f(0.75,0.25,0.0);
    glVertex3f(0.75,0.75,0.0);
    glVertex3f(0.25,0.75,0.0);
    glEnd();
    glFlush();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glClear(GL_COLOR_BUFFER_BIT);
    glutInitWindowPosition(400,300);
    glutInitWindowSize(400,400);
    glutCreateWindow("Sample");
    myInit();
    glutDisplayFunc(drawPoly);
    glColor3f(1.0,1.0,1.0);
    glutMainLoop();
    return 0;
}

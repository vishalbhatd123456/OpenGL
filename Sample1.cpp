
#include<GL/glut.h>

void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0); //set the display window color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,200.0);
}

void lineSegnment(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //clear the display window
    glBegin(GL_LINES);
    glVertex2f(180,15);
    glVertex2f(10,145);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("Example Program");

    init();
    glutDisplayFunc(lineSegnment);
    glutMainLoop();

}

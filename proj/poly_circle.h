
#include <glut.h>

#include <math.h>
const int n = 40;
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536f;
void myDisplay(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    for(i=0; i<n; ++i)
        glVertex2f(R*cos(i*2*Pi/n), R*sin(i*2*Pi/n));
    glEnd();
    glFlush();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Xcode Glut Demo");
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}


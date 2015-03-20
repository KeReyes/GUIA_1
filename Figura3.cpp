//Keiri Merary Ayala R...AR12042

//#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>//#include <C:\GLUT\include\GL\glut.h>
#include <math.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); // color amarillo

    glPointSize (3);

    glBegin(GL_TRIANGLES);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.7, 0.30, 0.0);
    glVertex3f(0.70, -0.30, 0.0);
    glEnd();

    glColor3f(0.5, 1.0, 0.5); // color verde
    glBegin(GL_TRIANGLES);
    glVertex3f(0.40, 0.20, 0.0);
    glVertex3f(0.10, 0.40, 0.0);
    glVertex3f(-0.20, 0.20, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // color rojo
    glBegin(GL_TRIANGLES);
    glVertex3f(0.10, 0.40, 0.0);
    glVertex3f(-0.50, 0.40, 0.0);
    glVertex3f(-0.20, 0.20, 0.0);
    glEnd();

    glColor3f(0.5, 1.0, 0.5); // color verde
    glBegin(GL_TRIANGLES);
    glVertex3f(0.40, -0.20, 0.0);
    glVertex3f(0.10, -0.40, 0.0);
    glVertex3f(-0.20, -0.20, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // color rojo
    glBegin(GL_TRIANGLES);
    glVertex3f(0.10, -0.40, 0.0);
    glVertex3f(-0.50, -0.40, 0.0);
    glVertex3f(-0.20, -0.20, 0.0);
    glEnd();


    glColor3f(0.0, 0.0, 1.0); // color blue
    glBegin(GL_POLYGON);
    glVertex3f(0.70, 0.20, 0.0);
    glVertex3f(0.70, -0.20, 0.0);
    glVertex3f(-0.70, -0.20, 0.0);
    glVertex3f(-0.70, 0.20, 0.0);
    glEnd();

    glColor3f(1.0, 1.0, 0.0); // color blue
    glRectd(-0.8,0.15,-0.7,0.05);
    glRectd(-0.8,-0.05,-0.7,-0.15);


    glutSwapBuffers();
    glEnd();

    glFlush ();

 }
 void init (void)
 {
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-1.1, 1.0, -1.0, 1.0, -1.0, 1.0);
 }

 int main(int argc, char** argv)
 {
     glutInit(&argc, argv);
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize (350, 350);
     glutInitWindowPosition (100, 100);
     glutCreateWindow ("hello");
     init ();
     glutDisplayFunc(display);
     glutMainLoop();
     return 0;
 }

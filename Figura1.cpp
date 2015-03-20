//Keiri Merary Ayala R...AR12042

//#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h> //#include <C:\GLUT\include\GL\glut.h>
#include <math.h>

void display(void)
{
     glClear (GL_COLOR_BUFFER_BIT);
     glColor3f (1.0, 1.0, 1.0);
     glPointSize (2);

     GLfloat angulo;
     int i;
     GLfloat x,y,r1=0.5,r2=0.25;


     glBegin(GL_POINTS);

     for (i=0; i<=360; i+=7)
     {
        //A=r1*r2*M_PI;
        angulo=i+M_PI/180;

        y=r2*cos(angulo);
        x=r1*sin(angulo);


     glVertex3f(x,y,0);

     }

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
     glutInitWindowSize (450, 450);
     glutInitWindowPosition (100, 100);
     glutCreateWindow ("hello");
     init ();
     glutDisplayFunc(display);
     glutMainLoop();
     return 0;
 }

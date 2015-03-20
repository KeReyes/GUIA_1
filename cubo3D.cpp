//Keiri Merary Ayala R...AR12042

//#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>//#include <C:\GLUT\include\GL\glut.h>
		double rotate_y=0;
		double rotate_x=0;
		double rotate_z=0;
		GLfloat X = 0.0f;
		GLfloat Y = 0.0f;
		GLfloat Z = 0.0f;
		GLfloat scale = 1.0f;
		void display()
		{
		// Borrar pantalla y Z-buffer
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		// Resetear transformaciones
		glLoadIdentity();

		// Rotar en "rotate_x" y "rotate_y"
		glRotatef( rotate_x, 1.0, 0.0, 0.0 );
		glRotatef( rotate_y, 0.0, 1.0, 0.0 );
		glRotatef(rotate_z, 0.0, 0.0, 1.0 );

		glTranslatef(X, Y, Z); // Translates the screen left or right

		// Otras transformaciones
		glScalef(scale, scale, scale);

		//LADO FRONTAL: lado multicolor
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0); // color rojo
		glVertex3f( 0.3, -0.3, -0.3 ); // v1 es rojo

        glColor3f(1.0, 1.0, 0.0); // color amarillo
		glVertex3f( 0.3, 0.3, -0.3 ); // v2 es amarillo

		glColor3f(0.0, 0.0, 0.1); // color azul
		glVertex3f( -0.3, 0.3, -0.3 ); // v3 es azul

		glColor3f (1.0, 1.0, 1.0);  // color blanco
		glVertex3f( -0.3, -0.3, -0.3 ); // v4 es blanco
		glEnd();

		// LADO TRASERO: lado blanco
        glBegin(GL_POLYGON);
        glColor3f(   1.0,  1.0, 1.0 );
        glVertex3f(  0.3, -0.3, 0.3 );
        glVertex3f(  0.3,  0.3, 0.3 );
        glVertex3f( -0.3,  0.3, 0.3 );
        glVertex3f( -0.3, -0.3, 0.3 );
        glEnd();

        // LADO DERECHO: lado verde
        glBegin(GL_POLYGON);
        glColor3f(  0.0,  0.5,  0.0 );
        glVertex3f( 0.3, -0.3, -0.3 );
        glVertex3f( 0.3,  0.3, -0.3 );
        glVertex3f( 0.3,  0.3,  0.3 );
        glVertex3f( 0.3, -0.3,  0.3 );
        glEnd();

        // LADO IZQUIERDO: lado amarillo
        glBegin(GL_POLYGON);
        glColor3f(   1.0,  1.0,  0.0 );
        glVertex3f( -0.3, -0.3,  0.3 );
        glVertex3f( -0.3,  0.3,  0.3 );
        glVertex3f( -0.3,  0.3, -0.3 );
        glVertex3f( -0.3, -0.3, -0.3 );
        glEnd();

        // LADO SUPERIOR: lado azul
        glBegin(GL_POLYGON);
        glColor3f(   0.0,  0.0,  1.0 );
        glVertex3f(  0.3,  0.3,  0.3 );
        glVertex3f(  0.3,  0.3, -0.3 );
        glVertex3f( -0.3,  0.3, -0.3 );
        glVertex3f( -0.3,  0.3,  0.3 );
        glEnd();

        // LADO INFERIOR: lado rojo
        glBegin(GL_POLYGON);
        glColor3f(   1.0,  0.0,  0.0 );
        glVertex3f(  0.3, -0.3, -0.3 );
        glVertex3f(  0.3, -0.3,  0.3 );
        glVertex3f( -0.3, -0.3,  0.3 );
        glVertex3f( -0.3, -0.3, -0.3 );
        glEnd();

		glFlush();
		glutSwapBuffers();
	}

	void specialKeys( int key, int x, int y )
	{
	// Flecha derecha: aumentar rotaci�n 7 grados
		if (key == GLUT_KEY_RIGHT)
		rotate_y += 7;

	// Flecha izquierda: disminuir rotaci�n 7 grados
		else if (key == GLUT_KEY_LEFT)
		rotate_y -= 7;
		else if (key == GLUT_KEY_UP)
		rotate_x += 7;
		else if (key == GLUT_KEY_DOWN)
		rotate_x -= 7;
		else if (key == GLUT_KEY_F2)
		rotate_z += 7;
		else if (key == GLUT_KEY_F2)
		rotate_z -= 7;

		// actualizaci�n de visualizaci�n
		glutPostRedisplay();
		}

		void keyboard(unsigned char key, int x, int y)
		{
		switch (key)
		{
		case 's':
		scale=0.5;
		break;
		case 'd':
		scale=1.5;
		break;
		case 'x' :
		X += 0.1f;
		break;
		case 'X' :
		X -= 0.1f;
		break;
		case 'y' :
		Y += 0.1f;
		break;
		case 'Y' :
		Y -= 0.1f;
		break;
		case 'z':
		Z -= 0.1f;
		break;
		case 'Z':
		Z += 0.1f;
		break;
		case 'q':
		exit(0); // exit
		}
		glutPostRedisplay(); // actualizaci�n de visualizaci�n
		}
		int main(int argc, char* argv[])
		{
		glutInit(&argc,argv);


		// Solicitar ventana con color real y doble buffer con Z-buffer
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize (800, 600);
		glutInitWindowPosition (0, 0);


		// Crear ventana
		glutCreateWindow("Ejemplo de Movimientos con OPenGL");


		// Habilitar la prueba de profundidad de Z-buffer
		glEnable(GL_DEPTH_TEST);


		// Funciones de retrollamada
		glutDisplayFunc(display);

		glutKeyboardFunc(keyboard); //invoca funcion de teclado

		glutSpecialFunc(specialKeys);//invoca teclas de funci�n especial
		glutMainLoop();
		return 0;
		}

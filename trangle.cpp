#include<GL/glut.h>
#include<string.h>


void displayText( ) 
{
	const char *str="Simple triangle";
	int j = strlen( str );
	glColor3f( 0.7, 0.0, 1.0 );
	glRasterPos2f( -0.2, -0.8 );
	for( int i = 0; i < j; i++ ) 
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str[i] );
	}

	const char *str2="Shubhankar Nath R134214062";
	j = strlen( str2 );
	glColor3f( 0.2, 0.5, 1.0 );
	glRasterPos2f( -0.9, 0.9 );
	for( int i = 0; i < j; i++ ) 
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str2[i] );
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.2f, 0.2f, 0.2f, 0.2f); 
	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 0) ;
	glVertex2f(-0.4, 0.5);
	glVertex2f(0, -0.2);
	glVertex2f(-0.8, -0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 0);
	glVertex2f(0.5, 0.5);
	glColor3f(0.5, 0, 0);
	glVertex2f(0.9, -0.2);
	glColor3f(0, 0, 0.5);
	glVertex2f(0.1, -0.2);
	glEnd();

	displayText();
	glFlush();
}


int main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Simple Triangle");
  glutDisplayFunc(display);
  glutMainLoop();
}
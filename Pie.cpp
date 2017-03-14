#include<GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<unistd.h>


void drawPie(float percent, float r, float g, float b)
{
  float d=0;
  for (int i =0; i<360; i++)
  {
    d= (3.14/180)*(i*percent);//Converting radian into degree
    glBegin(GL_LINES);
    glColor3f(r,g,b);
    glVertex2d(300,300);
    glVertex2f((100*cos(d)+300), (100*sin(d)+300));
    usleep(8000);//Causing Delay
    glEnd();
    glFinish();
  }
}

void myKey(unsigned char key, int x, int y)
{
  if(key==32)// 32 is ASCII code for SPACEBAR
      {
        glClear(GL_COLOR_BUFFER_BIT);
      	glClearColor(0.0f, 0.0f, 0.0f, 0.8f);
        glFlush();
      }
  else if ((key==68)||(key=100))// ASCII code for "D" or "d"
  {
    drawPie(.50,1,1,1);
  }
}

void display()
{
  const char *str="Press SPACEBAR to clear Screen & 'D' to re-draw. ";
	int j = strlen( str );
	glColor3f(1,1,1);
	glRasterPos2f( 180, 550 );
	for( int i = 0; i < j; i++ )
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_10, str[i] );
	}

	const char *str2="Shubhankar Nath R134214062";
	j = strlen( str2 );
	glColor3f( 0.2, 0.5, 1.0 );
	glRasterPos2f( 10, 50 );
	for( int i = 0; i < j; i++ )
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str2[i] );
	}

  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("DDA");
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(0,600,600,0);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}

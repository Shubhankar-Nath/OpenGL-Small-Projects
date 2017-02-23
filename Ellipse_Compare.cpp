#include<GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<unistd.h>

void drawMidPt(int a, int b, int xc, int yc)
{
  float aSq = a * a;
  float bSq = b * b;
  float x = 0, y = b, p;
  float px = 0, py = 2 * aSq * y;
  glColor3f( 1 ,0, 0);
  glBegin(GL_POINTS);
  glVertex2d(xc+x,yc-y);// Top most point
  glVertex2d(xc-x,yc+y);// Bottom most point
  glEnd();
  glFinish();

  p = bSq - (aSq * b) + (0.25 * aSq);
  while (px < py)
  {
    x++;
    px = px + 2 * bSq;
    if (p < 0)
    p = p + bSq + px;
    else
    {
      y--;
      py = py - 2 * aSq;
      p = p + bSq + px - py;
    }
    glBegin(GL_POINTS);
		glVertex2d(xc+x,yc+y);
    glVertex2d(xc+x,yc-y);
    glVertex2d(xc-x,yc-y);
    glVertex2d(xc-x,yc+y);
    usleep(8000);//Causing Delay
    glEnd();
    glFinish();
  }

 p = bSq*(x+0.5)*(x+0.5) + aSq*(y-1)*(y-1) - aSq*bSq;

 while (y > 0)
 {
  y--;
  py = py - 2 * aSq;
  if (p > 0)
  p = p + aSq - py;
  else
  {
    x++;
    px = px + 2 * bSq;
    p = p + aSq - py + px;
  }
  glBegin(GL_POINTS);
  glVertex2d(xc+x,yc+y);
  glVertex2d(xc+x,yc-y);
  glVertex2d(xc-x,yc-y);
  glVertex2d(xc-x,yc+y);
  usleep(8000);//Causing Delay
  glEnd();
  glFinish();
  }
}

void drawPolar(int a, int b, int xc, int yc)
{
  glColor3f(0.2, 0.6, 0.2) ;
  for (int i =0; i<360; i++)
  {
    glBegin(GL_POINTS);
    glVertex2f((a*sin(i)+xc),(b*cos(i)+yc));
    usleep(8000);//Causing Delay
    glEnd();
    glFlush();
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
    drawPolar(60, 60, 150, 150);
    drawPolar(52, 68, 150, 450);
    drawMidPt(60, 60, 450, 150);
    drawMidPt(52, 68, 450, 450);
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
  glutCreateWindow("Ellipse Compare");
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(0,600,600,0);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}

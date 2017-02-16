#include<GL/glut.h>
#include<string.h>
#include<stdio.h>

//.... Setting Global Variables to be visible by all functions ....
int count=0, x1=0, y1=0, y2=0, x2=0;
bool flag=true;

void drawDDA(int x1, int y1, int x2, int y2)// function to draw lines using two points
{
  float fx=x1, fy=y1;
  int dx=x2-x1;
  int dy=y2-y1;
  int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
	float xIncrement = dx / (float)steps;
	float yIncrement = dy / (float)steps;
  glBegin(GL_POINTS);
  glVertex2f(fx, fy);
  for (int i = 0; i < steps; i++)
  {
    fx += xIncrement;
    fy += yIncrement;
    glVertex2f(fx, fy);
  }
 glEnd();
 glFlush();
}

void mymouse(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    if (flag==true)//Setting Values for First click
    {
      x1=x;
      y1=y;
      flag=false;
      count++;
    }
    else//Setting Values for Second click
    {
      x2=x;
      y2=y;
      flag =true;
      count++;
    }
    if(count==2)// Making Sure that it is clicked twice
    {
      drawDDA(x1,y1,x2,y2);// Passing the coordinates to draw lines
      count=0;
    }
  }
}

void myKey(unsigned char key, int x, int y)
{
  if(key==32)// 32 is ASCII code for SPACEBAR
      {
        glClear(GL_COLOR_BUFFER_BIT);
      	glClearColor(0.4f, 0.4f, 0.4f, 0.8f);
        glFlush();
      }
}

void display()
{
  const char *str="Press SPACEBAR to clear Screen and Left-click twice to draw.";
	int j = strlen( str );
	glColor3f(1,1,1);
	glRasterPos2f( 170, 550 );
	for( int i = 0; i < j; i++ )
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_10, str[i] );
	}

	const char *str2="Shubhankar Nath R134214062";
	j = strlen( str2 );
	glColor3f( 0.2, 0.5, 1.0 );
	glRasterPos2f( 10, 25 );
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
  glutMouseFunc(mymouse);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}

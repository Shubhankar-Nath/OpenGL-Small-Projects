#include<GL/glut.h>
#include<string.h>
#include<stdio.h>

//.... Setting Global Variables to be visible by all functions ....
int count=0, x1=0, y1=0, y2=0, x2=0;
bool flag=true;

void Redraw()
{

    glClear(GL_COLOR_BUFFER_BIT);//clearing Screen
    glClearColor(0, 0, 0, 1);
    glBegin(GL_LINE_LOOP);//making a square
    glColor3f(0.2,0.8,0.2);//Nearly green colour
    glVertex2f(150,150);
    glVertex2f(450,150);
    glVertex2f(450,450);
    glVertex2f(150,450);
    glEnd();

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

void clipLine (float x1, float y1, float x2, float y2)
{
  float m = (y2-y1)/(x2-x1);
  glBegin(GL_LINES);//Drawing orignal Line:RED
  glColor3f(0.8,0.2,0.2);
  glVertex2f(x1,y1);
  glVertex2f(x2,y2);
  glEnd();
  glFinish();

  //Condition for clipped line outside viewport
  if ((x1<150)&&(x2<150))
  Redraw();
  if ((y1<150)&&(y2<150))
  Redraw();
  if ((x1>450)&&(x2>450))
  Redraw();
  if ((y1>450)&&(y2>450))
  Redraw();

  //Making adjustments
  if(x1<150)
  {
    x1=150;
    y1=y2-(m*(x2-x1));
  }
  if(x2<150)
  {
    x2=150;
    y2=(m*(x2-x1))+y1;
  }
  if(y1<150)
  {
    y1=150;
    x1=x2-((1/m)*(y2-y1));
  }
  if(y2<150)
  {
    y2=150;
    x2=((1/m)*(y2-y1))+x1;
  }

  if(x1>450)
  {
    x1=450;
    y1=y2-(m*(x2-x1));
  }
  if(x2>450)
  {
    x2=450;
    y2=(m*(x2-x1))+y1;
  }
  if(y1>450)
  {
    y1=450;
    x1=x2-((1/m)*(y2-y1));
  }
  if(y2>450)
  {
    y2=450;
    x2=((1/m)*(y2-y1))+x1;
  }


  glBegin(GL_LINES);//Drawing clipped Line
  glColor3f(0.2,0.2,0.8);
  glVertex2f(x1,y1);
  glVertex2f(x2,y2);
  glEnd();
  glFinish();
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
      clipLine(x1,y1,x2,y2);// Passing the coordinates to draw lines
      count=0;
    }
  }
}

void myKey(unsigned char key, int x, int y)//to make use of keyboard
{
  if(key==32)// 32 is ASCII code for SPACEBAR
      {
        Redraw();
      }
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);//clearing Screen
  glClearColor(0.4f, 0.4f, 0.4f, 0.8f);
  glBegin(GL_LINE_LOOP);//making a square
  glColor3f(0.2,0.8,0.2);//Nearly green colour
  glVertex2f(150,150);
  glVertex2f(450,150);
  glVertex2f(450,450);
  glVertex2f(150,450);
  glEnd();

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

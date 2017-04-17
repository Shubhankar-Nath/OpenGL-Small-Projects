#include<GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;
//.... Setting Global Variables to be visible by all functions ....
int count=0, x1=0, y1=0, y2=0, x2=0;
bool flag=true;

void ScreenClear()//ScreenClear the contents of the screen
{
  glClear(GL_COLOR_BUFFER_BIT);//clearing Screen
  glClearColor(0, 0, 0, 1);
  glBegin(GL_LINE_LOOP);//making Liang Barsky
  glColor3f(0.2,0.8,0.2);//Nearly green colour
  glVertex2f(100,100);
  glVertex2f(500,100);
  glVertex2f(500,300);
  glVertex2f(100,300);
  glEnd();

  glBegin(GL_LINE_LOOP);//making Cohen-Sutherland
  glColor3f(0.4,0.6,0.2);//Nearly green colour
  glVertex2f(300,350);
  glVertex2f(500,350);
  glVertex2f(500,500);
  glVertex2f(300,500);
  glEnd();

  const char *str="SPACEBAR: Clear-Screen | Left-click twice to draw.";
  int j = strlen( str );
  glColor3f(1,1,1);
  glRasterPos2f( 5, 570 );
  for( int i = 0; i < j; i++ )
  {
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_10, str[i] );
  }

  const char *str2="Shubhankar Nath R134214062";
  j = strlen( str2 );
  glColor3f( 0.2, 0.5, 1.0 );
  glRasterPos2f( 5, 590 );
  for( int i = 0; i < j; i++ )
  {
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_10, str2[i] );
  }
  glFlush();
}

void clipLine (float x1, float y1, float x2, float y2)
{
  float x_1=x1, x_2=x2, y_1=y1, y_2=y2;//copying the values

    //====================Cohen-Sutherland START========================
    float m = (y2-y1)/(x2-x1);
  if ((x1<100)&&(x2<100))
  ScreenClear();
  if ((y1<100)&&(y2<100))
  ScreenClear();
  if ((x1>500)&&(x2>500))
  ScreenClear();
  if ((y1>300)&&(y2>300))
  ScreenClear();

  //Making adjustments
  if(x1<100)
  {
    x1=100;
    y1=y2-(m*(x2-x1));
  }
  if(x2<100)
  {
    x2=100;
    y2=(m*(x2-x1))+y1;
  }
  if(y1<100)
  {
    y1=100;
    x1=x2-((1/m)*(y2-y1));
  }
  if(y2<100)
  {
    y2=100;
    x2=((1/m)*(y2-y1))+x1;
  }

  if(x1>500)
  {
    x1=500;
    y1=y2-(m*(x2-x1));
  }
  if(x2>500)
  {
    x2=500;
    y2=(m*(x2-x1))+y1;
  }
  if(y1>300)
  {
    y1=300;
    x1=x2-((1/m)*(y2-y1));
  }
  if(y2>300)
  {
    y2=300;
    x2=((1/m)*(y2-y1))+x1;
  }

    glBegin(GL_LINES);//Drawing clipped Line
    glColor3f(0.2,0.2,0.8);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glFinish();
//====================Cohen-Sutherland END========================
//********************Liang-Barsky START**********************

float xmin=300, ymin=350, xmax=500, ymax=500, t1=0, t2=1, p[4], q[4], temp;
p[0]=x_1-x_2;
p[1]=x_2-x_1;
p[2]=y_1-y_2;
p[3]=y_2-y_1;
q[0]=x_1-xmin;
q[1]=xmax-x_1;
q[2]=y_1-ymin;
q[3]=ymax-y_1;

for (int i=0; i<4; i++)
{
  if ((p[i]==0)&&(q[i]<0))
ScreenClear();

}

for (int i=0; i<4; i++)
{
  temp=q[i]/p[i];
  if(p[i]<0)
        {
            if(t1<=temp)
                t1=temp;
        }
        else
        {
            if(t2>temp)
                t2=temp;
        }
}
if(t1<t2)
    {
        x1 = x_1 + t1 * p[1];
        x2 = x_1 + t2 * p[1];
        y1 = y_1 + t1 * p[3];
        y2 = y_1 + t2 * p[3];
    }

    glBegin(GL_LINES);//Drawing clipped Line
    glColor3f(0.2,0.2,0.8);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glFinish();
//********************Liang-Barsky END**********************

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
      glBegin(GL_LINES);//Drawing orignal Line:RED
      glColor3f(0.8,0.2,0.2);
      glVertex2f(x1,y1);
      glVertex2f(x2,y2);
      glEnd();
      glFinish();
      clipLine(x1,y1,x2,y2);// Passing the coordinates to draw lines
      count=0;
      //cout<<"\n"<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
    }
  }
}

void myKey(unsigned char key, int x, int y)//Space to refresh screen
{
  if(key==32)// 32 is ASCII code for SPACEBAR
      {
        ScreenClear();
      }
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);//clearing Screen
  glClearColor(0.4f, 0.4f, 0.4f, 0.8f);
  glBegin(GL_LINE_LOOP);//making Liang Barsky
  glColor3f(0.2,0.8,0.2);//Nearly green colour
  glVertex2f(100,100);
  glVertex2f(500,100);
  glVertex2f(500,300);
  glVertex2f(100,300);
  glEnd();

  glBegin(GL_LINE_LOOP);//making Cohen-Sutherland
  glColor3f(0.4,0.6,0.2);//Nearly green colour
  glVertex2f(300,350);
  glVertex2f(500,350);
  glVertex2f(500,500);
  glVertex2f(300,500);
  glEnd();

  const char *str="SPACEBAR: Clear-Screen | Left-click twice to draw.";
	int j = strlen( str );
	glColor3f(1,1,1);
	glRasterPos2f( 5, 570 );
	for( int i = 0; i < j; i++ )
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_10, str[i] );
	}

	const char *str2="Shubhankar Nath R134214062";
	j = strlen( str2 );
	glColor3f( 0.2, 0.5, 1.0 );
	glRasterPos2f( 5, 590 );
	for( int i = 0; i < j; i++ )
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_10, str2[i] );
	}
  glFlush();
}


int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Clipping");
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(0,600,600,0);
  glutDisplayFunc(display);
  glutMouseFunc(mymouse);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}

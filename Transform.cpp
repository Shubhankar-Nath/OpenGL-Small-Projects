#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
#define PI 3.14159265

using namespace std;

float OrignalTri [3][3]={{0,-100,100},{100,-100,-100},{1,1,1}};
static float t_x=0, t_y=0, theta=0, s_x=0, s_y=0;

void drawTriangle(float Tri[3][3])
{
  glClear(GL_COLOR_BUFFER_BIT);//Clearing Screen
  glClearColor(0.0f, 0.0f, 0.0f, 0.8f);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.2, 0.6, 0.2);
  glVertex2f(Tri[0][0],Tri[1][0]);//Matrix position
  glVertex2f(Tri[0][1],Tri[1][1]);
  glVertex2f(Tri[0][2],Tri[1][2]);
  glEnd();
  glFinish();

  glBegin(GL_LINES);//Drawing grid
  glColor4f(0.6,0.2,0.2,0.8);
  for (int v=-300;v<300;v=v+60)
  {
    glVertex2f(-300,v);
    glVertex2f(300,v);
    glVertex2f(v,-300);
    glVertex2f(v,300);
  }
  glEnd();
  glFinish();
}

void translate(float x, float y)
{
  float TranslateMatrix [3][3]={{1,0,x},{0,1,y},{0,0,1}}, ReturnMatrix[3][3];
  for (int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      float sum=0;
      for (int k=0;k<3;k++)
      {
        sum=sum+(TranslateMatrix[i][k]*OrignalTri[k][j]);
      }
      ReturnMatrix[i][j]=sum;
    }
  }
  drawTriangle(ReturnMatrix);
}

void rotate(float thetaDegree)
{
  float a=1,b=0;// for zero degree
  if (thetaDegree==90)
  {
    a=0;
    b=1;
  }
  if (thetaDegree==180)
  {
    a=-1;
    b=0;
  }
  if (thetaDegree==270)
  {
    a=0;
    b=-1;
  }
  float RotateMatrix [3][3]={{a,b,0},{b,a,0},{0,0,1}}, ReturnMatrix[3][3];
  for (int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      float sum=0;
      for (int k=0;k<3;k++)
      {
        sum=sum+(RotateMatrix[i][k]*OrignalTri[k][j]);
      }
      ReturnMatrix[i][j]=sum;
    }
  }
  drawTriangle(ReturnMatrix);
}

void reflect(float a, float b, float c, float d)
{
  float ReflectMatrix [3][3]={{a,b,0},{c,d,0},{0,0,1}}, ReturnMatrix[3][3];
  for (int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      float sum=0;
      for (int k=0;k<3;k++)
      {
        sum=sum+(ReflectMatrix[i][k]*OrignalTri[k][j]);
      }
      ReturnMatrix[i][j]=sum;
    }
  }
  drawTriangle(ReturnMatrix);
}

void orignal()
{
  drawTriangle(OrignalTri);
}

void zoom( float sx, float sy)
{
  float ZoomMatrix [3][3]={{sx,0,0},{0,sy,0},{0,0,1}}, ReturnMatrix[3][3];
  for (int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      float sum=0;
      for (int k=0;k<3;k++)
      {
        sum=sum+(ZoomMatrix[i][k]*OrignalTri[k][j]);
      }
      ReturnMatrix[i][j]=sum;
    }
  }
  drawTriangle(ReturnMatrix);
}

void display()
{
  const char *str2="Shubhankar Nath R134214062";
	int j = strlen( str2 );
	glColor3f( 0.9, 0.5, 1.0 );
	glRasterPos2f(-280, 280 );
	for( int i = 0; i < j; i++ )
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str2[i] );
	}
  glBegin(GL_LINES);//Drawing grid
  glColor4f(0.6,0.2,0.2,0.8);
  for (int v=-300;v<300;v=v+60)
  {
    glVertex2f(-300,v);
    glVertex2f(300,v);
    glVertex2f(v,-300);
    glVertex2f(v,300);
  }
  glEnd();
  glFinish();
}

void myKey(unsigned char key, int x, int y)
{
  if (key==97)//move left with 'a'
  translate(--t_x, t_y);
  else if (key==119)//move up with 'w'
  translate(t_x,--t_y);
  else if (key==100)//move right with 'd'
  translate(++t_x,t_y);
  else if (key==115)//move down with 's'
  translate(t_x,++t_y);
  else if (key==32)//rotate 90 degrees with 'space'
  {
    rotate(theta);
    theta=theta+90;//rotating anti-clockwise 90 degree
    if (theta>270)
      theta=0;
  }
  else if(key==111)//show orignal with 'o'
  orignal();
  else if(key==120)//reflect along x axis with 'x'
  reflect(1,0,0,-1);
  else if(key==121)//reflect along y axis with 'y'
  reflect(-1,0,0,1);
  else if(key==122)// zoom to z
  zoom(++s_x,++s_y);
  else if(key==113)
  zoom(--s_x,--s_y);
}

void showOption()
{
    cout<<"Choose the transformation:";
    cout<<"\t\n.Translation: a,w,s,d";
    cout<<"\t\n.Rotation: SPACEBAR";
    cout<<"\t\n.Orignal: o";
}

int main(int argc, char** argv)
{
  showOption();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Transformation");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-300,300,300,-300);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}

#include<GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;
float OrignalFig [4][4]={{0,0,50,1},{50,0,-20,1},{-50,0,-20,1},{0,50,0,1}};
static float t_x=0, t_y=0, t_z=0, s_x=0, s_y=0, s_z=0, theta=0;

void draw( float Fig[4][4])
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
  glLineWidth(5.0f);//Drawing axis again
  glColor4f(0.0,0.8,0.0,0.3);
  glVertex3f(0,0,-300);
  glVertex3f(0,0,300);
  glColor4f(0.0,0.8,0.0,0.3);
  glVertex3f(0,-300,0);
  glVertex3f(0,300,0);
  glColor4f(0.0,0.8,0.0,0.3);
  glVertex3f(-300,0,0);
  glVertex3f(300,0,0);
  glLineWidth(1.0f);
  glEnd();
  glFinish();

  glBegin(GL_TRIANGLES);
  glColor3f(0.0,0.0,0.8);//BottomSurface
  glVertex3f(Fig[0][0],Fig[0][1],Fig[0][2]);
  glVertex3f(Fig[1][0],Fig[1][1],Fig[1][2]);
  glVertex3f(Fig[2][0],Fig[2][1],Fig[2][2]);
  glColor3f(0.4,0.0,0.6);//BackSurface
  glVertex3f(Fig[3][0],Fig[3][1],Fig[3][2]);
  glVertex3f(Fig[1][0],Fig[1][1],Fig[1][2]);
  glVertex3f(Fig[2][0],Fig[2][1],Fig[2][2]);
  glColor3f(0.2,0.0,0.4);//LSide
  glVertex3f(Fig[0][0],Fig[0][1],Fig[0][2]);
  glVertex3f(Fig[3][0],Fig[3][1],Fig[3][2]);
  glVertex3f(Fig[2][0],Fig[2][1],Fig[2][2]);
  glColor3f(0.0,0.4,0.4);//RSide
  glVertex3f(Fig[0][0],Fig[0][1],Fig[0][2]);
  glVertex3f(Fig[1][0],Fig[1][1],Fig[1][2]);
  glVertex3f(Fig[3][0],Fig[3][1],Fig[3][2]);
  glEnd();
  glFinish();
}

void translate(float l, float m, float n)
{
  float TranslateMatrix [4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{l,m,n,1}}, ReturnMatrix[4][4];
  for (int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      float sum=0;
      for (int k=0;k<4;k++)
      {
        sum=sum+(OrignalFig[i][k]*TranslateMatrix[k][j]);
      }
      ReturnMatrix[i][j]=sum;
    }
  }
  draw(ReturnMatrix);
}

void rotate(float thetaDegree)
{
  if (thetaDegree==90)
  {
    float TranslateMatrix [4][4]={{0,0,-1,0},{0,1,0,0},{1,0,0,0},{0,0,0,1}}, ReturnMatrix[4][4];
    for (int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
      {
        float sum=0;
        for (int k=0;k<4;k++)
        {
          sum=sum+(OrignalFig[i][k]*TranslateMatrix[k][j]);
        }
        ReturnMatrix[i][j]=sum;
      }
    }
    draw(ReturnMatrix);
  }
  if (thetaDegree==180)
  {
    float TranslateMatrix [4][4]={{-1,0,0,0},{0,1,0,0},{0,0,-1,0},{0,0,0,1}}, ReturnMatrix[4][4];
    for (int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
      {
        float sum=0;
        for (int k=0;k<4;k++)
        {
          sum=sum+(OrignalFig[i][k]*TranslateMatrix[k][j]);
        }
        ReturnMatrix[i][j]=sum;
      }
    }
    draw(ReturnMatrix);
  }
  if (thetaDegree==270)
  {
    float TranslateMatrix [4][4]={{0,0,1,0},{0,1,0,0},{-1,0,0,0},{0,0,0,1}}, ReturnMatrix[4][4];
    for (int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
      {
        float sum=0;
        for (int k=0;k<4;k++)
        {
          sum=sum+(OrignalFig[i][k]*TranslateMatrix[k][j]);
        }
        ReturnMatrix[i][j]=sum;
      }
    }
    draw(ReturnMatrix);
  }
  if ( thetaDegree==0)
  draw(OrignalFig);
}

void reflect(float a, float b, float c)
{
  float TranslateMatrix [4][4]={{a,0,0,0},{0,b,0,0},{0,0,c,0},{0,0,0,1}}, ReturnMatrix[4][4];
  for (int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      float sum=0;
      for (int k=0;k<4;k++)
      {
        sum=sum+(OrignalFig[i][k]*TranslateMatrix[k][j]);
      }
      ReturnMatrix[i][j]=sum;
    }
  }
  draw(ReturnMatrix);
}

void scale (float sx, float sy, float sz)
{
  float TranslateMatrix [4][4]={{sx,0,0,0},{0,sy,0,0},{0,0,sz,0},{0,0,0,1}}, ReturnMatrix[4][4];
  for (int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      float sum=0;
      for (int k=0;k<4;k++)
      {
        sum=sum+(OrignalFig[i][k]*TranslateMatrix[k][j]);
      }
      ReturnMatrix[i][j]=sum;
    }
  }
  draw(ReturnMatrix);
}

void myKey(unsigned char key, int x, int y)
{
  if (key==97)//move left with 'a'
  translate(--t_x, t_y,t_z);
  else if (key==119)//move up with 'w'
  translate(t_x,--t_y,t_z);
  else if (key==100)//move right with 'd'
  translate(++t_x,t_y,t_z);
  else if (key==115)//move down with 's'
  translate(t_x,++t_y,t_z);
  else if (key==113)//move forward with 'q'
  translate(t_x,t_y,++t_z);
  else if(key==101)//move behind with 'e'
  translate(t_x,t_y,--t_z);
  else if(key==110)//scale up 'n'
  scale(++s_x,++s_y,++s_z);
  else if(key==109)//scale down 'm'
  scale(--s_x,--s_y,--s_z);
  else if (key==120)//reflect yz plane with 'x'
  reflect(-1,1,1);
  else if (key==121)//reflect xz plane 'y'
  reflect(1,-1,1);
  else if (key==122)//reflect xy plane 'z'
  reflect(1,1,-1);
  else if (key==32)//rotate 90 degrees with 'space'
  {
    rotate(theta);
    theta=theta+90;//rotating anti-clockwise 90 degree
    if (theta>270)
      theta=0;
  }

}

void display()
{
  glBegin(GL_LINES);
  glLineWidth(5.0f);//Drawing axis
  glColor4f(0.0,0.8,0.0,0.3);
  glVertex3f(0,0,-300);
  glVertex3f(0,0,300);
  glColor4f(0.0,0.8,0.0,0.3);
  glVertex3f(0,-300,0);
  glVertex3f(0,300,0);
  glColor4f(0.0,0.8,0.0,0.3);
  glVertex3f(-300,0,0);
  glVertex3f(300,0,0);
  glLineWidth(1.0f);
  glEnd();
  glFinish();
  draw (OrignalFig );
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("3D");
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  glOrtho(-300,300,-300,300,300,-300);
  gluLookAt(4.0, 4.0, 8.0,0.0, 0.0, 0.0,0.0, 1.0, 0.);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}

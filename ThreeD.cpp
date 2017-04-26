#include<GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<iostream>

float OrignalCube [8][4]={{-50,50,50,1},{50,50,50,1},{50,50,-50,1},{-50,50,-50,1},{-50,-50,50,1},{50,-50,50,1},{50,-50,-50,1},{-50,-50,-50}};
static float t_x=0, t_y=0, t_z=0;

void drawCube(float Cube[8][4])
{
  glClear(GL_COLOR_BUFFER_BIT);//clearing Screen
  glClearColor(0.4f, 0.4f, 0.4f, 0.8f);

  glBegin(GL_QUADS);//drawing the cube

  glColor4f(0.0,0.0,0.4,0.3);
  glVertex3f(Cube[3][0],Cube[3][1],Cube[3][2]);//back surface
  glVertex3f(Cube[2][0],Cube[2][1],Cube[2][2]);
  glVertex3f(Cube[6][0],Cube[6][1],Cube[6][2]);
  glVertex3f(Cube[7][0],Cube[7][1],Cube[7][2]);

  glColor4f(0.4,0.0,0.0,0.3);
  glVertex3f(Cube[4][0],Cube[4][1],Cube[4][2]);//bottom surface
  glVertex3f(Cube[5][0],Cube[5][1],Cube[5][2]);
  glVertex3f(Cube[6][0],Cube[6][1],Cube[6][2]);
  glVertex3f(Cube[7][0],Cube[7][1],Cube[7][2]);

  glColor4f(0.0,0.4,0.0,0.3);
  glVertex3f(Cube[0][0],Cube[0][1],Cube[0][2]);//left surface
  glVertex3f(Cube[4][0],Cube[4][1],Cube[4][2]);
  glVertex3f(Cube[7][0],Cube[7][1],Cube[7][2]);
  glVertex3f(Cube[3][0],Cube[3][1],Cube[3][2]);

  glColor4f(0.0,0.0,0.4,0.3);
  glVertex3f(Cube[0][0],Cube[0][1],Cube[0][2]);//front surface
  glVertex3f(Cube[1][0],Cube[1][1],Cube[1][2]);
  glVertex3f(Cube[5][0],Cube[5][1],Cube[5][2]);
  glVertex3f(Cube[4][0],Cube[4][1],Cube[4][2]);

  glColor4f(0.4,0.0,0.0,0.3);
  glVertex3f(Cube[0][0],Cube[0][1],Cube[0][2]);//top surface
  glVertex3f(Cube[1][0],Cube[1][1],Cube[1][2]);
  glVertex3f(Cube[2][0],Cube[2][1],Cube[2][2]);
  glVertex3f(Cube[3][0],Cube[3][1],Cube[3][2]);


  glColor4f(0.0,0.4,0.0,0.3);
  glVertex3f(Cube[1][0],Cube[1][1],Cube[1][2]);//right surface
  glVertex3f(Cube[5][0],Cube[5][1],Cube[5][2]);
  glVertex3f(Cube[6][0],Cube[6][1],Cube[6][2]);
  glVertex3f(Cube[2][0],Cube[2][1],Cube[2][2]);


  glEnd();
  glFinish();
}

void translate(float l, float m, float n)
{
  float TranslateMatrix [4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{l,m,n,1}}, ReturnMatrix[8][4];
  for (int i=0;i<4;i++)
  {
    for(int j=0;j<8;j++)
    {
      float sum=0;
      for (int k=0;k<4;k++)
      {
        sum=sum+(TranslateMatrix[i][k]*OrignalCube[k][j]);
      }
      ReturnMatrix[i][j]=sum;
    }
  }
  drawCube(ReturnMatrix[8][4])
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
  else if (key=113)
  translate(t_x,t_y,++t_z);
  else if(key=101)
  translate(t_x,t_y,--t_z);
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
  gluLookAt(3.0, 4.0, 5.0,0.0, 0.0, 0.0,0.0, 1.0, 0.);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}

#include<GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int array[6];

void draw_LineGraph()
{
  int p=0, space= 60, h=0;
  glLineWidth(3.0f);
  glBegin(GL_LINE_STRIP);
  glColor3f(0.4,0.4,0.8);
  while (array[p]!='\0')
  {
    h= (array[p]*6)+60;
    glVertex2f(space, h);
    p++;
    space=space+60;
  }
  glEnd();
  glFlush();
}

void display()
{
  //Drawing grid lines according to the Ortho2D size..
  for (int g=0; g< 660; g=g+60)
  {
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex2f(0, g);// Horizantal lines
    glVertex2f(660, g);
    glVertex2f(g, 0);// Vertical lines
    glVertex2f(g, 660);
    glEnd();
    glFlush();
  }
  glLineWidth(1.0f);
  glBegin(GL_LINES);// for Drawing base lines
  glColor3f(0.8,0.4,0.4);
  glVertex2f(0,60);
  glVertex2f(660,60);
  glVertex2f(60,0);
  glVertex2f(60,660);
  glEnd();
  glFlush();

  draw_LineGraph();
}

int main(int argc, char** argv)
{
  printf ("Enter Values between 0 to 100");
  for ( int i=0; i<6; i++)
  {
  scanf("%d",&array[i] );
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Grid");
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(0,660,0,660);// + 60 just to have corner lines
  glutDisplayFunc(display);
  glutMainLoop();
}

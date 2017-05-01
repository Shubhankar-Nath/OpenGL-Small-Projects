#include<GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<unistd.h>

using namespace std;

void drawBar(int x, int y, int z)//x & z can be -ve but not y
{
  float r=0.0, g=1.0;
  int mod_xmin=x-(x%40);//rounding to nearest lower grid line on surface
  int mod_zmin=z-(z%40);
  int mod_xmax=mod_xmin+40;
  int mod_zmax=mod_zmin+40;
  for (float i = 0; i < y; i++)//y value starts from 0 to given input
  {
    glColor4f(r,g,0.5,0.8);//as height increases, r++ & g--
    glBegin(GL_QUADS);//Drawing base Surface over one another
    glVertex3f(mod_xmin,i,mod_zmin);
    glVertex3f(mod_xmax,i,mod_zmin);
    glVertex3f(mod_xmax,i,mod_zmax);
    glVertex3f(mod_xmin,i,mod_zmax);
    glEnd();
    glFinish();
    usleep(12000);
    r=r+0.005;
    g=g-0.005;
  }
}

void display()
{
  glBegin(GL_QUADS);//Drawing base Surface
  glVertex3f(-200,0,-200);
  glVertex3f(200,0,-200);
  glVertex3f(200,0,200);
  glVertex3f(-200,0,200);
  glEnd();
  glBegin(GL_LINES);//Drawing grid
  glColor4f(0.6,0.2,0.2,0.8);
  for(float i =-200;i<200;i=i+40)
  {
    glVertex3f(i,0,200);
    glVertex3f(i,0,-200);
    glVertex3f(200,0,i);
    glVertex3f(-200,0,i);
  }
  glEnd();
  glFinish();
  drawBar(-87, 150, 37);//x & z values are rounded off to give the area while y gives the magnitude
  drawBar(37, 190, 77);
  drawBar(-87, 19, 97);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("3DBar");
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  glOrtho(-300,300,-300,300,300,-300);//draw from zero to 400 only
  gluLookAt(5.0, 6.0, 8.0,0.0, 0.0, 0.0,0.0, 1.0, 0.);
  glutDisplayFunc(display);
  //glutKeyboardFunc(myKey);
  glutMainLoop();
}

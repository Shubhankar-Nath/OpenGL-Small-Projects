#include<GL/glut.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

static int TriangleHeight[6];//Data Structure to show heights

void drawTriangle()
{
  int a=25, b=75;
  for (int z=0; z<6; z++)
  {// Drawing all the triangles of same base but different height from the array
    glBegin(GL_TRIANGLES);
    glColor3f(0.2f,0.7f,0.3f);
    glVertex2d(a,400);
    glVertex2d(b,400);
    glVertex2d(a,(400-TriangleHeight[z]));
    glEnd();
    glFlush();
    a+=100;//Putting up space
    b+=100;
    printf("%d |", TriangleHeight[z]);
  }
  printf("\n" );
}

void sortTriangle()
{// Use any sorting algorithm here,
  // Using bubble sort
  int key;
  for(int a=0; a<6; a++)
    for(int b=0; b<6-1-a; b++)
    {
      if(TriangleHeight[b]>TriangleHeight[b+1])
      {
        key = TriangleHeight[b+1];
        TriangleHeight[b+1]=TriangleHeight[b];
        TriangleHeight[b]=key;
      }
      usleep(8000);
      drawTriangle();
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
  else if ((key==83)||(key=115))// ASCII code for "S" or "s"
  {
    sortTriangle();
  }
}

void display(/* arguments */)
{
  glClear(GL_COLOR_BUFFER_BIT);// For clearing the screen
  glClearColor(0.0f, 0.0f, 0.0f, 0.8f);
  glFlush();

  const char *str="Press SPACEBAR to clear Screen & 'S' to Sort. ";
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
  drawTriangle();
}

int main(int argc, char** argv)
{
  printf("Enter heights of the triange ( 0 to 300):\n");
  for (int z=0; z<6; z++)
    {
      scanf("%d ", &TriangleHeight[z]);
    }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Sort");
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(0,600,600,0);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}

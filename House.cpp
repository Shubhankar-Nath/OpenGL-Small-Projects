#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdio.h>

void displayText( ) 
{
	const char *str="House";
	int j = strlen( str );
	glColor3f( 0.7, 0.0, 1.0 );
	glRasterPos2f( -0.1, -0.9 );
	for( int i = 0; i < j; i++ ) 
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str[i] );
	}

	const char *str2="Shubhankar Nath R134214062";
	j = strlen( str2 );
	glColor3f( 0.2, 0.5, 1.0 );
	glRasterPos2f( -0.9, 0.9 );
	for( int i = 0; i < j; i++ ) 
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str2[i] );
	}
}

void mymouse(int button, int state, int x, int y)//Change color on Clicking
{

	float xx= (float(x)/300.0)-1;//Converting Pixel values to coordinates {-1, 0, 1}
	float yy= 1-(float(y)/300.0);

	float r=0.1, xcl=-0.6, yc=0.5, pl=0, xcr=0.6, pr=0 ;
	pl = ( (xx-xcl)*(xx-xcl) ) + ( (yy-yc)*(yy-yc) ) - (r*r);//Decision for left
	pr = ( (xx-xcr)*(xx-xcr) ) + ( (yy-yc)*(yy-yc) ) - (r*r);//Decision for rigth

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (pl<=0 || pr <=0) )// Left click color change
	{	
		glBegin(GL_POLYGON);//RCircleRecolor
		glColor3f(0.7, 0.5, 0.2) ;
		for (int i =0; i<360; i++)
		{
			glVertex2f((r*sin(i)+xcr),(r*cos(i)+yc));
		}
		glEnd();

		glBegin(GL_POLYGON);//LCircle
		for (int i =0; i<360; i++)
		{
			glVertex2f((r*sin(i)+xcl),(r*cos(i)+yc));
		}
		glEnd();

		glFlush();
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP && (pl<=0 || pr <=0)	)// Right click color change 
	{	
		glBegin(GL_POLYGON);//RCircleRecolor
		glColor3f(0.4, 0.4, 0.7) ;
		for (int i =0; i<360; i++)
		{
			glVertex2f((r*sin(i)+xcr),(r*cos(i)+yc));
		}
		glEnd();

		glBegin(GL_POLYGON);//LCircle
		for (int i =0; i<360; i++)
		{
			glVertex2f((r*sin(i)+xcl),(r*cos(i)+yc));
		}
		glEnd();

		glFlush();
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.4f, 0.4f, 0.4f, 0.8f); 
	glBegin(GL_LINE_LOOP);// House Outline
	glColor3f(0.2, 0.2, 0.8) ;
	glVertex2f(-0.9,-0.8);
	glVertex2f(0.9, -0.8);
	glVertex2f(0.9, 0.2);
	glVertex2f(0.6, 0.8);
	glVertex2f(0.3, 0.2);
	glVertex2f(0.15, 0.2);
	glVertex2f(0, 0.5);
	glVertex2f(-0.15, 0.2);
	glVertex2f(-0.3, 0.2);
	glVertex2f(-0.6, 0.8);
	glVertex2f(-0.9, 0.2);
	glEnd();

	
	glBegin(GL_LINE_STRIP);//Balcony
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.28, -0.1);
	glVertex2f(0.28, -0.1);
	glVertex2f(0.28, 0.2);
	glEnd();

	glBegin(GL_LINES);//Balcony strips
	float p=-0.28, q=-0.23;
	while ((p<0.28)&&(q<0.28))
	{
		glVertex2f(p,0.05);
		glVertex2f(q,-0.1);
		p=p+0.03;
		q=q+0.03;
	}
	glVertex2f(-0.28,0.05);
	glVertex2f(0.28,0.05);
	glEnd();

	glBegin(GL_POLYGON);//Door1
	glColor3f(0.2, 0.6, 0.2) ;
	glVertex2f(-0.7, -0.8);
	glVertex2f(-0.7, -0.2);
	glVertex2f(-0.5, -0.2);
	glVertex2f(-0.5, -0.8);
	glEnd();

	glBegin(GL_POLYGON);//Door2
	glVertex2f(0.7, -0.8);
	glVertex2f(0.7, -0.2);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.5, -0.8);
	glEnd();

	glBegin(GL_POLYGON);//RCircle
	float r=0.1, xc=0.6, yc=0.5;
	glColor3f(0.2, 0.6, 0.2) ;
	for (int i =0; i<360; i++)
	{
		glVertex2f((r*sin(i)+xc),(r*cos(i)+yc));
	}
	glEnd();
 
	glBegin(GL_POLYGON);//LCircle
	xc=-0.6; yc=0.5;
	for (int i =0; i<360; i++)
	{
		glVertex2f((r*sin(i)+xc),(r*cos(i)+yc));
	}
	glEnd();

	glBegin(GL_LINE_STRIP);//flag
	glColor3f(0.6, 0.1, 0.1) ;
	glVertex2f(0, 0.5);
	glVertex2f(0, 0.88);
	glColor3f(0.9, 0.1, 0.1) ;
	glVertex2f(0.2, 0.75);
	glColor3f(0.6, 0.1, 0.1) ;
	glVertex2f(0, 0.75);
	glVertex2f(0, 0.5);
	glEnd();

	displayText();
	glFlush();
}



int main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("House");
  glutDisplayFunc(display);
  glutMouseFunc(mymouse);
  glutMainLoop();
}
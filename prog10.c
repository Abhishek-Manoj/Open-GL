#include<stdio.h>
#include<GL/glut.h>
float x;
void drawCar(void)
{
 //body
 glColor3f(0.235,0.4,0.140);
 glLineWidth(10.0);
 glBegin(GL_POLYGON);
 glVertex2f(100.0,150.0);
 glVertex2f(400.0,150.0);
 glVertex2f(400.0,250.0);
 glVertex2f(100.0,250.0);
 
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2f(175.0,250.0);
 glVertex2f(200.0,325.0);
 glVertex2f(300.0,325.0);
 glVertex2f(325.0,250.0);
 glEnd();
  
  glColor3f(0.46,0.527,0.597);
 glBegin(GL_POLYGON);
 glVertex2f(240.0,255.0);
 glVertex2f(240.0,315.0);
 glVertex2f(210.0,315.0);
 glVertex2f(190.0,255.0);
 glEnd();
 
 glColor3f(0.46,0.527,0.597);
 glBegin(GL_POLYGON);
 glVertex2f(260.0,255.0);
 glVertex2f(260.0,315.0);
 glVertex2f(290.0,315.0);
 glVertex2f(310.0,255.0);
 glEnd();

 /*glColor3f(0.235,0.4,0.140);
 glBegin(GL_POLYGON);
 glVertex2f(200.0,250.0);
 glVertex2f(200.0,325.0);
 glVertex2f(175.0,250.0);
 glEnd();
 
 glBegin(GL_POLYGON);
 glVertex2f(300.0,250.0);
 glVertex2f(300.0,325.0);
 glVertex2f(325.0,250.0);
 glEnd(); */

 //Tyres
 glColor3f(0.0,0.0,0.0);
 glPushMatrix();
 glTranslatef(150.0,150.0,0.0);
 glutSolidSphere(30.0,100.0,100.0);
 glPopMatrix();
  
 glColor3f(1.0,1.0,1.0);
 glPushMatrix();
 glTranslatef(150.0,150.0,0.0);
 glutSolidSphere(20.0,100.0,100.0);
 glPopMatrix();

 glColor3f(0.0,0.0,0.0);
 glPushMatrix();
 glTranslatef(350.0,150.0,0.0);
 glutSolidSphere(30.0,100.0,100.0);
 glPopMatrix();
 
 glColor3f(1.0,1.0,1.0);
 glPushMatrix();
 glTranslatef(350.0,150.0,0.0);
 glutSolidSphere(20.0,100.0,100.0);
 glPopMatrix();
}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glPushMatrix();
 glTranslatef(x,100.0,0.0);
 drawCar();
 glPopMatrix();
 glPushMatrix();
 glTranslatef(x,-50.0,0.0);
 glScalef(0.5,0.5,1.0);
 drawCar();
 glPopMatrix(); 
 glFlush();
}


void timer(int e)
{
 if(x>-500)
 {
 x--;
 glutPostRedisplay();
 glutTimerFunc(50,timer,0);
 }
}

int main(int argc,char **argv)
{
 printf("Hello");
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100,100);
 glutCreateWindow("First Program");
 glClearColor(0.02,0.741,0.752,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-500.0,500.0,0.0,500.0,-450.0,450.0);
 glutDisplayFunc(display);
 timer(0);
 glutMainLoop();
}

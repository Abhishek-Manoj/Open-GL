#include<stdio.h>
#include<GL/glut.h>
int choice,x=0;
float theta,h,k;
void timer()
{
 x--;
 glutPostRedisplay();
 glutTimerFunc(50,timer,0);
 }
void Rotate_fixed()
{

 
 glTranslatef(h,k,0);
 glRotatef(x,0,1,0);
  glTranslatef(-h,-k,0);
}

void draw_triangle()
{
 
 glColor3f(1.0,0.0,1.0);
 glLineWidth(5.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(100.0,100.0);
 glVertex2f(400.0,100.0);
 glVertex2f(250.0,350.0);
 glEnd();
}

void display_origin()
{
 glClear(GL_COLOR_BUFFER_BIT);
 draw_triangle();
 glPushMatrix();
 glRotatef(x,0,1,0);
 draw_triangle();
 glPopMatrix();
 glFlush();
}

void display_fixed()
{
 glClear(GL_COLOR_BUFFER_BIT);
 draw_triangle();
 glPushMatrix();
 Rotate_fixed();
 draw_triangle();
 glPopMatrix();
 glFlush();
}


void myInit()
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-500.0,500.0,-500.0,500.0,-400.0,400.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
} 

int main(int argc,char **argv)
{
 printf("1.Rotate wrt origin\n");
 printf("2.Rotate wrt fixed point\n");
 printf("Enter your choice:");
 scanf("%d",&choice);
 printf("Enter the angle of rotation:");
 scanf("%f",&theta);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(0,0);
 if(choice==1)
 {
  glutCreateWindow("Triangle Rotation wrt origin");
  glutDisplayFunc(display_origin);
 }
 else if(choice==2)
 {
  printf("Enter the fixed point");
  scanf("%f %f",&h,&k);
  glutCreateWindow("Triangle Rotation wrt fixed points");
  glutDisplayFunc(display_fixed);
 }
 else
 {
  printf("Invalid Input\n");
 }
 myInit();
 timer(0);
 glutMainLoop();
}

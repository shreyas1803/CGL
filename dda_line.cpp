#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cstdlib>

void display(int x, int y){
	glColor3f(0, 1, 0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

float x1,x2,Y1,y2;

void DrawLine(int x1, int Y1, int x2, int y2)
{
  float dy, dx, step, x, y, k, Xin, Yin;
  dx = x2 - x1;
  dy = y2 - Y1;
  if (abs(dx) > abs(dy)) {
    step = abs(dx);
  } else
    step = abs(dy);
  Xin = dx / step;
  Yin = dy / step;
  x = x1;
  y = Y1;
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  for (k = 1; k <= step; k++) {
    x = x + Xin;
    y = y + Yin;
    display(x,y);
}
}

void renderFunction()
{
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0, 700, 0, 700);
	DrawLine(100, 300, 170, 500);
	DrawLine(171, 501, 300, 300);
	DrawLine(300, 300, 100, 300);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
    }

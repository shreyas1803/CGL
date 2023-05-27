#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cstdlib>

void display(int x, int y){
	glColor3f(0, 1, 0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void DrawLine(int x1, int y1, int x2, int y2)
{
	int dy = y2 - y1;
	int dx = x2 - x1;
	int xc, yc;
	int x = x1;
	int y = y1;
	
	if(x1>x2){
		xc = -1;
	}else{
		xc = 1;
	}
	if(y1>y2){
		yc = -1;
	}else{
		yc = 1;
	}
	
	if(dx == 0){
		for(int i=0;i<dy;i++){
			y+=yc;
			display(x, y);
		}
	}
	if(dy == 0){
		for(int i=0;i<dx;i++){
			x+=xc;
			display(x, y);
		}
	}
	if(dx>dy)
	{
		int p = (2*dy)-dx;
		for(int i=0;i<dx;i++){
			if(p>0){
				y = y+yc;
				p = p + (2*dy-2*dx);
			}
			else{
				p = p + (2*dy);
			}
			x = x + xc;
			display(x, y);
		}
	}
	if(dy>dx)
	{
		int p = (2*dx)-dy;
		for(int i=0;i<dy;i++){
			if(p>0){
				x = x+xc;
				p = p + (2*dx-2*dy);
			}
			else{
				p = p + (2*dx);
			}
			y = y + yc;
			display(x, y);
		}
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

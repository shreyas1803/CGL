#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cstdlib>

void setpixel(int x, int y){
	glColor3f(1,0 , 0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	
}

void DrawLine(int x1, int y1, int x2, int y2)
{
    float dy = (y2 - y1);
    float dx = (x2 - x1);

    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    float xin = 1;
    if (x2 < x1) {
        xin = -1;
    }
    float yin = 1;
    if (y2 < y1) {
        yin = -1;
    }

    float x = x1;
    float y = y1;

    if (dx > dy) {
        setpixel(x, y);

        float p = 2 * dy - dx;
        float inc1 = 2 * (dy - dx);
        float inc2 = 2 * dy;

        for (int i = 0;i < dx;i++) {

            if (p >= 0) {
                y += yin;
                p += inc1;

            }
            else {

                x += xin;
                p += inc2;

            }
            setpixel(x, y);
        }

    }
    else {
        setpixel(x, y);
        float p = 2 * dx - dy;
        float inc1 = 2 * (dx - dy);
        float inc2 = 2 * dx;

        for (int i = 0;i < dy;i++) {
            if (p >= 0) {
                p += inc1;
                x += xin;
            }
            else {
                p += inc1;
                y += yin;
            }
            setpixel(x, y);
        }
    }
    glFlush();
}

void renderFunction()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0, 700, 0, 700);
	DrawLine(100, 100, 100, 150);
	DrawLine(100, 150, 200, 150);
	DrawLine(200, 150, 200, 100);
	DrawLine(200, 100, 100, 100);			

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1400,900);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
    }

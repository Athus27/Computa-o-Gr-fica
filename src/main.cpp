#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0); glVertex2f(-0.6f, -0.4f);
        glColor3f(0,1,0); glVertex2f( 0.6f, -0.4f);
        glColor3f(0,0,1); glVertex2f( 0.0f,  0.6f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("FreeGLUT funcionando");

    glClearColor(1,1,1,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

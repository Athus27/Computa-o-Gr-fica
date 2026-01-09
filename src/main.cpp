#include <glad/glad.h>
#include <GL/freeglut.h>
#include <iostream>


bool isFullscren = false;
int winW = 800, winH = 600;
int winX = 100, winY = 100;

void toggleFullscreen(){
    if (!isFullscren) {
        winX = glutGet(GLUT_WINDOW_X);
        winY = glutGet(GLUT_WINDOW_Y);
        winW = glutGet(GLUT_WINDOW_WIDTH);
        winH = glutGet(GLUT_WINDOW_HEIGHT);

        glutFullScreen();
        isFullscren =true;
    } else {
        glutReshapeWindow(winW,winH);
        glutPositionWindow(winX,winY);
        isFullscren = false;
    }
    glutPostRedisplay(); // Força a atualização, marca que a janela deve ser redesenhada
}

void display(){
    // Limpa a tela para não dar crash
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Cor cinza-azulado
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y){
    if (key == 'f' || key == 'F') {
        toggleFullscreen();
    }
}

void reshape(int w, int h){

}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Teste OpenGL");

    // O GLAD deve ser carregado DEPOIS do CreateWindow
    if (!gladLoadGL()) {
        std::cerr << "Erro ao iniciar GLAD" << std::endl;
        return 1; 
    }

    // REGISTROS OBRIGATÓRIOS
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // sua função de teclado

    glutMainLoop();
    return 0;
}
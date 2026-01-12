#include <glad/glad.h>
#include <GL/freeglut.h>
#include <iostream>

#include "Menu.h"


bool isFullscren = false;
int winW = 800, winH = 600;
int winX = 100, winY = 100;

// Objeto global do menu para uso nas callbacks
Menu menu;

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

//favor importar o menu.h e criar um objeto menu, e registrar as funções display e keyboard do menu
// para que o menu funcione corretamente dentro do main loop do glut deverá ser criado um objeto menu fora do main porque as funções de callback do glut não aceitam parâmetros extras, então o objeto menu deve ser global, e deve-se registrar as funções display e keyboard do menu para que o menu funcione corretamente dentro do main loop do glut. Para chamar as funções do menu dentro das funções de callback do glut, deve-se usar o objeto menu global criado fora do mai, e para isso deve-se criar funções wrapper que chamem os métodos do objeto menu, essas funções são criadas abaixo:
void menuDisplayWrapper() {
    menu.display();
}
void menuKeyboardWrapper(unsigned char key, int x, int y) {
    if (key == 'f' || key == 'F') {
        toggleFullscreen();
        return;
    }
    menu.handleKeypress(key, x, y);
}

// Logo após a criação do objeto menu global, deve-se registrar as funções wrapper no main:
// e para isso

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    // Solicita contexto compatível para usar pipeline fixo (glMatrixMode, stroke fonts)
    glutInitContextVersion(2, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Teste OpenGL");

    // O GLAD deve ser carregado DEPOIS do CreateWindow
    if (!gladLoadGL()) {
        std::cerr << "Erro ao iniciar GLAD" << std::endl;
        return 1; 
    }

    // REGISTROS OBRIGATÓRIOS
    glutDisplayFunc(menuDisplayWrapper);
    glutKeyboardFunc(menuKeyboardWrapper);
    glutIdleFunc(menuDisplayWrapper);

    //

    glutMainLoop();
    return 0;
}
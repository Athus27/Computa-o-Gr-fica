// Implementação do Menu com renderização em projeção ortográfica

#include <GL/freeglut.h>
#include <iostream>
#include "Menu.h"

Menu::Menu() : selectedOption(0) {}
void Menu::display() {
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, width, height);
    glClearColor(0.12f, 0.12f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Garantir estado simples para texto bitmap
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(2.5f);

    // Projeção ortográfica em coordenadas de janela (0..width, 0..height)
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, (double)width, 0.0, (double)height, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Quad de teste para validar renderização 2D
    glColor3f(0.3f, 0.3f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(width, 0);
    glVertex2i(width, height);
    glVertex2i(0, height);
    glEnd();

    // Título em branco
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_LINES);
    glVertex2i(50, height - 40);
    glVertex2i(150, height - 40);
    glEnd();

    // Desenha as opções no centro da janela
    int centerX = width / 2;
    int centerY = height / 2;
    for (int i = 0; i < 3; ++i) {
        int y = centerY + 50 - i * 60;
        drawOption(options[i], i == selectedOption, y);
    }

    // Restaura as matrizes
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glutSwapBuffers();
}
void Menu::handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
        case 'W':
            selectedOption = (selectedOption - 1 + 3) % 3;
            break;
        case 's':
        case 'S':
            selectedOption = (selectedOption + 1) % 3;
            break;
        case '\r': // Enter key
            if (selectedOption == 0) {
                startGame();
            } else if (selectedOption == 1) {
                showOptions();
            } else if (selectedOption == 2) {
                exitGame();
            }
            break;
    }
    glutPostRedisplay();
}
void Menu::drawOption(const std::string &option, bool isSelected, int yPosition) {
    // Cor do retângulo
    if (isSelected) {
        glColor3f(1.0f, 1.0f, 0.0f); // Amarelo
    } else {
        glColor3f(1.0f, 1.0f, 1.0f); // Branco
    }
    
    // Desenha retângulo centralizado
    int rectWidth = 200;
    int rectHeight = 40;
    int leftX = 400 - rectWidth / 2;
    int rightX = 400 + rectWidth / 2;
    
    glBegin(GL_QUADS);
    glVertex2i(leftX, yPosition - rectHeight / 2);
    glVertex2i(rightX, yPosition - rectHeight / 2);
    glVertex2i(rightX, yPosition + rectHeight / 2);
    glVertex2i(leftX, yPosition + rectHeight / 2);
    glEnd();
    
    // Desenha texto no centro do retângulo em preto
    glColor3f(0.1f, 0.1f, 0.1f);
    glRasterPos2i(leftX + 30, yPosition - 5);
    for (unsigned char c : option) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void Menu::startGame() {
    std::cout << "Iniciando o jogo..." << std::endl;
    // Lógica para iniciar o jogo
}

void Menu::showOptions() {
    std::cout << "Mostrando opções..." << std::endl;
    // Lógica para mostrar opções
}

void Menu::exitGame() {
    std::cout << "Saindo do jogo..." << std::endl;
    exit(0);
}

// define a classe menu.h para o menu do jogo, com 3 opções: iniciar jogo, opções e sair
// sabendo que usa c++ com opengl e freeglut




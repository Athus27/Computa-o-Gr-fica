// define a classe menu.h para o menu do jogo, com 3 opções: iniciar jogo, opções e sair
// sabendo que usa c++ com opengl e freeglut

#ifndef MENU_H
#define MENU_H
#include <string>

class Menu
{
public:
    Menu();
    void display();
    void handleKeypress(unsigned char key, int x, int y);

private:
    int selectedOption;
    const std::string options[3] = {"Start Game", "Options", "Exit"};
    void drawOption(const std::string &option, bool isSelected, int yPosition);
    void startGame();
    void showOptions();
    void exitGame();
};
#endif // MENU_H
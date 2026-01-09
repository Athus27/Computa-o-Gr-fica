
## SITES RECOMENDADOS 

### 1. **LearnOpenGL**
🔗 [https://learnopengl.com](https://learnopengl.com)

> link do repositório: github.com/JoeyDeVries/learnopengl.

Use para **conceito**, não para copiar código inteiro.
Capítulos úteis:

* Getting Started → Coordinate Systems
* Input
* Camera

⚠️ Usa GLFW, mas **os conceitos são os mesmos** do FreeGLUT.

---

###  2. **FreeGLUT – documentação**

🔗 [https://freeglut.sourceforge.net/docs/api.php](https://freeglut.sourceforge.net/docs/api.php)

 Aqui você encontra **os comandos que você realmente vai usar**:

* `glutDisplayFunc`
* `glutKeyboardFunc`
* `glutMouseFunc`
* `glutFullScreen`
* `glutGet`

---

###  3. **NeHe Productions**

🔗 [http://nehe.gamedev.net](http://nehe.gamedev.net)

👉 Tutoriais **antigos, simples e diretos**, perfeitos para:

* menus
* texto na tela
* lógica básica de jogo

📌 Muitos exemplos são **OpenGL clássico**, exatamente como sua disciplina.

---

###  4. **Lazy Foo' Productions**

🔗 [https://lazyfoo.net](https://lazyfoo.net)

👉 Não usa OpenGL puro, mas ensina:

* **menus**
* **estados de jogo**
* **entrada de teclado**
* **loop de jogo**

Você copia a **lógica**, não a API.

---

## Conceitos

Antes de qualquer código, entenda isso:

> **Seu jogo é uma MÁQUINA DE ESTADOS**

Exemplo:

```text
MENU
 ├── NEW_GAME
 ├── CONTINUE
 ├── OPTIONS
 └── EXIT
```

Você **não cria um jogo inteiro de uma vez**.
Você muda o **estado atual**.

---

##  COMANDOS NO MENU 

### Janela

```cpp
glutInitWindowSize(w, h);
glutCreateWindow("Meu Jogo");
```

Opcional:

```cpp
glutFullScreen();
```

---

###  Teclado (navegar no menu)

```cpp
void keyboard(unsigned char key, int x, int y) {
    if (key == 'w') menuIndex--;
    if (key == 's') menuIndex++;
    if (key == 13)  selectOption(); // ENTER
}

glutKeyboardFunc(keyboard);
```

---

###  Desenhar menu

```cpp
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawText("NEW GAME", x, y);
    drawText("CONTINUE", x, y-40);
    drawText("OPTIONS", x, y-80);
    drawText("EXIT", x, y-120);

    glFlush();
}
```

Texto simples:

```cpp
void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
```

---

## 🧩 ESTRUTURA MÍNIMA DO SEU JOGO

Guarde isso, é **padrão acadêmico**:

```cpp
enum GameState {
    MENU,
    PLAYING,
    OPTIONS,
    EXIT
};

GameState currentState = MENU;
```

No `display()`:

```cpp
if (currentState == MENU) drawMenu();
if (currentState == PLAYING) drawGame();
```



---

##  PRIMEIRO OBJETIVO

Não pensar em jogo ainda, temos q fazer o básico

 - [ ] Abrir janela
 - [ ] Mostrar texto do menu
 - [ ] Mudar opção com teclado
 - [ ] Apertar ENTER e mudar estado

Quando isso funcionar, **o resto é extensão**.

---

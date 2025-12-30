> **extensão de C com recursos extras**, especialmente **POO**, mais abstrações e biblioteca padrão maior, a **principal diferença é entre a sintaxe moderna** e na conveniência da biblioteca padrão**(iostream, std::string, std::vector etc)**

# I/O

## Sobrecargas (<<&>>)
Operadores de sobrecarga(overload) dos operadores de deslocamento de bits que tem c, na biblioteca `iostrem` eles ganham um segundo significado
### <<     <- enviar para o stream
```cpp
std::cout << x; //envie x para cout
//esse é o printf, é montado como Console Output =cout

std::cout << "Resultado: " << x << "\n";
// nesse caso é redefinido para concatenar valores no fluxo
```

### >>     <- ler do stream
```cpp
std::cin >> x; // leia para x a partir do cin


//exemplo de pedido de entrada
std::cout << "Digite um número: ";
std::cin >> x;


```

-  C++ permite sobrecarga de operadores.
- A declaração é como em C, com o acréscimo que tem a dedução, como por exemplo:
```cpp
auto x = 10; //deduz  int
```
- Em C++ tem o código em booleano
- Strings por meio de biblioteca `string`
```cpp
#include <string>
std::string nome = "Athus";
```
- Em C++ as funções são praticamente iguais a de c, porém permite **sobrecarga(Mesma função, mesmo nome, mas parâmetros diferentes.)**
```cpp
int soma(int a, int b);
float soma(float x, float y);
```
 - Namespaces
 ```cpp
 std::cout << "Oi"; 
 //ou 
 using namespace std
 ```
 
  
  ### New/Delete vs malloc/free
   #### C
```c
int* v = malloc(sizeof(int) * 10);
free(v);

```

#### C++
```cpp
int* v = new int[10]
delete[]v;
```
>Hoje o estilo moderno usa std::vector (evitar new/delete).

# Classes

```cpp
class Pessoa {
public:
	int idade;
}
```

# OpenGL + GLUT/FreeGLUT
>usa da mesma forma que se usa em c
>
```cpp
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // desenhar aqui
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Janela OpenGL");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

```
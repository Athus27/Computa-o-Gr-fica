# Computação Gráfica – OpenGL + FreeGLUT (C++)

Este projeto utiliza **C++ com OpenGL e FreeGLUT**, compilado com **g++ (MinGW)** no Windows e executado via terminal ou VS Code.

---

## 📁 Estrutura do Projeto

```

Computa-o-Gr-fica/
├─ src/
│  └─ main.cpp          # Código principal
├─ deps/
│  └─ freeglut/         # FreeGLUT (include, lib, bin)
├─ build/
│  └─ app.exe           # Executável gerado
└─ README.md

````

---

## ⚙️ Pré-requisitos

- Windows
- MinGW (g++)
- FreeGLUT (fornecido pela professora, dentro de `deps/freeglut`)

---

## ▶️ Como compilar

Abra o **PowerShell** na raiz do projeto (`Computa-o-Gr-fica`) e execute:

```powershell
g++ .\src\main.cpp -o .\build\app.exe `
  -I .\deps\freeglut\include `
  -L .\deps\freeglut\lib `
  -lfreeglut -lopengl32 -lglu32 -lgdi32 -lwinmm
````

---

## ▶️ Como executar

Antes de executar, garanta que a DLL esteja no diretório `build`:

```powershell
copy .\deps\freeglut\bin\freeglut.dll .\build\
```

Depois, execute:

```powershell
.\build\app.exe
```

---
## 📝 Observações

* O `#include <GL/freeglut.h>` funciona porque o caminho é informado com `-I`.
* A pasta `build` é usada apenas para execução.
* Alterações no código devem ser feitas em `src/main.cpp`.

---

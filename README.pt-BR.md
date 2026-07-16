# Navigation Screen Game

Uma biblioteca leve em **C++20** para gerenciamento de navegação entre telas de jogos utilizando um sistema baseado em pilha (*stack*).

---

# Runtime da Biblioteca
Esta biblioteca atualmente é compilada utilizando o Runtime estático do Microsoft Visual C++:

| Configuração | Runtime |
|---|---|
| Debug | `/MTd` |
| Release | `/MTd` |

Projetos que utilizarem esta biblioteca devem utilizar a mesma configuração de runtime.

Misturar diferentes runtimes pode causar erros de linkedição, por exemplo:

- `/MT` com `/MD`
- `/MTd` com `/MDd` não são recomendados.
___
# Sobre

Muitos desenvolvedores C++ criam jogos sem utilizar uma engine completa.

Bibliotecas como:

- Raylib
- Allegro
- SDL
- Outros frameworks multimídia

fornecem excelentes recursos para:

- Renderização.
- Áudio.
- Entrada de usuário.
- Manipulação gráfica.

Porém, normalmente essas bibliotecas não possuem um sistema próprio para gerenciamento de telas e estados do jogo.

Conforme o projeto cresce, é comum surgirem grandes estruturas com `switch`, várias variáveis de estado e lógica difícil de manter para controlar:

- Menu principal.
- Tela de jogo.
- Menu de pausa.
- Configurações.
- Tela de Game Over.
- Telas de carregamento.

O **Navigation Screen Game** surgiu para resolver esse problema.

A biblioteca utiliza uma **pilha de telas (screen stack)** para organizar e controlar a navegação entre diferentes partes do jogo.

---

# Recursos

- Sistema simples de navegação entre telas.
- Gerenciamento utilizando pilha (*stack*).
- Design orientado a objetos.
- Fácil integração com projetos C++ existentes.
- Compatível com:
  - Raylib.
  - Allegro.
  - SDL.
  - Sistemas próprios de renderização.
- Desenvolvido utilizando C++20.

---

# Estrutura do Projeto

Estrutura atual:

```
NavigationPage/
        
├── CMakeLists.txt
├── Navigator.cpp
├── Navigator.h
├── Screen.cpp
├── Screen.h
├── NavigationPage.vcxproj
├── NavigationPage.slnx

└── x64/
    ├── Debug/
    └── Release/
```

---

# Como Funciona

## Screen

`Screen` é a classe base que deve ser herdada pelas telas do jogo.

Cada tela criada pelo desenvolvedor deve herdar dessa classe.

Exemplo:

```cpp
#include "Screen.h"

class MenuScreen : public Screen
{
public:

    void Update() override;
    void Draw() override;

};
```

Uma tela pode representar:

- Menu principal.
- Gameplay.
- Pausa.
- Configurações.
- Créditos.
- Tela de carregamento.

A renderização fica totalmente sob responsabilidade do projeto.

Você pode utilizar:

- Raylib.
- Allegro.
- SDL.
- OpenGL.
- Qualquer sistema próprio de renderização.

---

# Navigator

`Navigator` é responsável por controlar a pilha de telas.

Ele não herda de nenhuma classe.

O desenvolvedor cria suas próprias telas e utiliza o `Navigator` para controlar a navegação entre elas.

Exemplo conceitual:

```
Pilha de Telas

+----------------+
| Tela de Jogo   |
+----------------+
| Tela de Pausa  |
+----------------+
| Menu Principal |
+----------------+

        |
        v

     Navigator
```

O sistema permite:

- Adicionar novas telas.
- Remover telas.
- Retornar para telas anteriores.
- Controlar estados sem grandes estruturas condicionais.

---

# O que o Navigation Screen Game NÃO faz

Esta biblioteca é responsável apenas pelo gerenciamento de telas.

Ela **não possui**:

- Sistema de renderização.
- Motor de física.
- Detecção de colisão.
- Sistema de áudio.
- Gerenciamento de entrada.
- Gerenciamento de recursos.

Esses sistemas devem ser implementados pelo seu projeto ou por outras bibliotecas.

Exemplo:

```
Raylib / Allegro / SDL

          |
          |
          v

Navigation Screen Game

          |
          |
          v

Suas Telas do Jogo
```

---

# Requisitos
  - CMake 3.20 ou superior
## Compilador

Necessário:

- Compilador compatível com C++20.

Compiladores suportados:

- Microsoft Visual C++ (Visual Studio 2022 ou superior).
- GCC.
- Clang.

## Sistemas Operacionais

Compatível com:

- Windows.
- Linux.
- MacOS.

---

# Instalação

# Windows - Visual Studio

Clone o repositório:

```bash
git clone https://github.com/YOUR_USERNAME/NavigationPage.git
```

Abra:

```
NavigationPage.slnx
```

no Visual Studio.

Compile:

```
Build > Build Solution
```

A biblioteca será gerada:

Debug:

```
x64/Debug/NavigationPage.lib
```

Release:

```
x64/Release/NavigationPage.lib
```

---

# Windows - Visual Studio Code

Requisitos:

- Visual Studio Code.
- Extensão C++.
- CMake.
- Compilador MSVC ou MinGW.

Compile:

```bash
mkdir build
cd build

cmake ..

cmake --build .
```

---

# Linux - Visual Studio Code

Instale as dependências:

Ubuntu:

```bash
sudo apt update

sudo apt install build-essential cmake
```

Clone:

```bash
git clone https://github.com/YOUR_USERNAME/NavigationPage.git
```

Compile:

```bash
mkdir build
cd build

cmake ..

cmake --build .
```

---

# Linux - CLion

1. Abra o CLion.
2. Escolha:

```
File > Open
```

3. Selecione a pasta do projeto.

O CLion irá detectar automaticamente o projeto.

Compile:

```
Build > Build Project
```

---

# Utilização

Um projeto pode organizar suas telas assim:

```
Screens/

├── MenuScreen.cpp
├── MenuScreen.h

├── GameScreen.cpp
├── GameScreen.h

├── PauseScreen.cpp
└── PauseScreen.h
```

Cada tela herda de:

```cpp
Screen
```

O `Navigator` controla qual tela está ativa.

---

# Por que o Navigation Screen Game foi criado?

Muitos desenvolvedores independentes utilizam:

- Raylib.
- Allegro.
- SDL.

Essas bibliotecas são excelentes ferramentas para criação de jogos, porém deixam o gerenciamento de telas sob responsabilidade do desenvolvedor.

Sem um sistema de navegação, muitos projetos acabam utilizando:

```cpp
switch(gameState)
{
    case MENU:
        break;

    case GAME:
        break;

    case PAUSE:
        break;

    case OPTIONS:
        break;
}
```

Conforme o jogo cresce, esse modelo se torna difícil de manter.

O Navigation Screen Game fornece uma solução mais organizada utilizando:

- Programação orientada a objetos.
- Herança de telas.
- Navegação baseada em pilha.

---

# Exemplos futuros

Exemplos de projetos estarão disponíveis em breve:

- Pong.
- Space Invaders.

---

# Autor

**Mateus Mendes de Freitas**

---

# Licença

Este projeto está licenciado sob:

**GNU General Public License v3.0**

Consulte o arquivo LICENSE para mais informações.
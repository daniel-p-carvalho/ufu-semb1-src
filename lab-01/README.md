# Lab 01 — Validação do Ambiente e Ferramentas

Este laboratório contém o firmware de teste (*Blinky*) para validar a cadeia completa de desenvolvimento na placa **STM32F411 Blackpill**: compilador cruzado (`arm-none-eabi-gcc`), utilitário de gravação (`st-flash`), servidor de depuração (`openocd`) e integração com o Visual Studio Code (extensão *Cortex-Debug*).

---

## 1. Estrutura de Arquivos

* `src/main.c`: Código em C que inicializa o clock do GPIO porta C e alterna o nível lógico do pino PC13 (LED azul da placa).
* `src/startup.c`: Tabela de vetores de interrupção e tratador de reset (*Reset Handler*) para a arquitetura Cortex-M4.
* `stm32f411-rom.ld`: *Linker script* que define o mapa de memória (Flash de 512 KB em `0x08000000`, SRAM de 128 KB em `0x20000000`).
* `Makefile`: Automação da compilação e alvos de gravação e depuração.
* `.vscode/`: Configurações pré-definidas para o VS Code (`launch.json`, `tasks.json`, `c_cpp_properties.json`).

---

## 2. Como Compilar e Gravar pelo Terminal

No terminal, dentro desta pasta:

```bash
# Limpar artefatos anteriores e compilar
make clean
make

# Gravar na placa via ST-LINK (com a placa conectada via USB)
make flash
```

Ao final da gravação, o LED da placa começará a piscar com período aproximado de 1 segundo.

---

## 3. Como Depurar no VS Code

1. Abra esta pasta no VS Code: **File → Open Folder** e selecione `lab-01`.
2. Abra o arquivo `src/main.c`.
3. Insira *breakpoints* clicando à esquerda dos números das linhas que escrevem em `*gpioc_bsrr` (dentro do laço `while (1)`).
4. Pressione **F5** para iniciar a depuração.
5. Utilize **F5** (*Continue*) e **F10** (*Step Over*) para avançar o programa passo a passo e observar o LED acender e apagar sob o controle do depurador.

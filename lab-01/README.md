# Lab 01 — Validação do Ambiente e Ferramentas

Este laboratório contém o firmware de teste (*blinky*) para validar a cadeia completa de desenvolvimento: compilador cruzado (`arm-none-eabi-gcc`), utilitário de gravação (`st-flash`), servidor de depuração (`openocd`) e integração com o Visual Studio Code (extensão *Cortex-Debug*).

O código é fornecido pronto: nesta etapa ele é uma caixa-preta, e cada parte dele será estudada ao longo da disciplina.

---

## 1. Placas

Cada placa tem a sua pasta. A placa oficial da disciplina, usada em todo o texto da apostila, é a **STM32F411 Blackpill**.

| Pasta | Placa | Flash / SRAM | LED | Gravador | Situação |
|---|---|---|---|---|---|
| [`stm32f411-blackpill/`](./stm32f411-blackpill) | WeAct Blackpill STM32F411CEU6 | 512 KB / 128 KB | PC13, acende em nível baixo | ST-LINK externo | Disponível |
| `stm32f401-blackpill/` | WeAct Blackpill STM32F401CCU6 ou CEU6 | 256 KB / 64 KB (CC) ou 512 KB / 96 KB (CE) | PC13, acende em nível baixo | ST-LINK externo | Planejada |
| `nucleo-f411re/` | ST Nucleo-F411RE | 512 KB / 128 KB | PA5 (LD2), acende em nível alto | ST-LINK/V2-1 embutido | Planejada |

---

## 2. Estrutura de Arquivos (`stm32f411-blackpill/`)

* `src/main.c`: habilita o clock da porta C do GPIO e alterna o nível lógico do pino PC13 (LED azul da placa).
* `src/startup.c`: tabela de vetores de interrupção e tratador de reset (*reset handler*) para o Cortex-M4.
* `stm32f411-rom.ld`: *linker script* com o mapa de memória (Flash de 512 KB em `0x08000000`, SRAM de 128 KB em `0x20000000`).
* `Makefile`: compilação e alvos de gravação (`flash`) e depuração (`openocd`, `debug`).
* `.vscode/`: configuração pronta do VS Code (`launch.json`, `tasks.json`, `c_cpp_properties.json`). Este é o único laboratório que traz a própria `.vscode/`, para que a validação do ambiente funcione sem nenhum ajuste. Nos demais, use os modelos genéricos de [`tools/vscode/`](../tools/vscode).

---

## 3. Como Compilar e Gravar pelo Terminal

Dentro da pasta da placa:

```bash
cd ~/semb1-workspace/ufu-semb1-src/lab-01/stm32f411-blackpill

# Limpar artefatos anteriores e compilar
make clean
make

# Gravar na placa via ST-LINK (com a placa conectada)
make flash
```

Ao final da gravação, o LED da placa começa a piscar com período aproximado de 1 segundo.

---

## 4. Como Depurar no VS Code

1. Abra a pasta **da placa** no VS Code: **File → Open Folder** e selecione `lab-01/stm32f411-blackpill`. Tem de ser essa pasta, e não `lab-01`: é nela que estão a `.vscode/` e o `blinky.elf`.
2. Abra o arquivo `src/main.c`.
3. Insira *breakpoints* clicando à esquerda dos números das linhas que escrevem em `*gpioc_bsrr` (dentro do laço `while (1)`).
4. Pressione **F5** para iniciar a depuração.
5. Use **F5** (*Continue*) e **F10** (*Step Over*) para avançar o programa passo a passo e observar o LED acender e apagar sob o controle do depurador.

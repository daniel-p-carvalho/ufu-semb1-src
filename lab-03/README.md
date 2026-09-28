# Lab 03 — `g_a + g_b` em Bare-Metal

Nesta aula, o programa `embedded.c` da aula anterior roda na placa sem sistema operacional, sem biblioteca C e sem *runtime* prontos. As duas peças que faltam, o **código de inicialização** (`startup.c`) e o ***linker script*** (`stm32f411-rom.ld`), são escritas por você, do zero, seguindo a apostila. O resultado é conferido no depurador: `g_a` vale 10 e `g_b` vale 0 quando o `main()` começa.

Esta pasta contém o **ponto de partida** da aula: só a aplicação. O `startup.c` e o *linker script* prontos aparecem na pasta do `lab-04`, que começa onde esta aula termina.

---

## 1. Placas

A placa oficial da disciplina, usada em todo o texto da apostila, é a **STM32F411 Blackpill**.

| Pasta | Placa | Flash | SRAM | Topo da pilha (`STACK_START`) | Situação |
|---|---|---|---|---|---|
| [`stm32f411-blackpill/`](./stm32f411-blackpill) | WeAct Blackpill STM32F411CEU6 | 512 KB em `0x08000000` | 128 KB em `0x20000000` | `0x20020000` | Disponível |
| `stm32f401-blackpill/` | WeAct Blackpill STM32F401CCU6 ou CEU6 | 256 KB (CC) ou 512 KB (CE) | 64 KB (CC) ou 96 KB (CE) | `0x20010000` (CC) ou `0x20018000` (CE) | Planejada |
| `nucleo-f411re/` | ST Nucleo-F411RE | 512 KB | 128 KB | `0x20020000` | Planejada |

Para outra placa, o que muda nesta aula são o tamanho da SRAM no `startup.c` (e, com ele, o topo da pilha) e os valores de `LENGTH` no bloco `MEMORY` do *linker script*. O programa não usa nenhum periférico, então o resto é igual.

---

## 2. Arquivos

* `stm32f411-blackpill/embedded.c`: a aplicação, idêntica à do `lab-02`. Soma `g_a` e `g_b`, guarda o resultado em `g_c` e fica em um laço infinito.

Você vai criar, na mesma pasta:

* `startup.c`: tabela de vetores (`g_vectors`, na seção `.isr_vectors`) e tratador de reset (`reset_handler`), que copia a `.data` da Flash para a SRAM, zera a `.bss` e chama o `main()`.
* `stm32f411-rom.ld`: blocos `MEMORY` e `SECTIONS`, com a `.data` gravada na Flash e copiada para a SRAM (`> SRAM AT> FLASH`) e os símbolos `_sdata`, `_edata`, `_la_data`, `_sbss` e `_ebss`.

---

## 3. Como Começar

```bash
cp -r ~/semb1-workspace/ufu-semb1-src/lab-03/stm32f411-blackpill ~/semb1-workspace/bare-metal
cd ~/semb1-workspace/bare-metal
```

## 4. Compilação, Ligação e Gravação (à mão, sem `Makefile`)

```bash
arm-none-eabi-gcc -c -g -mcpu=cortex-m4 -mthumb -O0 -Wall startup.c -o startup.o
arm-none-eabi-gcc -c -g -mcpu=cortex-m4 -mthumb -O0 -Wall embedded.c -o embedded.o
arm-none-eabi-gcc -nostdlib -T stm32f411-rom.ld -Wl,-Map=embedded.map -Wl,--print-memory-usage startup.o embedded.o -o embedded.elf
arm-none-eabi-objcopy -O binary embedded.elf embedded.bin

# Conferência antes de gravar
arm-none-eabi-nm -n embedded.elf
arm-none-eabi-objdump -h embedded.elf
od -A x -t x4 -N 8 embedded.bin      # deve mostrar 20020000 08000041

# Gravação
st-flash --reset write embedded.bin 0x08000000
```

## 5. Conferência no Depurador

Em um terminal:

```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
```

Em outro, na pasta do projeto:

```text
arm-none-eabi-gdb embedded.elf
(gdb) target extended-remote localhost:3333
(gdb) monitor reset halt
(gdb) monitor mww 0x20000000 0xdeadbeef 3
(gdb) x/3xw 0x20000000
(gdb) break main
(gdb) continue
(gdb) x/3xw 0x20000000
(gdb) print g_a
(gdb) print g_b
(gdb) next
(gdb) print g_c
```

`g_a` deve valer 10 e `g_b` e `g_c` devem valer 0 ao chegar ao `main()`; depois do `next`, `g_c` vale 10.

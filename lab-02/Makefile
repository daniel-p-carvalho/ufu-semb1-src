# Makefile para o Lab 02 — Do C ao Binário
# Sistemas Embarcados I - FEELT/UFU

CC_NATIVE ?= gcc
CC_ARM    ?= arm-none-eabi-gcc
OBJDUMP   ?= arm-none-eabi-objdump
NM        ?= arm-none-eabi-nm

CFLAGS_NATIVE ?= -Wall -Wextra -g
CFLAGS_ARM    ?= -mcpu=cortex-m4 -mthumb -Wall -Wextra -g

.PHONY: all clean preprocess asm-x86 asm-arm disasm-arm nm-arm

all: program embedded.o cosine

# 1. Compilação nativa (PC x86-64)
program: program.c
	$(CC_NATIVE) $(CFLAGS_NATIVE) $< -o $@

# 2. Compilação para ARM Cortex-M4 (parando no arquivo objeto .o)
embedded.o: embedded.c
	$(CC_ARM) -c $(CFLAGS_ARM) $< -o $@

# 3. Exemplo da atividade para casa com libm (-lm)
cosine: cosine.c
	$(CC_NATIVE) $(CFLAGS_NATIVE) $< -o $@ -lm

# 4. Alvos didáticos para dissecação do pipeline de compilação
preprocess: program.c
	$(CC_NATIVE) -E $< -o program.i

asm-x86: program.c
	$(CC_NATIVE) -S $(CFLAGS_NATIVE) $< -o program-x86.s

asm-arm: embedded.c program.c
	$(CC_ARM) -S $(CFLAGS_ARM) embedded.c -o embedded-arm.s
	$(CC_ARM) -S $(CFLAGS_ARM) program.c -o program-arm.s

disasm-arm: embedded.o
	$(OBJDUMP) -d $<

nm-arm: embedded.o
	$(NM) $<

clean:
	rm -f program program-static no-crt cosine
	rm -f program.i program.s program.o
	rm -f program-x86.s program-arm.s embedded-arm.s
	rm -f embedded.o embedded.elf

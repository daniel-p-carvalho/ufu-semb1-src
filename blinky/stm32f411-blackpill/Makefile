# Nome do programa

PROGNAME := blinky

# Ferramentas do toolchain

CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
CP = arm-none-eabi-objcopy
GDB = arm-none-eabi-gdb
RM = rm -rf

# Diretorios arquivos objeto e de lista de dependencias serao salvos

OBJDIR = build
DEPDIR = .deps

# Arquivos a serem compilados

SRCS = src/startup.c \
       src/main.c

#Flags do compilador

CFLAGS = -g -mcpu=cortex-m4 -mthumb -Wall -O0
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d
LFLAGS = -nostdlib -T stm32f411-rom.ld -Wl,-Map=blinky.map

# Gera lista de arquivos objeto e cria diretorio onde serao salvos

OBJS = $(patsubst %, $(OBJDIR)/%.o, $(basename $(SRCS)))
$(shell mkdir -p $(dir $(OBJS)) > /dev/null)

# Gera lista de arquivos de lista dependencia e cria diretorio onde serao salvos

DEPS = $(patsubst %, $(DEPDIR)/%.d, $(basename $(SRCS)))
$(shell mkdir -p $(dir $(DEPS)) > /dev/null)

all: $(OBJS) $(PROGNAME).elf $(PROGNAME).bin

$(PROGNAME).elf: $(OBJS)
	$(LD) $(LFLAGS) -o $@ $^

$(PROGNAME).bin: $(PROGNAME).elf
	$(CP) -O binary $^ $@

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d
	$(CC) -c $(CFLAGS) $(DEPFLAGS) $< -o $@

# Cria um novo target para cada arquivo de dependencia possivel

$(DEPS):

# Inclui conteudo dos arquivos de dependencia

-include $(DEPS)

# Gravacao e depuracao (ST-LINK)

OPENOCD_CFG = -f interface/stlink.cfg -f target/stm32f4x.cfg

.PHONY: flash openocd debug

# Grava o binario na FLASH (inicio em 0x08000000) e reinicia o chip
flash: $(PROGNAME).bin
	st-flash --reset write $(PROGNAME).bin 0x08000000

# Inicia o servidor OpenOCD (deixe rodando em um terminal separado)
openocd:
	openocd $(OPENOCD_CFG)

# Conecta o GDB ao OpenOCD (porta 3333) e para o processador no reset
debug: $(PROGNAME).elf
	$(GDB) $(PROGNAME).elf -ex "target extended-remote localhost:3333" -ex "monitor reset halt"

.PHONY: clean
clean:
	$(RM) $(OBJDIR) $(DEPDIR)
	$(RM) $(PROGNAME).elf $(PROGNAME).bin $(PROGNAME).map
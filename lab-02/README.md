# Lab 02 — Do C ao Binário

Laboratório prático da Semana 2 da disciplina de Sistemas Embarcados I (FEELT/UFU).

Este laboratório disseca as quatro etapas do pipeline de compilação C (`gcc`), comparando a compilação nativa no PC (x86-64) com a compilação cruzada para o ARM Cortex-M4 (`arm-none-eabi-gcc`), além de examinar a regra RISC Load-Store, a convenção binária AAPCS e a estrutura de seções ELF.

**Nota:** Este laboratório é puramente de análise de software e ferramentas. Não requer conexão com a placa de desenvolvimento física.

---

## Arquivos do Laboratório

* `program.c`: Código em C com variáveis globais inicializadas e não-inicializadas (`g_a`, `g_b`), função `add()` e chamada a `printf()`.
* `embedded.c`: Versão adaptada para microcontrolador (sem biblioteca C e com laço `while (1)`), pronta para compilação cruzada com `arm-none-eabi-gcc`.
* `cosine.c`: Exemplo para demonstrar a etapa de ligação manual com bibliotecas (`-lm`).
* `Makefile`: Automação com alvos didáticos para gerar os arquivos intermediários (`.i`, `.s`, `.o`).

---

## Comandos Principais

### Compilação padrão
```console
# Compila tudo (executavel nativo program, objeto ARM embedded.o e cosine)
make

# Executa o programa nativo
./program
```

### Dissecando as etapas intermediárias
```console
# 1. Pré-processamento (gera program.i)
make preprocess
wc -l program.c program.i

# 2. Compilação para Assembly x86-64 (gera program-x86.s)
make asm-x86

# 3. Compilação para Assembly ARM Cortex-M4 (gera program-arm.s e embedded-arm.s)
make asm-arm

# 4. Tabela de símbolos do objeto ARM
make nm-arm

# 5. Desmontagem (desassembly) do objeto ARM
make disasm-arm

# Limpeza
make clean
```

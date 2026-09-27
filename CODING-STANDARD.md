# Padrão de Codificação

Este documento define o padrão de codificação do código C deste repositório. Todo código novo ou modificado deve segui-lo.

O código daqui é **material didático**: estudantes vão lê-lo, copiá-lo e modificá-lo, e a apostila cita trechos dele. Por isso, quando uma regra deste documento entrar em conflito com a clareza, prefira o código que um estudante entende na primeira leitura. Código "esperto" (macros encadeadas, aritmética de ponteiros compacta, truques de precedência) não tem lugar aqui.

---

## 1. Diretrizes gerais

1. **Largura de linha**: nenhuma linha de código ou comentário ultrapassa a coluna **78**.
2. **Codificação e fim de linha**: arquivos em UTF-8, com fim de linha Unix (LF) e exatamente uma quebra de linha ao final do arquivo.
3. **Sem comentários `//`**: use sempre `/* ... */` (ou `/** ... */` para Doxygen).
4. **Sem TAB em `.c`, `.h` e `.ld`**: indente com espaços. A exceção é o `Makefile`, cujas receitas **exigem** TAB.
5. **Sem parênteses desnecessários** em retornos e atribuições simples: `return valor;`, e não `return (valor);`.
6. **Idioma**:
   - **Identificadores em inglês**, seguindo a nomenclatura dos manuais de referência (`RCC`, `GPIO`, `MODER`, `reset_handler`). Assim o estudante encontra no *Reference Manual* exatamente o nome que lê no código.
   - **Comentários em português**, com acentuação, pois são escritos para os estudantes.
7. **Conteúdo dos comentários**: um comentário explica o **porquê** ou o que não é óbvio no código atual — uma decisão, um limite, a seção do manual que justifica um valor. Não descreve a mudança que o produziu ("corrigido X", "antes era Y"); para isso existe o histórico do git.

---

## 2. Indentação e chaves

1. **Indentação de 2 espaços** por nível.
2. **Chaves sempre em linha própria**, sem comentários na mesma linha.
   - **Funções**: chaves na coluna 0; o corpo é indentado em 2 espaços.
   - **Blocos de controle** (`if`, `else`, `for`, `while`, `switch`, `do`): chaves indentadas em 2 espaços em relação à instrução, e o conteúdo do bloco em mais 2.
   - **Inicializadores de vetores e estruturas**: chaves na mesma coluna da declaração.
3. **Espaço após palavra-chave**: `if (`, `for (`, `while (`, `switch (`. Chamadas de função não têm espaço antes do parêntese: `main()`.
4. **Laços infinitos** usam `while (1)`.
5. **Laços de corpo vazio** usam um bloco vazio explícito, e não um `;` solto no fim da linha, que é fácil de não ver.

```c
void example_function(void)
{
  if (condition)
    {
      do_a();
    }
  else
    {
      do_b();
    }

  for (i = 0; i < LED_DELAY; i++)
    {
    }
}
```

---

## 3. Comentários

1. Comentários começam com letra maiúscula e terminam com ponto final.
2. Um comentário em linha própria é precedido por **uma linha em branco**, exceto logo após uma chave de abertura `{`.
3. Comentários à direita do código são curtos e, quando adjacentes, alinhados na mesma coluna.
4. Membros de estruturas e uniões são documentados com o comentário Doxygen pós-membro `/**< ... */`.

```c
#define SRAM_START  0x20000000U           /* Início da SRAM. */
#define SRAM_SIZE   (128U * 1024U)        /* 128 KB no STM32F411. */

struct led_s
{
  uint32_t port;  /**< Endereço base do GPIO do LED. */
  uint8_t  pin;   /**< Número do pino (0 a 15). */
};
```

---

## 4. Estrutura dos arquivos

### 4.1 Cabeçalho de arquivo

Todo arquivo `.c` e `.h` começa com o cabeçalho abaixo, em sintaxe Doxygen. A licença é indicada pelo identificador SPDX, sem repetir o texto da licença (que está em [`LICENSE`](LICENSE)):

```c
/**
 * @file main.c
 * @brief Descrição curta e objetiva do propósito do arquivo.
 *
 * @author Daniel P. Carvalho <daniel.carvalho@ufu.br>
 * @date 2021
 *
 * @copyright Copyright (c) 2021 Daniel P. Carvalho.
 * SPDX-License-Identifier: MIT
 */
```

`@date` é o ano de criação do arquivo.

### 4.2 Seções de um arquivo `.c`

As seções são demarcadas por divisores de linha única com exatamente 78 colunas, nesta ordem. Seções vazias são omitidas:

```c
/* --- Included Files ----------------------------------------------------- */

/* --- Pre-processor Definitions ------------------------------------------ */

/* --- Private Types ------------------------------------------------------ */

/* --- Function Prototypes ------------------------------------------------ */

/* --- External Data ------------------------------------------------------ */

/* --- Private Data ------------------------------------------------------- */

/* --- Public Data -------------------------------------------------------- */

/* --- Private Functions -------------------------------------------------- */

/* --- Public Functions --------------------------------------------------- */
```

*Function Prototypes* reúne os protótipos de funções usadas antes de sua definição (no `startup.c`, os tratadores de exceção referenciados pela tabela de vetores). *External Data* reúne as declarações `extern`, como os símbolos exportados pelo *linker script* (`_sdata`, `_ebss` etc.).

### 4.3 Seções de um arquivo `.h`

1. Included Files
2. Pre-processor Definitions
3. Public Types
4. Public Data (declarações `extern`)
5. Inline Functions
6. Public Function Prototypes

### 4.4 *Header guards*

Todo `.h` tem uma guarda de inclusão com o caminho do arquivo a partir da pasta da placa, em maiúsculas, com `/`, `.` e `-` trocados por `_`. **Nunca** comece o nome com `_` ou `__`: esses identificadores são reservados ao compilador e à biblioteca C (C99 §7.1.3).

```c
#ifndef SRC_GPIO_H
#define SRC_GPIO_H

/* Conteúdo do cabeçalho. */

#endif /* SRC_GPIO_H */
```

### 4.5 Documentação de funções

Funções públicas são documentadas acima do protótipo no `.h`; funções privadas e tratadores de exceção, acima da definição no `.c`:

```c
/**
 * @brief Descrição curta do que a função faz.
 *
 * Detalhes opcionais: restrições de uso, efeitos colaterais,
 * referência à seção do manual.
 *
 * @param led Descrição do parâmetro.
 *
 * @return Descrição do valor retornado.
 */
```

Para funções `void` sem parâmetros, basta o `@brief` e, se necessário, os detalhes.

---

## 5. Nomenclatura

1. **Funções e variáveis**: `snake_case` minúsculo. Não use *camelCase*, *PascalCase* nem notação húngara (`pDst`, `iCount`).
2. **Funções públicas** de um módulo são prefixadas com o nome do módulo: `gpio_set_mode()`. Funções privadas são `static`.
3. **Variáveis globais** têm o prefixo `g_`: `g_vectors`.
4. **Macros e constantes**: `SNAKE_CASE` maiúsculo.
5. **Estruturas e uniões**: sem `typedef`; a *tag* termina em `_s` (estrutura) ou `_u` (união), e as variáveis são declaradas com o tipo completo: `struct led_s led;`.
6. **Registradores de periféricos** seguem o padrão abaixo, com os nomes exatamente como no *Reference Manual*:

| Tipo de macro | Padrão | Exemplo |
| --- | --- | --- |
| Endereço base do periférico | `STM32_<PERIF>_BASE` | `STM32_GPIOC_BASE` |
| Offset do registrador | `STM32_<PERIF>_<REG>_OFFSET` | `STM32_GPIO_MODER_OFFSET` |
| Endereço do registrador | `STM32_<PERIF>_<REG>` | `STM32_GPIOC_MODER` |
| Campo ou bit do registrador | `<PERIF>_<REG>_<CAMPO>` | `RCC_AHB1ENR_GPIOCEN` |

---

## 6. Pré-processador

1. O `#` fica sempre na coluna 0. Diretivas aninhadas em blocos condicionais recebem 2 espaços **após** o `#` por nível: `#  define`.
2. **Includes**, em grupos separados por uma linha em branco, cada um em ordem alfabética:
   1. o cabeçalho do próprio arquivo (`gpio.c` → `"gpio.h"`), sozinho;
   2. cabeçalhos do sistema, com `< >`;
   3. cabeçalhos do projeto, com `" "`.
3. **Macros com parâmetros**: cada parâmetro e a expressão inteira ficam entre parênteses: `#define GPIO_MODER_SHIFT(n) ((n) << 1)`.
4. **Constantes sem sinal** levam o sufixo `U` (`0x40023800U`, `1U << 2`). Deslocar um `1` com sinal até o bit 31 é comportamento indefinido em C.
5. `#endif` e `#else` de *header guards* ou de blocos com mais de 10 linhas levam um comentário com a condição: `#endif /* SRC_GPIO_H */`.

---

## 7. Regras de sistemas embarcados

1. **Tipos de largura fixa** (`uint8_t`, `uint16_t`, `uint32_t`, de `<stdint.h>`) para registradores, endereços e dados de tamanho definido. Use `int` apenas quando o tamanho realmente não importar.
2. **Todo acesso a registrador de periférico é `volatile`**. Sem `volatile`, o compilador pode eliminar ou reordenar leituras e escritas que ele julga redundantes, e o programa passa a funcionar só com `-O0`.
3. **Laços de atraso por contagem** usam um contador `volatile`, pelo mesmo motivo: com otimização, um laço vazio sobre uma variável comum é simplesmente removido.
4. **Sem HAL nem CMSIS**: os registradores são definidos no próprio projeto, a partir do *Reference Manual*, com o padrão de nomes da Seção 5.
5. **Alterações de registrador** que não devem afetar os outros bits seguem o padrão *leitura-modificação-escrita* em três passos explícitos (ler para uma variável, limpar a máscara e aplicar o novo valor, escrever de volta). É mais longo que um `|=` em uma linha, mas mostra ao estudante o que o processador realmente faz.
6. **Assinatura do `main()`**: `int main(void)`. Em *bare-metal* não há sistema operacional para passar `argc`/`argv`, nem para receber o valor de retorno.

---

## 8. Código citado pela apostila

A apostila ([ufu-embedded-systems](https://github.com/daniel-p-carvalho/ufu-embedded-systems)) cita arquivos deste repositório pelo caminho, pelos nomes de identificadores e, em alguns roteiros, pelo **número da linha** (por exemplo, `break main.c:135` na validação do ambiente). Ao alterar um arquivo, procure na apostila as referências a ele e atualize as que mudaram.

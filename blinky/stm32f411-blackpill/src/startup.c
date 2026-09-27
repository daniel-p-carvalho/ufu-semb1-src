/**
 * @file startup.c
 * @brief Tabela de vetores e tratador de Reset do STM32F411.
 *
 * Prepara a memória para o programa C (copia a .data e zera a .bss) e
 * chama main(). Os limites das seções vêm do linker script.
 *
 * @author Daniel P. Carvalho <daniel.carvalho@ufu.br>
 * @date 2021
 *
 * @copyright Copyright (c) 2021 Daniel P. Carvalho.
 * SPDX-License-Identifier: MIT
 */

/* --- Included Files ----------------------------------------------------- */

#include <stdint.h>

/* --- Pre-processor Definitions ------------------------------------------ */

#define SRAM_START  0x20000000U               /* Início da SRAM. */
#define SRAM_SIZE   (128U * 1024U)            /* 128 KB no STM32F411. */
#define SRAM_END    (SRAM_START + SRAM_SIZE)  /* Fim da SRAM. */

#define STACK_START SRAM_END                  /* Topo inicial da pilha. */

/* --- Function Prototypes ------------------------------------------------ */

int main(void);

/* Tratadores das exceções de sistema. Todos, exceto o de Reset, são
 * apelidos fracos de default_handler: basta definir uma função com o
 * mesmo nome em outro arquivo para substituí-los.
 */

void reset_handler(void);
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hardfault_handler(void)
  __attribute__((weak, alias("default_handler")));
void memmanage_handler(void)
  __attribute__((weak, alias("default_handler")));
void busfault_handler(void)
  __attribute__((weak, alias("default_handler")));
void usagefault_handler(void)
  __attribute__((weak, alias("default_handler")));
void svc_handler(void) __attribute__((weak, alias("default_handler")));
void debugmon_handler(void)
  __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void)
  __attribute__((weak, alias("default_handler")));

/* --- External Data ------------------------------------------------------ */

/* Símbolos definidos pelo linker script. */

extern uint32_t _sdata;     /* Início da seção .data na SRAM. */
extern uint32_t _edata;     /* Fim da seção .data na SRAM. */
extern uint32_t _la_data;   /* Origem da seção .data na Flash. */

extern uint32_t _sbss;      /* Início da seção .bss. */
extern uint32_t _ebss;      /* Fim da seção .bss. */

/* --- Public Data -------------------------------------------------------- */

/* Tabela de vetores. A seção .isr_vectors é posicionada pelo linker
 * script no início da Flash.
 */

uint32_t g_vectors[] __attribute__((section(".isr_vectors"))) =
{
  STACK_START,                            /* 0x0000 0000 */
  (uint32_t)reset_handler,                /* 0x0000 0004 */
  (uint32_t)nmi_handler,                  /* 0x0000 0008 */
  (uint32_t)hardfault_handler,            /* 0x0000 000c */
  (uint32_t)memmanage_handler,            /* 0x0000 0010 */
  (uint32_t)busfault_handler,             /* 0x0000 0014 */
  (uint32_t)usagefault_handler,           /* 0x0000 0018 */
  0,                                      /* 0x0000 001c: reservado. */
  0,                                      /* 0x0000 0020: reservado. */
  0,                                      /* 0x0000 0024: reservado. */
  0,                                      /* 0x0000 0028: reservado. */
  (uint32_t)svc_handler,                  /* 0x0000 002c */
  (uint32_t)debugmon_handler,             /* 0x0000 0030 */
  0,                                      /* 0x0000 0034: reservado. */
  (uint32_t)pendsv_handler,               /* 0x0000 0038 */
  (uint32_t)systick_handler,              /* 0x0000 003c */
};

/* --- Public Functions --------------------------------------------------- */

/**
 * @brief Tratador de Reset: primeira função executada após o reset.
 *
 * Copia a seção .data da Flash para a SRAM, zera a seção .bss e chama
 * main().
 */

void reset_handler(void)
{
  uint32_t i;
  uint32_t size;
  uint8_t *dst;
  uint8_t *src;

  /* Copia a seção .data da Flash (LMA) para a SRAM (VMA). */

  size = (uint32_t)&_edata - (uint32_t)&_sdata;
  dst  = (uint8_t *)&_sdata;
  src  = (uint8_t *)&_la_data;

  for (i = 0; i < size; i++)
    {
      *dst++ = *src++;
    }

  /* Preenche a seção .bss com zeros. */

  size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  dst  = (uint8_t *)&_sbss;

  for (i = 0; i < size; i++)
    {
      *dst++ = 0;
    }

  /* Só agora o ambiente do C está pronto. */

  main();
}

/**
 * @brief Tratador padrão das exceções não implementadas.
 *
 * Trava o processador em um laço infinito, em vez de deixá-lo saltar
 * para um endereço inválido. Com o depurador, é fácil ver que o
 * programa parou aqui.
 */

void default_handler(void)
{
  while (1)
    {
    }
}

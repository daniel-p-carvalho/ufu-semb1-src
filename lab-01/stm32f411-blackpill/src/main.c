/**
 * @file main.c
 * @brief Pisca o LED da Blackpill (PC13) acessando os registradores.
 *
 * @author Daniel P. Carvalho <daniel.carvalho@ufu.br>
 * @date 2021
 *
 * @copyright Copyright (c) 2021 Daniel P. Carvalho.
 * SPDX-License-Identifier: MIT
 */

/* --- Included Files ----------------------------------------------------- */

#include <stdint.h>
#include <stdlib.h>

/* --- Pre-processor Definitions ------------------------------------------ */

/* Endereços base dos periféricos (RM0383, mapa de memória). */

#define STM32_RCC_BASE            0x40023800U  /* Reset and clock control. */
#define STM32_GPIOC_BASE          0x40020800U  /* GPIO porta C. */

/* Offsets dos registradores. */

#define STM32_RCC_AHB1ENR_OFFSET  0x0030U  /* Habilitação de clock AHB1. */

#define STM32_GPIO_MODER_OFFSET   0x0000U  /* Modo dos pinos. */
#define STM32_GPIO_OTYPER_OFFSET  0x0004U  /* Tipo de saída. */
#define STM32_GPIO_PUPDR_OFFSET   0x000cU  /* Pull-up/pull-down. */
#define STM32_GPIO_ODR_OFFSET     0x0014U  /* Dado de saída. */
#define STM32_GPIO_BSRR_OFFSET    0x0018U  /* Set/reset de bits. */

/* Endereços dos registradores. */

#define STM32_RCC_AHB1ENR   (STM32_RCC_BASE + STM32_RCC_AHB1ENR_OFFSET)

#define STM32_GPIOC_MODER   (STM32_GPIOC_BASE + STM32_GPIO_MODER_OFFSET)
#define STM32_GPIOC_OTYPER  (STM32_GPIOC_BASE + STM32_GPIO_OTYPER_OFFSET)
#define STM32_GPIOC_PUPDR   (STM32_GPIOC_BASE + STM32_GPIO_PUPDR_OFFSET)
#define STM32_GPIOC_ODR     (STM32_GPIOC_BASE + STM32_GPIO_ODR_OFFSET)
#define STM32_GPIOC_BSRR    (STM32_GPIOC_BASE + STM32_GPIO_BSRR_OFFSET)

/* RCC_AHB1ENR: habilitação de clock dos periféricos do barramento AHB1. */

#define RCC_AHB1ENR_GPIOCEN       (1U << 2)  /* Clock da porta C. */

/* GPIO_MODER: modo de cada pino (2 bits por pino). */

#define GPIO_MODER_INPUT          0U  /* Entrada. */
#define GPIO_MODER_OUTPUT         1U  /* Saída de uso geral. */
#define GPIO_MODER_ALT            2U  /* Função alternativa. */
#define GPIO_MODER_ANALOG         3U  /* Analógico. */

#define GPIO_MODER_SHIFT(n)       ((n) << 1)
#define GPIO_MODER_MASK(n)        (3U << GPIO_MODER_SHIFT(n))

/* GPIO_OTYPER: tipo de saída de cada pino (1 bit por pino). */

#define GPIO_OTYPER_PP            0U  /* Push-pull. */
#define GPIO_OTYPER_OD            1U  /* Dreno aberto. */

#define GPIO_OT_SHIFT(n)          (n)
#define GPIO_OT_MASK(n)           (1U << GPIO_OT_SHIFT(n))

/* GPIO_PUPDR: resistores de pull-up/pull-down (2 bits por pino). */

#define GPIO_PUPDR_NONE           0U  /* Sem pull-up nem pull-down. */
#define GPIO_PUPDR_PULLUP         1U  /* Pull-up. */
#define GPIO_PUPDR_PULLDOWN       2U  /* Pull-down. */

#define GPIO_PUPDR_SHIFT(n)       ((n) << 1)
#define GPIO_PUPDR_MASK(n)        (3U << GPIO_PUPDR_SHIFT(n))

/* GPIO_BSRR: os bits 0-15 ligam o pino, os bits 16-31 o desligam. */

#define GPIO_BSRR_SET(n)          (1U << (n))
#define GPIO_BSRR_RESET(n)        (1U << ((n) + 16))

/* Configuração. */

#define LED_PIN    13U       /* LED da Blackpill: PC13, ativo em baixo. */
#define LED_DELAY  100000U   /* Iterações do laço de atraso. */

/* --- Public Data ---------------------------------------------------------- */

/* Quantas iterações faltam para o laço de atraso terminar. Começa em
 * LED_DELAY e é decrementada a cada volta, até chegar a zero.
 */

static volatile uint32_t g_delay_count = LED_DELAY;

/* --- Private Functions ---------------------------------------------------- */

/**
 * @brief Espera ocupada de LED_DELAY iterações.
 */

static void delay(void)
{
  for ( ; g_delay_count > 0; g_delay_count--)
    {
    }

  g_delay_count = LED_DELAY;
}

/* --- Public Functions --------------------------------------------------- */

/**
 * @brief Configura o PC13 como saída e pisca o LED indefinidamente.
 *
 * @return Não retorna.
 */

int main(void)
{
  uint32_t reg;

  /* Ponteiros para os registradores. O volatile obriga o compilador a
   * fazer cada leitura e escrita, na ordem em que aparecem no código.
   */

  volatile uint32_t *rcc_ahb1enr  = (volatile uint32_t *)STM32_RCC_AHB1ENR;
  volatile uint32_t *gpioc_moder  = (volatile uint32_t *)STM32_GPIOC_MODER;
  volatile uint32_t *gpioc_otyper = (volatile uint32_t *)STM32_GPIOC_OTYPER;
  volatile uint32_t *gpioc_pupdr  = (volatile uint32_t *)STM32_GPIOC_PUPDR;
  volatile uint32_t *gpioc_bsrr   = (volatile uint32_t *)STM32_GPIOC_BSRR;

  /* Habilita o clock da porta C. */

  reg  = *rcc_ahb1enr;
  reg |= RCC_AHB1ENR_GPIOCEN;
  *rcc_ahb1enr = reg;

  /* Configura o PC13 como saída push-pull, sem pull-up nem pull-down. */

  reg  = *gpioc_moder;
  reg &= ~GPIO_MODER_MASK(LED_PIN);
  reg |= GPIO_MODER_OUTPUT << GPIO_MODER_SHIFT(LED_PIN);
  *gpioc_moder = reg;

  reg  = *gpioc_otyper;
  reg &= ~GPIO_OT_MASK(LED_PIN);
  reg |= GPIO_OTYPER_PP << GPIO_OT_SHIFT(LED_PIN);
  *gpioc_otyper = reg;

  reg  = *gpioc_pupdr;
  reg &= ~GPIO_PUPDR_MASK(LED_PIN);
  reg |= GPIO_PUPDR_NONE << GPIO_PUPDR_SHIFT(LED_PIN);
  *gpioc_pupdr = reg;

  while (1)
    {
      /* Liga o LED (ativo em nível baixo). */

      *gpioc_bsrr = GPIO_BSRR_RESET(LED_PIN);

      delay();

      /* Desliga o LED. */

      *gpioc_bsrr = GPIO_BSRR_SET(LED_PIN);

      delay();
    }

  /* Nunca deveria chegar aqui. */

  return EXIT_FAILURE;
}

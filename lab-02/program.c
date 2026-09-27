/**
 * @file program.c
 * @brief Programa didatico para dissecao do pipeline de compilacao C (nativo).
 *
 * @author Daniel P. Carvalho <daniel.carvalho@ufu.br>
 * @date 2026
 *
 * @copyright Copyright (c) 2026 Daniel P. Carvalho.
 * SPDX-License-Identifier: MIT
 */

/* --- Included Files ----------------------------------------------------- */

#include <stdio.h>

/* --- Pre-processor Definitions ------------------------------------------ */

#define INITIAL_VALUE 10

/* --- Public Data -------------------------------------------------------- */

int g_a = INITIAL_VALUE;
int g_b;

/* --- Public Functions --------------------------------------------------- */

/**
 * @brief Soma dois inteiros.
 *
 * @param x Primeiro operando.
 * @param y Segundo operando.
 *
 * @return Soma dos dois operandos.
 */
int add(int x, int y)
{
  return x + y;
}

int main(void)
{
  printf("g_a + g_b = %d\n", add(g_a, g_b));
  return 0;
}

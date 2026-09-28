/**
 * @file embedded.c
 * @brief Programa didatico sem runtime ou libc para compilacao cruzada ARM.
 *
 * @author Daniel P. Carvalho <daniel.carvalho@ufu.br>
 * @date 2026
 *
 * @copyright Copyright (c) 2026 Daniel P. Carvalho.
 * SPDX-License-Identifier: MIT
 */

/* --- Included Files ----------------------------------------------------- */

/* Nao inclui cabecalhos de sistema: compilacao bare-metal isolada. */

/* --- Pre-processor Definitions ------------------------------------------ */

#define INITIAL_VALUE 10

/* --- Public Data -------------------------------------------------------- */

int g_a = INITIAL_VALUE;
int g_b;
int g_c;

/* --- Public Functions --------------------------------------------------- */

/**
 * @brief Soma dois inteiros seguindo a convencao AAPCS.
 *
 * @param x Primeiro operando (recebido em R0).
 * @param y Segundo operando (recebido em R1).
 *
 * @return Soma dos dois operandos (retornado em R0).
 */
int add(int x, int y)
{
  return x + y;
}

int main(void)
{
  g_c = add(g_a, g_b);

  while (1)
    {
    }

  return 0;
}

/**
 * @file cosine.c
 * @brief Exemplo demonstrativo de ligacao com biblioteca matematica (-lm).
 *
 * @author Daniel P. Carvalho <daniel.carvalho@ufu.br>
 * @date 2026
 *
 * @copyright Copyright (c) 2026 Daniel P. Carvalho.
 * SPDX-License-Identifier: MIT
 */

/* --- Included Files ----------------------------------------------------- */

#include <math.h>
#include <stdio.h>

/* --- Public Functions --------------------------------------------------- */

int main(int argc, char *argv[])
{
  (void)argv;
  printf("%f\n", cos(argc));
  return 0;
}

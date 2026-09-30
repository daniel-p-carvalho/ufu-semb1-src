# Plano de Ensino — Sistemas Embarcados I

<div align="center">
  <img src="images/logo-ufu.svg" alt="UFU Logo" width="200">

  ### Universidade Federal de Uberlândia (UFU)
  ### Faculdade de Engenharia Elétrica / Engenharia de Controle e Automação (FEELT)
  **Semestre Letivo: 2026/02**
</div>

---

## 1. Identificação

| Item | Especificação |
|:---|:---|
| **Componente Curricular:** | Sistemas Embarcados I |
| **Código da Disciplina:** | 31523 |
| **Unidade Ofertante:** | Faculdade de Engenharia Elétrica (FEELT) |
| **Carga Horária Total:** | 75 horas presenciais (90 horas-aula) |
| **Distribuição:** | Teórica: 45 horas \| Prática: 30 horas |
| **Período / Série:** | 5º Período |
| **Turma:** | A |
| **Natureza:** | Obrigatória |
| **Docente Responsável:** | Prof. Daniel P. Carvalho ([daniel.carvalho@ufu.br](mailto:daniel.carvalho@ufu.br)) |

---

## 2. Ementa

Estudo e desenvolvimento de sistemas embarcados microcontrolados. Visão sistêmica do processo de desenvolvimento de hardware e firmware; Técnicas de codificação eficiente; Estudo da arquitetura de um microcontrolador; Estratégias de criação de firmware; Portabilidade.

---

## 3. Justificativa

Trabalhar os elementos de projeto envolvidos no desenvolvimento de sistemas embarcados, tanto no aspecto de hardware como de firmware. Trazer a sistemática do processo de desenvolvimento de hardware microcontrolado, técnicas de codificação eficiente, estratégias de criação de firmware, estudo da plataforma ARM Cortex-M, desenvolvimento de hardware microcontrolado, criação de placas e circuitos com ferramentas CAD e arquitetura de computadores.

---

## 4. Objetivos

### Objetivo Geral
Integrar os conceitos apresentados em diversas disciplinas da Engenharia Elétrica e de Controle e Automação através do estudo prático e desenvolvimento de sistemas embarcados:
* Visão sistêmica do processo de desenvolvimento de hardware e firmware;
* Técnicas de codificação eficiente e segura em linguagem C;
* Estratégias de estruturação e arquitetura de firmware;
* Estudo aprofundado da plataforma ARM Cortex-M e microcontroladores STM32;
* Portabilidade e camadas de abstração de hardware.

### Objetivos Específicos
* Compreender detalhadamente os principais protocolos e barramentos de comunicação digital (USART/UART, I2C, SPI);
* Empregar eficientemente a linguagem C para programação bare-metal em microcontroladores de 32 bits;
* Desenvolver firmware direto nos registradores de controle e temporizadores do núcleo ARM Cortex-M4;
* Aplicar paradigmas de construção de firmwares (orientado a interrupções, super-loop cooperativo e noções de RTOS);
* Utilizar ferramentas modernas de compilação, automação (`make`) e depuração em hardware (*GDB*, *OpenOCD*, *VS Code*);
* Aplicar normas de versionamento com Git e padrões de codificação (*coding standards*).

---

## 5. Programa

### 5.1. Fundamentos de Arquitetura e Ambiente de Desenvolvimento
* Organização estruturada de computadores, arquitetura Von Neumann vs Harvard, paradigmas CISC e RISC.
* Ambiente operacional Linux para desenvolvimento embarcado, shell terminal, utilitários de manipulação e análise de arquivos binários.
* A cadeia de ferramentas GNU (*toolchain* `arm-none-eabi-gcc`, `as`, `ld`, `objdump`, `nm`).
* Controle de versão de software com Git e boas práticas de commits e repositórios.

### 5.2. Arquitetura ARM Cortex-M e o Processo de Compilação
* O núcleo ARM Cortex-M4: modelo de registradores, modos de operação (Thread e Handler) e níveis de privilégio.
* O pipeline de compilação do C ao binário: pré-processamento (`-E`), compilação (`-S`), montagem (`-c`) e linkedição.
* A regra Load-Store do RISC e o padrão de chamada de procedimentos AAPCS (*Procedure Call Standard for the Arm Architecture*).
* Desmontagem de executáveis e resolução de relocações.

### 5.3. O Microcontrolador STM32F411, Startup e Linker Script
* O ecossistema STM32: interconexão de barramentos internos (AHB e APB) e sistema de clock (RCC, HSI, HSE, PLL).
* Mapeamento de memória: Flash, SRAM e espaço de periféricos mapeados em memória.
* Escrita artesanal do *linker script* (`.ld`): seções de saída (`.text`, `.rodata`, `.data`, `.bss`), atributos de memória, alinhamento de palavras (`ALIGN(4)`) e tratamento de exceções *UsageFault*.
* Código de inicialização (*startup code*) em C bare-metal: inicialização dos dados globais na SRAM e zeramento da seção BSS.

### 5.4. Depuração em Hardware e Automação de Compilação
* A interface de gravação e depuração em circuito (SWD/JTAG) com adaptadores ST-LINK.
* Utilização de OpenOCD e GDB para depuração remota em hardware real: pontos de parada (*breakpoints*), inspeção de registradores e pilha.
* Automação de compilação com GNU `make`: sintaxe de `Makefiles`, regras implícitas e explícitas, dependências automáticas e compilação modular.

### 5.5. Entrada e Saída de Uso Geral (GPIO) e Manipulação em Baixo Nível
* Estrutura interna dos pinos de I/O do STM32F411: circuitos de Push-Pull, Open-Drain, resistores de Pull-up e Pull-down.
* Registradores de configuração e controle (`MODER`, `OTYPER`, `OSPEEDR`, `PUPDR`) e registradores de dados (`IDR`, `ODR`, `BSRR`).
* Manipulação direta de bits em C: operadores bitwise, máscaras, ponteiros tipados para registradores e a semântica do qualificador `volatile`.
* Técnicas de tratamento de ruído e repique de contatos mecânicos (*debounce*).

### 5.6. Sistema de Exceções e Interrupções
* O controlador de interrupções aninhadas NVIC (*Nested Vectored Interrupt Controller*): vetorização, níveis de prioridade e preempção.
* O subsistema EXTI (*Extended Interrupt and Event Controller*) no STM32F411: mapeamento de pinos e disparo por bordas.
* Escrita e registro de rotinas de serviço de interrupção (*Interrupt Service Routines* - ISR).

### 5.7. Temporizadores de Hardware e Modulação por Largura de Pulso (PWM)
* O temporizador de sistema do Cortex-M (*SysTick*): temporização não-bloqueante e medição de intervalos.
* Temporizadores de uso geral (TIM2/TIM3/TIM4/TIM5): base de tempo, prescaler e auto-reload.
* Canais de comparação de saída (*Output Compare*) e geração de sinais PWM para controle de atuadores e brilho.

### 5.8. Protocolos de Comunicação Serial
* **Comunicação Serial Assíncrona (USART/UART):** Princípios de transmissão serial assíncrona, sincronismo de quadros, gerador de baud rate, controle de fluxo e comunicação bidirecional por interrupção com buffers circulares.
* **Barramento Serial Periférico (SPI):** Topologia síncrona mestre-escravo, linhas de sinal (SCK, MOSI, MISO, CS), modos de clock (polaridade e fase) e alta taxa de transferência com periféricos externos.
* **Barramento Inter-Integrated Circuit (I2C):** Linhas SDA e SCL, condição de Start/Stop, endereçamento de 7 bits, reconhecimento (ACK/NACK) e interfaceamento com sensores.

### 5.9. Conversão Analógico-Digital (ADC) e Projeto de Firmware
* Princípios de conversão A/D: amostragem, quantização, resolução e tempo de conversão.
* O periférico ADC do STM32F411: canais internos/externos, sequenciamento e leitura de grandezas físicas.
* Arquitetura de firmware: super-loop com interrupções, máquinas de estados finitos (FSM) e boas práticas de código seguro.

---

## 6. Metodologia

O processo de ensino-aprendizagem é estruturado em uma abordagem prática, incremental e *bottom-up*:

* **Aulas Teóricas Expositivas e Dialogadas:** Apresentação rigorosa da fundamentação de arquitetura, princípios de hardware e padrões de software, estimulando a reflexão sobre o porquê de cada escolha técnica.
* **Aulas Práticas em Bancada de Laboratório:** Cada estudante ou dupla trabalha diretamente com a placa de desenvolvimento STM32F411 (Blackpill), gravador ST-LINK e ferramentas de bancada. As atividades são desenvolvidas em ferramentas de código aberto padrão da indústria (*GCC*, *Make*, *OpenOCD*, *GDB* e *VS Code*).
* **Desenvolvimento Guiado e Atividades Formativas:** Nas primeiras semanas, a construção artesanal do software (sem bibliotecas prontas como HAL da ST) garante que o estudante desmistifique os estágios do código de inicialização e do linker.
* **Acompanhamento Contínuo via Controle de Versão:** A entrega das atividades e relatórios semanais (`LEIAME.md`) é realizada obrigatoriamente por meio de repositórios individuais privados no GitHub (`semb1-entregas`), fomentando a disciplina de engenharia de software e histórico reprodutível.
* **Cômputo de Atividades Acadêmicas Remotas:** Conforme estabelecido no calendário aprovado pelo CONGRAD, o período inicial e as reposições oficiais integram a carga horária da disciplina mediante roteiros de estudos dirigidos e leitura de manuais técnicos (*Reference Manual* RM0383 e *Datasheet*).

---

## 7. Critérios de Avaliação

A avaliação do aproveitamento é contínua e formativa, dividida em avaliações teóricas e práticas totalizando **100 pontos**:

| Instrumento | Modalidade | Conteúdo Abrangente | Pontuação |
|:---|:---:|:---|:---:|
| **Prova Teórica 1 (P1)** | Individual / Presencial | Arquitetura de Computadores, Compilação Cruzada, ARM Cortex-M4, STM32F411, Inicialização, Linker Script e GPIO. | **25 pontos** |
| **Prova Teórica 2 (P2)** | Individual / Presencial | Sistema de Interrupções (NVIC/EXTI), Timers/PWM, Comunicação Serial (USART, SPI, I2C), ADC e Firmware. | **35 pontos** |
| **Trabalho Prático 1 (T1)** | Projeto em Grupo/Individual | Desenvolvimento de firmware bare-metal e validação do fluxo completo de inicialização e acionamento de hardware em bancada. | **15 pontos** |
| **Trabalho Prático 2 (T2)** | Projeto em Grupo/Individual | Projeto Integrador de Sistemas Embarcados: integração de periféricos de I/O, temporização, aquisição de dados e comunicação serial. | **25 pontos** |
| **Total:** | | | **100 pontos** |

### Recuperação de Aprendizagem
Em estrito cumprimento à **Resolução CONGRAD nº 46/2022**, ao término do período letivo será disponibilizada uma oportunidade de recuperação de aprendizagem no valor de **até 20 pontos** aos estudantes que:
1. Tenham obtido frequência mínima regimental de 75%;
2. Tenham atingido aproveitamento mínimo de 30% na soma das avaliações teóricas;
3. A nota da recuperação será atribuída com base na regularidade e qualidade técnica dos Estudos Dirigidos e atividades práticas formativas entregues ao longo de todo o semestre no repositório individual do aluno.

---

## 8. Cronograma de Aulas (Semestre 2026/02)

O cronograma a seguir está rigorosamente alinhado com o Calendário Acadêmico Oficial aprovado pela **Resolução Consolidada CONGRAD nº 158/2025**, contemplando 17 encontros letivos (14 segundas-feiras úteis + 3 reposições regimentais):

| Enc. | Data | Dia da Semana | Tipo | Conteúdo Programático Teórico e Prático |
|:---:|:---:|:---:|:---:|:---|
| **01** | **17/08/2026** | Segunda | Remoto / Ativ. Acad. | **Apresentação e Fundamentos:** Apresentação da disciplina, plano de ensino e critérios de avaliação. Introdução à Arquitetura de Computadores (Von Neumann vs Harvard, CISC vs RISC).<br>*Laboratório:* Ambiente de desenvolvimento Linux, comandos de terminal e configuração de ferramentas (WSL, VS Code, Git). |
| **02** | **24/08/2026** | Segunda | Remoto / Ativ. Acad. | **Arquitetura ARM e Compilação:** O núcleo ARM Cortex-M4, registradores, modos de operação e o padrão AAPCS.<br>*Laboratório:* O pipeline de compilação em C: pré-processamento, compilação, montagem e desmontagem (GCC nativo e ARM cruzado). |
| — | *31/08/2026* | *Segunda* | *Feriado Municipal* | **Sem aula presencial** — Feriado em Uberlândia (Aniversário da cidade). *(Aula compensada na reposição de 22/09).* |
| — | *07/09/2026* | *Segunda* | *Feriado Nacional* | **Sem aula presencial** — Feriado Nacional da Independência do Brasil. *(Aula compensada na reposição de 15/10).* |
| **03** | **14/09/2026** | Segunda | Presencial Bancada | **O STM32F411 e o Linker Script:** Mapa de memória do STM32F411, barramentos AHB/APB e subsistema de clock RCC.<br>*Laboratório:* Escrita artesanal do arquivo de ligação (`stm32f411-rom.ld`) e tabela de vetores de interrupção em C (`lab-03`). |
| **04** | **21/09/2026** | Segunda | Presencial Bancada | **Inicialização Bare-Metal:** Anatomia da inicialização, cópia da seção `.data` para SRAM, zeramento da `.bss` e chamada da função principal.<br>*Laboratório:* Gravação em bancada com ST-LINK/OpenOCD e validação do programa `g_a + g_b` no depurador GDB (`lab-04`). |
| **05** | **22/09/2026** | **Terça** | **Reposição CONGRAD** | **Depuração em Hardware:** Breakpoints de hardware, watchpoints e inspeção em tempo real de registradores e mapa de memória.<br>*Laboratório:* Sessão guiada de depuração avançada no VS Code via Cortex-Debug e OpenOCD. *(Compensação do feriado de 31/08).* |
| **06** | **28/09/2026** | Segunda | Presencial Bancada | **Automação com Make:** Princípios da automação de compilação, sintaxe de regras, variáveis e dependências em Makefiles.<br>*Laboratório:* Estruturação modular de projeto em C e escrita do Makefile da disciplina (`lab-05`). *(Marco de 25% do semestre).* |
| **07** | **05/10/2026** | Segunda | Presencial Bancada | **Entrada e Saída (GPIO):** Registradores de controle (`MODER`, `PUPDR`) e dados (`IDR`, `ODR`, `BSRR`), modificador `volatile` e manipulação de bits.<br>*Laboratório:* Acionamento de saídas digitais, leitura de teclas e algoritmo de debounce em C. |
| — | *12/10/2026* | *Segunda* | *Feriado Nacional* | **Sem aula presencial** — Feriado Nacional de Nossa Senhora Aparecida. *(Aula compensada na reposição de 15/10).* |
| **08** | **15/10/2026** | **Quinta** | **Reposição CONGRAD** | **O Controlador de Interrupções NVIC:** Vetorização de interrupções, prioridades, preempção e sub-vetorização EXTI no STM32F411.<br>*Laboratório:* Configuração do NVIC e tratamento de interrupções externas disparadas por borda de sinal. *(Compensação de 07/09).* |
| **09** | **19/10/2026** | Segunda | Presencial Bancada | **Arquitetura de Drivers:** Princípios de engenharia de software para embarcados: abstração de hardware (HAL), encapsulamento e drivers de I/O.<br>*Laboratório:* Implementação e validação de biblioteca modular de GPIO e botões orientada a eventos. |
| **10** | **26/10/2026** | Segunda | Presencial Avaliação | **Avaliação Teórica 1 (P1):** Avaliação presencial individual cobrindo as semanas 1 a 7.<br>*Laboratório:* Apresentação e acompanhamento de bancada do **Trabalho Prático 1 (T1)**. |
| — | *02/11/2026* | *Segunda* | *Feriado Nacional* | **Sem aula presencial** — Feriado Nacional de Finados. *(Aula compensada na reposição de 14/11).* |
| **11** | **09/11/2026** | Segunda | Presencial Bancada | **Temporizadores de Hardware:** O temporizador do sistema (SysTick) e os temporizadores gerais de 16/32 bits (TIM2 a TIM5).<br>*Laboratório:* Criação de base de tempo precisa para temporização não-bloqueante e medições temporais. |
| **12** | **14/11/2026** | **Sábado** | **Reposição CONGRAD** | **Modulação por Largura de Pulso (PWM):** Comparação de saída (*Output Compare*), duty cycle e aplicações em acionamentos.<br>*Laboratório:* Geração de sinais PWM com temporizador de hardware para controle de potência. *(Compensação de 02/11).* |
| **13** | **16/11/2026** | Segunda | Presencial Bancada | **Comunicação Serial USART:** Protocolo assíncrono UART/USART, gerador de baud rate, buffers de transmissão e recepção por interrupção.<br>*Laboratório:* Implementação de comunicação serial bidirecional entre o microcontrolador STM32 e o computador. |
| **14** | **23/11/2026** | Segunda | Presencial Bancada | **Barramento Serial SPI:** Sinais de clock e dados, modos SPI, sincronismo e transações mestre-escravo.<br>*Laboratório:* Comunicação de alta velocidade via SPI com periférico externo (sensores ou displays). *(Marco de 75% do semestre).* |
| **15** | **30/11/2026** | Segunda | Presencial Bancada | **Barramento I2C e Conversão A/D:** O protocolo I2C com periféricos seriais e amostragem analógica com o ADC interno do STM32F411.<br>*Laboratório:* Aquisição de grandezas analógicas via ADC e comunicação I2C. |
| **16** | **07/12/2026** | Segunda | Presencial Avaliação | **Avaliação Teórica 2 (P2):** Avaliação presencial individual cobrindo interrupções, temporizadores, comunicação serial e ADC.<br>*Laboratório:* Demonstração e arguição do **Trabalho Prático Integrador (T2)**. |
| **17** | **14/12/2026** | Segunda | Presencial Fechamento | **Encerramento do Semestre:** Vista de avaliações, revisão de conceitos e fechamento do diário de classe.<br>*Laboratório:* Aplicação das atividades de recuperação de aprendizagem (Res. CONGRAD nº 46/2022). |
| — | *19/12/2026* | *Sábado* | *Término do Semestre* | **Término oficial do semestre letivo e das aulas 2026/02 na UFU.** |

---

## 9. Bibliografia

### Bibliografia Básica (PPC / MEC)
1. **TOCCI, Ronald J.; WIDMER, Neal S.; MOSS, Gregory L.** *Sistemas digitais: princípios e aplicações*. 11. ed. São Paulo: Pearson Education do Brasil, 2011. xx, 817 p. ISBN: 978-8576059226.
2. **TANENBAUM, Andrew S.** *Organização estruturada de computadores*. São Paulo: Pearson, 2013. 605 p. ISBN: 978-8581435398.
3. **PRESSMAN, Roger S.** *Engenharia de software: uma abordagem profissional*. 8. ed. Porto Alegre: McGraw-Hill, 2016. ISBN: 978-8580555349.

### Bibliografia Complementar
1. **CARVALHO, Daniel P.** *Sistemas Embarcados I: Da Teoria à Prática com ARM Cortex-M4 e STM32*. Uberlândia: Faculdade de Engenharia Elétrica (FEELT/UFU), 2026.  
   Disponível localmente no repositório: [Apostila da Disciplina (PDF)](apostila/apostila-sistemas-embarcados.pdf) \| Versão online interativa: <https://github.com/daniel-p-carvalho/ufu-embedded-systems>.
2. **YIU, Joseph.** *The Definitive Guide to ARM® Cortex®-M3 and Cortex®-M4 Processors*. 3ª edição. Oxford: Newnes / Elsevier, 2013. ISBN: 978-0124080829.
3. **STMICROELECTRONICS.** *RM0383 Reference Manual: STM32F411xC/E Advanced Arm®-based 32-bit MCUs*. DocID 026448 Rev 7, 2021.
4. **STMICROELECTRONICS.** *PM0214 Programming Manual: STM32 Cortex®-M4 MCUs and MPUs Programming Manual*. DocID 022708 Rev 5, 2020.
5. **BACKES, André.** *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. 371 p. ISBN: 978-8535268553.
6. **KERNIGHAN, Brian W.; RITCHIE, Dennis M.** *C: A Linguagem de Programação Padrão ANSI*. Rio de Janeiro: Campus, 1989. ISBN: 978-8570015860.
7. **LI, Qing; YAO, Caroline.** *Real-Time Concepts for Embedded Systems*. San Francisco: CMP Books, 2003. xii, 294 p. ISBN: 978-1578201242.
8. **OLIVEIRA, André Schneider de; ANDRADE, Fernando Souza de.** *Sistemas embarcados: hardware e firmware na prática*. São Paulo: Érica, 2006. 316 p. ISBN: 978-8536501055.
9. **STALLMAN, Richard M. et al.** *Using the GNU Compiler Collection (GCC)*. Free Software Foundation, 2023. Disponível em: <https://gcc.gnu.org/onlinedocs/>.

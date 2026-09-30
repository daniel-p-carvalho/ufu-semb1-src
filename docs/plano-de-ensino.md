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

O processo de ensino-aprendizagem é estruturado em uma abordagem prática, incremental, interdisciplinar e *bottom-up*:

* **Aulas Teóricas Focadas em Técnicas de Firmware e Arquitetura:** Apresentação rigorosa da fundamentação de arquitetura do núcleo ARM Cortex-M4, subsistema de interrupções (NVIC), padrões de software de tempo real (*Time-Triggered Superloop*, Máquinas de Estados Finitos - FSM, Co-rotinas) e engenharia de sistemas embarcados.
* **Paradigma "Host-First" (Validação no PC antes de Embarcar):** O estudante aprende que firmware de qualidade desacopla regras de negócio do hardware. Toda a lógica da aplicação (física, colisões, menus da FSM, álgebra de pixels em *framebuffer* de 1 KB e filas circulares) é implementada e testada no computador (`gcc` host x86 no Linux/WSL) antes de ser integrada aos drivers do microcontrolador.
* **Engenharia de Hardware com Altium Designer:** Paralelamente ao firmware, os estudantes utilizam ferramentas profissionais de EDA (*Altium Designer* via *Altium Student Lab*) para projetar a placa de circuito impresso (PCB) de um console portátil ergonômico, gerando o pacote fabril completo (Gerbers, NC Drill, BOM e STEP 3D).
* **Aulas Práticas em Bancada de Laboratório (Silício Real):** Trabalho direto com a placa STM32F411 (Blackpill), gravador ST-LINK, periféricos e instrumentos de bancada, com o *Reference Manual* (RM0383) aberto. O software é desenvolvido artesanalmente em bare-metal C puro (sem HAL pronta e sem RTOS), utilizando a cadeia de ferramentas de código aberto padrão da indústria (*GCC*, *Make*, *OpenOCD*, *GDB* e *VS Code*).
* **Acompanhamento Contínuo via Controle de Versão:** A entrega das atividades semanais e relatórios técnicos (`LEIAME.md`) é realizada obrigatoriamente por repositórios individuais privados no GitHub (`semb1-entregas`), garantindo disciplina de versionamento e histórico técnico reprodutível.
* **Cômputo de Atividades Acadêmicas Remotas:** Conforme estabelecido no calendário aprovado pelo CONGRAD, o período inicial e as reposições oficiais integram a carga horária da disciplina mediante roteiros de estudos dirigidos, simulações e leitura de manuais técnicos.

---

## 7. Critérios de Avaliação

A avaliação do aproveitamento é contínua e formativa, dividida em avaliações teóricas e trabalhos práticos de engenharia totalizando **100 pontos**:

| Instrumento | Modalidade | Conteúdo Abrangente | Pontuação |
|:---|:---:|:---|:---:|
| **Prova Teórica 1 (P1)** | Individual / Presencial | Arquitetura de Computadores, ISA Thumb-2, ARM Cortex-M4, STM32F411, Inicialização Bare-Metal, Linker Script e GPIO. | **25 pontos** |
| **Prova Teórica 2 (P2)** | Individual / Presencial | Sistema de Interrupções (NVIC/EXTI), Timers/PWM, Comunicação Serial (USART, SPI, I2C), ADC e Técnicas de Firmware. | **35 pontos** |
| **Trabalho Prático 1 (T1)** | Projeto de Hardware (Altium) | Projeto de Hardware do Console Portátil no Altium Designer: esquemático, contorno de gamepad, layout de PCB de 2 camadas, plano GND e pacote industrial (Gerbers/BOM). | **15 pontos** |
| **Trabalho Prático 2 (T2)** | Projeto Integrador de Firmware | Projeto Integrador de Firmware Bare-Metal (Console Dino Runner): engine não-bloqueante a 30 FPS, física, FSM, drivers de periféricos (GPIO, Timers, PWM áudio, OLED I2C/SPI e ADC). | **25 pontos** |
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
| **04** | **21/09/2026** | Segunda | Presencial Bancada | **Inicialização Bare-Metal & Primeiro GPIO:** Anatomia do boot de hardware e periféricos mapeados em memória.<br>*Laboratório:* Gravação em bancada com ST-LINK/OpenOCD, depuração no GDB e primeiro acionamento de GPIO (LED PC13 em bare-metal). Apresentação do Projeto Integrador e Altium Student Lab (`lab-04`). |
| **05** | **22/09/2026** | **Terça** | **Reposição CONGRAD** | **Depuração em Hardware & E/S:** Breakpoints de hardware, watchpoints e inspeção em tempo real de registradores do GPIO (`MODER`, `ODR`, `BSRR`).<br>*Laboratório:* Sessão de depuração via Cortex-Debug e controle de GPIO por registradores. *(Compensação do feriado de 31/08).* |
| **06** | **28/09/2026** | Segunda | Presencial Bancada | **Automação com Make & Entradas Digitais:** Princípios do GNU Make, compilação separada, alvos host x86 e ARM, e o modificador `volatile`.<br>*Laboratório:* Configuração de entradas digitais com pull-up interno (`PUPDR`, `IDR`), leitura de botão e escrita do `Makefile` modular (`lab-05`). Início do esquemático no Altium. *(Marco de 25% do semestre).* |
| **07** | **05/10/2026** | Segunda | Presencial Bancada | **Física de Contatos & Máquinas de Estados (FSM):** Ruído elétrico, repique mecânico (*bounce*) e modelagem formal de FSMs para debounce e eventos de botão.<br>*Laboratório:* Implementação de debounce temporal em C e teste da FSM de botões no PC e na bancada. Esquemático elétrico no Altium (botões e display). |
| — | *12/10/2026* | *Segunda* | *Feriado Nacional* | **Sem aula presencial** — Feriado Nacional de Nossa Senhora Aparecida. *(Aula compensada na reposição de 15/10).* |
| **08** | **15/10/2026** | **Quinta** | **Reposição CONGRAD** | **O Controlador de Interrupções NVIC & EXTI:** Vetorização de interrupções no Cortex-M, prioridades, preempção, seções críticas e subsistema EXTI.<br>*Laboratório:* Configuração do EXTI no STM32F411 para disparo assíncrono por borda nas teclas do console. Layout e contorno de gamepad no Altium. *(Compensação de 07/09).* |
| **09** | **19/10/2026** | Segunda | Presencial Bancada | **Engenharia de PCB & Arquitetura de Software:** Princípios de layout de alta velocidade, planos de terra GND, regras DRC industriais e desacoplamento de software.<br>*Laboratório:* Roteamento da PCB do console no Altium Designer, verificação de regras elétricas/físicas e preparação do pacote de manufatura. |
| **10** | **26/10/2026** | Segunda | Presencial Avaliação | **Avaliação Teórica 1 (P1):** Avaliação presencial individual cobrindo as semanas 1 a 7.<br>*Laboratório:* **Entrega e Avaliação do Trabalho Prático 1 (T1 — Hardware no Altium)**. |
| — | *02/11/2026* | *Segunda* | *Feriado Nacional* | **Sem aula presencial** — Feriado Nacional de Finados. *(Aula compensada na reposição de 14/11).* |
| **11** | **09/11/2026** | Segunda | Presencial Bancada | **Tempo Real & Superloop Cooperativo:** A arquitetura *Time-Triggered*, temporizador SysTick e temporizadores de uso geral (TIM2 a TIM5).<br>*Laboratório:* Configuração de timers de hardware no STM32F411 e integração com a engine de física (30 FPS) validada previamente no PC. |
| **12** | **14/11/2026** | **Sábado** | **Reposição CONGRAD** | **Modulação por Largura de Pulso (PWM):** Comparação de saída (*Output Compare*), duty cycle e síntese sonora.<br>*Laboratório:* Geração de sinais PWM com timer para acionamento de buzzer passivo e síntese de efeitos sonoros do jogo. *(Compensação de 02/11).* |
| **13** | **16/11/2026** | Segunda | Presencial Bancada | **Comunicação Serial USART & Filas Circulares:** Transmissão serial assíncrona, sincronismo de quadros, gerador de baud rate e padrão *Ring Buffer* (FIFO).<br>*Laboratório:* Driver USART bidirecional com recepção por interrupção para envio de telemetria e pontuação para o PC. |
| **14** | **23/11/2026** | Segunda | Presencial Bancada | **Grafismo em Baixo Nível & Barramentos Síncronos:** O protocolo I2C e SPI. Álgebra de pixels, organização do *framebuffer* monocromático de 1 KB na SRAM e desenho de bitmaps.<br>*Laboratório:* Driver de display OLED SSD1306 e envio do buffer de vídeo. *(Marco de 75% do semestre).* |
| **15** | **30/11/2026** | Segunda | Presencial Bancada | **Sinais Analógicos (ADC) & Máquinas de Estados Finais:** Princípios de conversão A/D, amostragem, calibração e estruturação avançada de FSM global.<br>*Laboratório:* Leitura analógica de potenciômetro via ADC1 para controle de velocidade e unificação dos módulos do jogo. |
| **16** | **07/12/2026** | Segunda | Presencial Avaliação | **Avaliação Teórica 2 (P2):** Avaliação presencial individual cobrindo interrupções, temporizadores, PWM, comunicação serial, ADC e técnicas de firmware.<br>*Laboratório:* **Demonstração e Arguição do Trabalho Prático Integrador (T2 — Firmware e Jogo Dino Runner)**. |
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

<div align="center">
  <img src="docs/images/logo-ufu.svg" alt="Universidade Federal de Uberlândia" width="220">

  # Sistemas Embarcados I
  ### Faculdade de Engenharia Elétrica / Engenharia de Controle e Automação (FEELT)
  **Universidade Federal de Uberlândia (UFU)**  
  *Autor:* Prof. Daniel P. Carvalho ([daniel.carvalho@ufu.br](mailto:daniel.carvalho@ufu.br))

  [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
  [![Plataforma: STM32F411](https://img.shields.io/badge/Alvo-STM32F411CEU6-orange.svg)]()
  [![Núcleo: ARM Cortex-M4](https://img.shields.io/badge/ARM-Cortex--M4-brightgreen.svg)]()
  [![Toolchain: GCC Bare-Metal](https://img.shields.io/badge/Toolchain-arm--none--eabi--gcc-red.svg)]()
</div>

---

Bem-vindo ao repositório oficial de códigos-base, materiais didáticos e modelos práticos da disciplina **Sistemas Embarcados I** da Faculdade de Engenharia Elétrica (FEELT) da Universidade Federal de Uberlândia (UFU).

Este repositório atua como o **ponto de distribuição central** do curso: aqui você encontra as versões compiladas em PDF da apostila e das atividades, ferramentas de configuração da bancada e o esqueleto de código inicial para cada aula de laboratório.

A versão interativa em HTML da apostila completa e o código-fonte dos textos teóricos estão disponíveis em: <https://github.com/daniel-p-carvalho/ufu-embedded-systems>.

---

## 1. Material Didático e Documentação Oficial

Para conveniência de consulta *offline*, impressão e acompanhamento nas aulas, disponibilizamos as versões oficiais dos documentos na pasta [`docs/`](./docs):

* **[Plano de Ensino (2026/02)](docs/plano-de-ensino.md)**: Documento oficial da disciplina contendo ementa, objetivos, metodologia, critérios de avaliação e o cronograma completo das 18 semanas alinhado ao calendário CONGRAD/UFU.
* **[Apostila Completa da Disciplina](docs/apostila/apostila-sistemas-embarcados.pdf)**: Volume consolidado em PDF com a fundamentação teórica completa e todos os roteiros de práticas de laboratório das Semanas 1 a 3.
* **[Cadernos de Atividades e Estudos Dirigidos](docs/atividades/)**: PDFs individuais de cada atividade extra-classe e estudo dirigido a serem entregues pelos estudantes:
  - [Atividade: Ambiente e Ferramentas de Desenvolvimento](docs/atividades/atividade-ambiente-ferramentas.pdf) (Semana 1)
  - [Estudo Dirigido: Arquitetura de Computadores](docs/atividades/estudo-dirigido-arquitetura.pdf) (Semana 1)
  - [Atividade: Do C ao Binário no PC](docs/atividades/atividade-do-c-ao-binario-pc.pdf) (Semana 2)
  - [Estudo Dirigido: Arquitetura ARM Cortex-M](docs/atividades/estudo-dirigido-cortex-m.pdf) (Semana 2)
  - [Atividade: Explorando o Código de Inicialização e o Linker Script](docs/atividades/atividade-startup-linker.pdf) (Semana 3)
  - [Estudo Dirigido: O Microcontrolador STM32F411](docs/atividades/estudo-dirigido-stm32.pdf) (Semana 3)

---

## 2. Organização do Repositório

```text
ufu-semb1-src/
├── README.md               # Este catálogo e guia do repositório
├── CODING-STANDARD.md      # Padrão de codificação C da disciplina
├── LICENSE                 # Licença de uso do código-fonte (MIT)
│
├── docs/                   # Material didático oficial e documentação
│   ├── plano-de-ensino.md  # Plano de Ensino institucional (2026/02)
│   ├── apostila/           # Apostila completa consolidada (Teoria + Práticas)
│   ├── atividades/         # Roteiros individuais de atividades e estudos dirigidos
│   └── images/             # Identidade visual e imagens de suporte
│
├── tools/                  # Ferramentas e configurações de ambiente
│   ├── udev/rules.d/       # Regras udev do Linux para o gravador ST-LINK
│   └── vscode/             # Modelos de configuração do VS Code para depuração
│
├── lab-01/                 # Validação do Ambiente (Blackpill)
├── lab-02/                 # Do C ao Binário (Compilação cruzada no terminal)
├── lab-03/                 # Startup e Linker Script (STM32F411)
└── ...                     # Próximos laboratórios (publicados ao longo do semestre)
```

---

## 3. Catálogo de Laboratórios

| Laboratório | Descrição | Semana Sugerida | Plataforma |
|---|---|:---:|:---:|
| [`lab-01/`](./lab-01) | **Validação do Ambiente:** Firmware *blinky* completo para homologação da cadeia de ferramentas cruzada (GCC, ST-LINK, OpenOCD e VS Code). | Semana 1 | STM32F411 (Blackpill) |
| [`lab-02/`](./lab-02) | **Do C ao Binário:** O pipeline manual de compilação no PC e no ARM (`-E`, `-S`, `-c`), modelo Load-Store e convenção AAPCS sem biblioteca C. | Semana 2 | Terminal (PC / ARM) |
| [`lab-03/`](./lab-03) | **Código de Inicialização e *Linker Script*:** Construção artesanal do `startup.c` (tabela de vetores e cópia de seções) e do `stm32f411-rom.ld`. | Semana 3 | Terminal (alvo STM32F411) |

> **Nota didática:** Cada pasta de laboratório contém o estado inicial do projeto para a respectiva aula. Os laboratórios seguintes serão incorporados a este repositório conforme o cronograma letivo avança.

---

## 4. Fluxo de Trabalho do Estudante

Recomendamos que você mantenha o clone deste repositório (`ufu-semb1-src`) como uma **referência local somente-leitura**, utilizada apenas para receber atualizações do professor.

O ciclo recomendado de trabalho é:

### 1. Atualizar este repositório
Antes de cada aula prática, sincronize as últimas novidades e eventuais novos laboratórios:
```bash
cd ~/semb1-workspace/ufu-semb1-src
git pull origin master
```

### 2. Copiar a pasta da aula para sua área de trabalho
Nunca trabalhe diretamente dentro do `ufu-semb1-src`. Copie a pasta do laboratório correspondente para a sua pasta de trabalho:
```bash
# Exemplo para a aula da Semana 2:
cp -r ~/semb1-workspace/ufu-semb1-src/lab-02 ~/semb1-workspace/lab-02
cd ~/semb1-workspace/lab-02
```

### 3. Desenvolver e testar
Siga o roteiro detalhado na apostila da disciplina. Conforme visto em sala:
- Nas primeiras semanas (Semanas 2 e 3), a compilação é realizada manualmente no terminal com o `arm-none-eabi-gcc` para sedimentar os fundamentos da cadeia de ferramentas.
- A partir das semanas de periféricos (Semana 5 em diante), o processo é automatizado via `make`.

### 4. Versionar e Entregar no seu Repositório Pessoal
Ao término da atividade, transfira os arquivos-fonte desenvolvidos e o seu relatório (`LEIAME.md`) para o seu repositório privado de entregas no GitHub (`semb1-entregas`), criado na Semana 1:
```bash
cd ~/semb1-workspace/semb1-entregas
# Adicione suas alterações, verifique com git diff e faça o commit
git status
git diff
git add .
git commit -m "Conclui atividade do lab-XX"
git push origin master
```

---

## 5. Padrão de Codificação e Configurações

* **Padrão de Código:** Todo código em C submetido nos relatórios deve seguir as diretrizes estabelecidas em [CODING-STANDARD.md](CODING-STANDARD.md) (estilo de indentação GNU, tipos explícitos da `<stdint.h>`, comentários `/* ... */` em português e nomes de registradores idênticos ao *Reference Manual*).
* **Configuração do Gravador ST-LINK:** Usuários de Linux/WSL devem instalar as regras presentes em [`tools/udev/rules.d/`](./tools/udev/rules.d) para permitir a comunicação com o gravador sem necessidade de permissões de `root`.
* **Configurações do VS Code:** A pasta [`tools/vscode/`](./tools/vscode) contém modelos de `tasks.json` e `launch.json` configurados para o Cortex-Debug, OpenOCD e GDB.

---

## 6. Autor e Contato

* **Autor:** Prof. Daniel P. Carvalho
* **E-mail institucional:** [daniel.carvalho@ufu.br](mailto:daniel.carvalho@ufu.br)
* **Unidade:** Faculdade de Engenharia Elétrica (FEELT) — Universidade Federal de Uberlândia (UFU)

---

## 7. Licença

* O código-fonte deste repositório é disponibilizado sob a **[Licença MIT](LICENSE)**.
* O material textual e as apostilas em PDF são distribuídos sob a licença **Creative Commons Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA 4.0)**.

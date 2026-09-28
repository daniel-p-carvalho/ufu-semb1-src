# ufu-semb1-src — Códigos-Fonte e Modelos

Códigos-fonte, modelos e ferramentas da disciplina **Sistemas Embarcados I** (FEELT/UFU).  
Apostila completa e material didático: <https://github.com/daniel-p-carvalho/ufu-embedded-systems>.

---

## 1. Organização do Repositório

O repositório é estruturado em pastas de laboratório (`lab-XX/`), uma por aula, e ferramentas de apoio (`tools/`). Os laboratórios que rodam na placa têm uma subpasta para cada placa suportada (`lab-XX/<placa>/`); os que rodam só no PC não têm.

```text
ufu-semb1-src/
├── README.md               # Este catálogo
├── CODING-STANDARD.md      # Padrão de codificação C da disciplina
├── LICENSE                 # Licença MIT
│
├── tools/                  # Ferramentas e configurações de suporte
│   ├── udev/rules.d/       # Regras udev para adaptadores ST-LINK (V2, V2-1, V3)
│   └── vscode/             # Modelos genéricos de configuração do VS Code
│
├── lab-01/                 # Validação do Ambiente
│   ├── README.md           # Orientações e tabela de placas
│   └── stm32f411-blackpill/
├── lab-02/                 # Do C ao Binário (roda no PC, sem pasta de placa)
└── ...                     # Próximos laboratórios
```

---

## 2. Catálogo de Laboratórios

| Laboratório | Descrição | Semana Sugerida | Placa |
|---|---|:---:|:---:|
| [`lab-01/`](./lab-01) | **Validação do Ambiente:** firmware *blinky* completo para teste da cadeia cruzada (GCC, ST-LINK, OpenOCD, VS Code). | Semana 1 | STM32F411 Blackpill |
| [`lab-02/`](./lab-02) | **Do C ao Binário:** pipeline de compilação no PC e no ARM, Load-Store e convenção AAPCS. | Semana 2 | — (PC) |
| [`lab-03/`](./lab-03) | **`g_a + g_b` em Bare-Metal:** escrita do `startup.c` e do `stm32f411-rom.ld` do zero. | Semana 4 | STM32F411 Blackpill |
| `lab-04/` | **Dissecando o Blinky:** GPIO por registradores, modificador `volatile` e `make`. | Semana 5 | STM32F411 Blackpill |

**Cada pasta contém o estado do projeto no início da aula correspondente.** Um mesmo projeto é desenvolvido ao longo de várias aulas; se você perdeu uma aula, copie a pasta da aula seguinte e continue com a turma. O que se escreve em uma aula aparece pronto na pasta da aula seguinte.

---

## 3. Fluxo de Trabalho do Estudante

Recomendamos que o clone deste repositório seja mantido como **referência imutável**. Para trabalhar em cada aula prática, copie a pasta correspondente para o seu espaço de trabalho pessoal:

```bash
# 1. Atualizar o repositório oficial sem conflitos
cd ~/semb1-workspace/ufu-semb1-src
git pull origin master

# 2. Copiar a pasta da prática do dia (e da sua placa) para a sua área de trabalho
cp -r ~/semb1-workspace/ufu-semb1-src/lab-01/stm32f411-blackpill ~/semb1-workspace/lab-01
cd ~/semb1-workspace/lab-01

# 3. Compilar e gravar
make clean && make
make flash
```

Para depurar no VS Code, abra a pasta copiada (a que contém o `Makefile`). Com exceção do `lab-01`, que já traz a sua `.vscode/`, copie os modelos genéricos de [`tools/vscode/`](./tools/vscode) e adapte-os conforme o `README.md` daquela pasta.

---

## 4. Padrão de Codificação e Licença

* O código em C segue o padrão definido em [CODING-STANDARD.md](CODING-STANDARD.md).
* O código deste repositório é distribuído sob a [Licença MIT](LICENSE). O texto explicativo da apostila segue licença Creative Commons BY-NC-SA.

# ufu-semb1-src — Códigos-Fonte e Modelos

Códigos-fonte, modelos e ferramentas da disciplina **Sistemas Embarcados I** (FEELT/UFU).  
Apostila completa e material didático: <https://github.com/daniel-p-carvalho/ufu-embedded-systems>.

---

## 1. Organização do Repositório

O repositório é estruturado em pastas de laboratório (`lab-XX/`) e ferramentas de apoio (`tools/`):

```text
ufu-semb1-src/
├── README.md               # Este catálogo
├── CODING-STANDARD.md      # Padrão de codificação C da disciplina
├── LICENSE                 # Licença MIT
│
├── tools/                  # Ferramentas e configurações de suporte
│   ├── udev/rules.d/       # Regras udev para adaptadores ST-LINK (V2, V2-1, V3)
│   └── vscode/             # Modelos de configuração para o VS Code (launch, tasks, properties)
│
├── lab-01/                 # Validação do Ambiente (Blackpill + ST-LINK)
└── ...                     # Próximos laboratórios
```

---

## 2. Catálogo de Laboratórios

| Laboratório | Descrição | Semana Sugerida | Placa |
|---|---|:---:|:---:|
| [`lab-01/`](./lab-01) | **Validação do Ambiente:** Firmware *Blinky* completo para teste da cadeia cruzada (GCC, ST-LINK, OpenOCD, VS Code). | Semana 1 | STM32F411 Blackpill |
| `lab-02/` | **Do C ao Binário:** Dissecção do pipeline de compilação, Load-Store e convenção AAPCS. | Semana 2 | — |
| `lab-03/` | **A + B em Bare-Metal:** Escrita guiada de `startup.c` e `stm32f411-rom.ld`. | Semana 3 | STM32F411 Blackpill |
| `lab-04/` | **Dissecando o Blinky:** Controle de GPIO por registradores, modificador `volatile` e `make`. | Semana 4 | STM32F411 Blackpill |

---

## 3. Fluxo de Trabalho do Estudante

Recomendamos que o clone deste repositório seja mantido como **referência imutável**. Para trabalhar em cada aula prática, copie a pasta correspondente para o seu espaço de trabalho pessoal:

```bash
# 1. Atualizar o repositório oficial sem conflitos
cd ~/semb1-workspace/ufu-semb1-src
git pull origin master

# 2. Copiar a pasta da prática do dia para a sua área de trabalho
cp -r ~/semb1-workspace/ufu-semb1-src/lab-01 ~/semb1-workspace/meu-lab-01
cd ~/semb1-workspace/meu-lab-01

# 3. Compilar e gravar
make clean && make
make flash
```

---

## 4. Padrão de Codificação e Licença

* O código em C segue o padrão definido em [CODING-STANDARD.md](CODING-STANDARD.md).
* O código deste repositório é distribuído sob a [Licença MIT](LICENSE). O texto explicativo da apostila segue licença Creative Commons BY-NC-SA.

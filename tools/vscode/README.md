# Modelos de Configuração do VS Code

Modelos genéricos para depurar e compilar os laboratórios da disciplina no VS Code, com a extensão *Cortex-Debug*. Com exceção do `lab-01`, que traz a sua própria `.vscode/`, os laboratórios não incluem configuração do editor: copie estes modelos para o seu projeto e adapte-os.

| Arquivo | Para que serve |
|---|---|
| `launch.json` | Depuração (F5): inicia o OpenOCD, grava o programa e para no `main()` |
| `tasks.json` | Tarefas de compilação (`Ctrl+Shift+B` executa `make`), gravação e limpeza |
| `c_cpp_properties.json` | IntelliSense: compilador cruzado e *defines* do chip |

---

## 1. Onde colocar a `.vscode/`

O VS Code procura a pasta `.vscode/` **na pasta que foi aberta** (**File → Open Folder**), e a variável `${workspaceFolder}` dos arquivos de configuração aponta para essa mesma pasta. Por isso, a `.vscode/` deve ficar na pasta que contém o `Makefile` do projeto, e é essa pasta que deve ser aberta no editor.

Depois de copiar um laboratório para o seu espaço de trabalho:

```bash
cp -r ~/semb1-workspace/ufu-semb1-src/lab-04/stm32f411-blackpill ~/semb1-workspace/lab-04
cp -r ~/semb1-workspace/ufu-semb1-src/tools/vscode ~/semb1-workspace/lab-04/.vscode
rm ~/semb1-workspace/lab-04/.vscode/README.md
```

Abra então `~/semb1-workspace/lab-04` no VS Code.

---

## 2. O que adaptar

### `launch.json`

* **`executable`**: o arquivo ELF gerado pelo `Makefile`. O modelo usa `${workspaceFolder}/blinky.elf`; se o `PROGNAME` do seu `Makefile` for outro, ou se o ELF for gerado em outra pasta (por exemplo, `build/`), ajuste o caminho.
* **`configFiles`**: os arquivos de configuração do OpenOCD. `interface/stlink.cfg` serve para qualquer ST-LINK (externo ou embutido, como o da Nucleo); `target/stm32f4x.cfg` serve para toda a família STM32F4, inclusive o F401 e o F411. Para um chip de outra família, troque o *target* (por exemplo, `target/stm32l4x.cfg`).
* **`name`**: o nome que aparece no menu de depuração; pode ser qualquer um.

### `tasks.json`

As tarefas apenas chamam o `make`. Se o seu projeto não tiver os alvos `flash` e `clean`, remova as tarefas correspondentes.

### `c_cpp_properties.json`

* **`compilerPath`**: o caminho do `arm-none-eabi-gcc`. Descubra com `which arm-none-eabi-gcc`. Se você seguiu o roteiro de instalação da apostila, ele é `/usr/bin/arm-none-eabi-gcc` (um link simbólico para a instalação em `/usr/share`).
* **`defines`**: a macro do chip, usada apenas pelo IntelliSense. O modelo define `STM32F411xE`; para o F401, use `STM32F401xC` ou `STM32F401xE`, conforme o chip.
* **`includePath`**: o modelo inclui todas as subpastas do projeto (`${workspaceFolder}/**`). Acrescente outros caminhos só se o projeto usar cabeçalhos fora da pasta.

---

## 3. Problemas comuns

* **"Failed to launch GDB" ou "executable not found"**: o projeto ainda não foi compilado, ou o `executable` do `launch.json` não corresponde ao nome do ELF. Rode `make` e confira o nome do arquivo gerado.
* **O VS Code não encontra a configuração de depuração**: a pasta aberta no editor não é a que contém a `.vscode/`. Abra a pasta do projeto, e não uma pasta acima dela.
* **O IntelliSense marca `uint32_t` como erro**: confira o `compilerPath` no `c_cpp_properties.json`.

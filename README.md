# ufu-semb1-src

Códigos-fonte da apostila de **Sistemas Embarcados I** (FEELT/UFU), disponível em
<https://github.com/daniel-p-carvalho/ufu-embedded-systems>.

## Organização

Cada projeto fica em um diretório próprio e, dentro dele, há uma versão para cada placa suportada:

```
<projeto>/
└── <placa>/
    ├── Makefile
    ├── <linker script>.ld
    ├── src/
    └── .vscode/launch.json
```

Cada versão é autocontida: não depende de arquivos de outros projetos ou placas.

| Projeto | Descrição | Placas |
|---|---|---|
| [`blinky`](blinky/) | Pisca o LED da placa, acessando o GPIO diretamente por registrador. Usado na validação do ambiente de desenvolvimento. | `stm32f411-blackpill` |

## Uso

Com o ambiente configurado conforme o roteiro *Ambiente e Ferramentas* da apostila:

```console
git clone https://github.com/daniel-p-carvalho/ufu-semb1-src.git
cd ufu-semb1-src/blinky/stm32f411-blackpill
make          # compila
make flash    # grava na placa via ST-LINK (st-flash)
make openocd  # inicia o servidor OpenOCD (em um terminal separado)
make debug    # conecta o GDB ao OpenOCD
```

Para depurar no VS Code, abra a pasta da placa (por exemplo, `blinky/stm32f411-blackpill`) e use a configuração do Cortex-Debug em `.vscode/launch.json`.

## Licença

O código deste repositório é distribuído sob a [licença MIT](LICENSE). O texto da apostila ([ufu-embedded-systems](https://github.com/daniel-p-carvalho/ufu-embedded-systems)) segue licença própria (Creative Commons BY-NC-SA).

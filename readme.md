#  Gestor de Listas

Programa em C para gerenciamento de listas de atividades via terminal, utilizando arquivos `.txt` como armazenamento persistente.

##  Funcionalidades

- **Criar lista** — cria um novo arquivo `.txt` para armazenar atividades
- **Remover lista** — deleta um arquivo de lista existente
- **Renomear lista** — renomeia um arquivo de lista
- **Adicionar item** — insere um novo item numerado ao final da lista
- **Remover item** — remove um item da lista com renumeração automática
- **Ver conteúdo** — exibe todos os itens de uma lista no terminal

##  Tecnologias

- Linguagem: **C**
- Compilador: **GCC**
- Sistema de arquivos: manipulação via `stdio.h` (`fopen`, `fclose`, `fprintf`, `fgets`)

##  Estrutura do projeto

```
gestor_listas/
├── gestor_listas.c      # Código principal
├── gestor_listas.h      # Protótipos das funções
└── README.md            # Documentação
```

##  Como usar

1. Execute o programa
2. Escolha uma opção no menu digitando o número correspondente
3. Siga as instruções na tela
4. Os arquivos `.txt` são criados na mesma pasta do executável

##  Observações

- O nome dos arquivos deve incluir a extensão `.txt` (ex: `compras.txt`)
- Não utilize caracteres especiais no nome dos arquivos
- Os itens são numerados automaticamente pelo programa


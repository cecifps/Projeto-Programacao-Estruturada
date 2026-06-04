# Sistema de Controle de Livros em C

Projeto desenvolvido em linguagem C para gerenciamento de um catálogo de livros utilizando manipulação de arquivos, vetores e structs.

## Sobre o Projeto

O sistema realiza a leitura de um arquivo texto contendo informações sobre livros e permite ao usuário realizar operações de consulta e gerenciamento através de um menu interativo.

Os livros são carregados para memória durante a execução e podem ser visualizados, pesquisados e organizados por ano de publicação.

## Funcionalidades

- Carregamento automático dos dados a partir de arquivo
- Cadastro de novos livros
- Busca de livros por código
- Listagem completa do catálogo
- Ordenação dos livros por ano de publicação
- Menu interativo no terminal

## Estrutura do Projeto

```text
sistema-controle-livros-c
│
├── codigobiblioteca.c
├── livros.txt
└── README.md
```

## Estrutura do Arquivo de Dados

O sistema utiliza um arquivo chamado `livros.txt`.

Exemplo:

```text
101 Algoritmos 2020 5
102 BancoDeDados 2018 3
103 Redes 2022 7
104 Compiladores 2015 2
105 EstruturasDeDados 2021 6
```

Cada linha possui:

| Campo | Descrição |
|---------|---------|
| Código | Identificador único do livro |
| Título | Nome do livro |
| Ano | Ano de publicação |
| Quantidade | Quantidade disponível |

## Tecnologias Utilizadas

- Linguagem C
- stdio.h
- stdlib.h
- string.h

## Conceitos Aplicados

- Structs
- Vetores
- Manipulação de arquivos
- Busca sequencial
- Ordenação (Bubble Sort)
- Funções
- Estruturas condicionais
- Estruturas de repetição

## Como Compilar

```bash
gcc main.c -o biblioteca
```

## Como Executar

Linux/Mac:

```bash
./biblioteca
```

Windows:

```bash
biblioteca.exe
```

## Exemplo de Menu

```text
====== SISTEMA DE CONTROLE DE LIVROS ======

1. Adicionar livro
2. Buscar livro por codigo
3. Imprimir livros
4. Ordenar por ano e imprimir
5. Sair
```

## Melhorias Futuras

- Persistência automática de novos livros no arquivo
- Remoção de livros
- Atualização de registros
- Busca por título
- Ordenação por quantidade disponível
- Interface gráfica

## Autora

Cecília Galindo

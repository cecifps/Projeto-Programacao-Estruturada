#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100
#define TAM_TITULO 50

typedef struct {
    int codigo;
    char titulo[TAM_TITULO];
    int ano;
    int quantidade;
} Livro;

Livro biblioteca[MAX_LIVROS];
int totalLivros = 0;

void lerArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro: nao foi possível abrir o arquivo '%s'.\n", nomeArquivo);
        return;
    }

    while (totalLivros < MAX_LIVROS &&
       fscanf(arquivo, "%d %49s %d %d", &biblioteca[totalLivros].codigo,
            biblioteca[totalLivros].titulo,
            &biblioteca[totalLivros].ano,
            &biblioteca[totalLivros].quantidade) == 4) {
        totalLivros++;
    }

    fclose(arquivo);
    printf("%d livros carregados do arquivo '%s'.\n\n", totalLivros, nomeArquivo);
}

void adicionarLivro() {
    if (totalLivros >= MAX_LIVROS) {
        printf("Capacidade maxima atingida!\n");
        return;
    }

    Livro novo;
    printf("Codigo: ");
    scanf("%d", &novo.codigo);
    printf("Titulo (sem espacos): ");
    scanf("%s", novo.titulo);
    printf("Ano de publicacao: ");
    scanf("%d", &novo.ano);
    printf("Quantidade disponivel: ");
    scanf("%d", &novo.quantidade);

    biblioteca[totalLivros] = novo;
    totalLivros++;
    printf("Livro adicionado com sucesso!\n");
}

void buscarPorCodigo() {
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalLivros; i++) {
        if (biblioteca[i].codigo == codigo) {
            printf("\nLivro encontrado:\n");
            printf("  Codigo    : %d\n", biblioteca[i].codigo);
            printf("  Titulo    : %s\n", biblioteca[i].titulo);
            printf("  Ano       : %d\n", biblioteca[i].ano);
            printf("  Quantidade: %d\n", biblioteca[i].quantidade);
            return;
        }
    }
    printf("Livro com codigo %d não encontrado.\n", codigo);
}

void imprimirLivros() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    printf("%-8s %-35s %-6s %-10s\n", "Codigo", "Totulo", "Ano", "Qtd");
    for (int i = 0; i < totalLivros; i++) {
        printf("%-8d %-35s %-6d %-10d\n",
               biblioteca[i].codigo,
               biblioteca[i].titulo,
               biblioteca[i].ano,
               biblioteca[i].quantidade);
    }
}

void ordenarPorAnoEImprimir() {
   
    Livro copia[MAX_LIVROS];
    for (int i = 0; i < totalLivros; i++) {
        copia[i] = biblioteca[i];
    }
    for (int i = 0; i < totalLivros - 1; i++) {
        for (int j = 0; j < totalLivros - 1 - i; j++) {
            if (copia[j].ano > copia[j + 1].ano) {
                Livro temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("%-8s %-35s %-6s %-10s\n", "Codigo", "Totulo", "Ano", "Qtd");
    for (int i = 0; i < totalLivros; i++) {
        printf("%-8d %-35s %-6d %-10d\n",
               copia[i].codigo,
               copia[i].titulo,
               copia[i].ano,
               copia[i].quantidade);
    }
}

void exibirMenu() {
    printf("\n\n====== SISTEMA DE CONTROLE DE LIVROS ======\n");
    printf("1. Adicionar livro\n");
    printf("2. Buscar livro por codigo\n");
    printf("3. Imprimir livros\n");
    printf("4. Ordenar por ano e imprimir\n");
    printf("5. Sair\n");
    printf("Escolha: ");
}

int main() {
    lerArquivo("livros.txt");

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                adicionarLivro();           
                break;
            case 2: 
                buscarPorCodigo();          
                break;
            case 3: 
                imprimirLivros();           
                break;
            case 4: 
                ordenarPorAnoEImprimir();   
                break;
            case 5: 
                printf("Encerrando.\n");  
                break;
            default: 
                printf("Opcao inválida!\n");
            }
        } while (opcao != 5);

    return 0;
}
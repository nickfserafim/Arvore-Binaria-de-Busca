#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);

    if (valor < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->chave) {
        raiz->direita = inserir(raiz->direita, valor);
    } else {
        printf("\n[Aviso] O valor %d ja existe na arvore!\n", valor);
    }
    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->chave == valor) return raiz;
    if (valor < raiz->chave) return buscar(raiz->esquerda, valor);
    return buscar(raiz->direita, valor);
}

// NOVA FUNÇÃO: Exibe a árvore graficamente (deitada)
// O espaço (espaco) aumenta a cada nível de profundidade
void exibirArvore2D(No* raiz, int espaco) {
    // Caso base
    if (raiz == NULL) return;

    // Aumenta a distância entre os níveis
    espaco += 5;

    // Processa o filho da DIREITA primeiro (topo do terminal)
    exibirArvore2D(raiz->direita, espaco);

    // Imprime o nó atual após os espaços
    printf("\n");
    for (int i = 5; i < espaco; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->chave);

    // Processa o filho da ESQUERDA (baixo do terminal)
    exibirArvore2D(raiz->esquerda, espaco);
}

int main() {
    No* raiz = NULL;
    int opcao, valor;

    do {
        printf("\n=== MENU ARVORE BINARIA DE BUSCA ===");
        printf("\n1. Inserir um numero");
        printf("\n2. Buscar um numero");
        printf("\n3. Visualizar Estrutura da Arvore (Grafico)");
        printf("\n0. Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o numero: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("Digite o numero para buscar: ");
                scanf("%d", &valor);
                if (buscar(raiz, valor) != NULL) printf("[Achei!]\n");
                else printf("[Nao encontrado]\n");
                break;
            case 3:
                printf("\n--- ESTRUTURA DA ARVORE (Gire a cabeca para a esquerda para ver em pé) ---\n");
                if (raiz == NULL) printf("Arvore vazia.\n");
                else exibirArvore2D(raiz, 0);
                printf("\n-------------------------------------------------------------------------\n");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}

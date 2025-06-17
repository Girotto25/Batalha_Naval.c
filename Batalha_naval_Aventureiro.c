#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA '0'
#define NAVIO_MAR '3'

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n    ");
    for (int c = 0; c < TAM; c++) {
        printf("%2d ", c);
    }
    printf("\n");

    for (int l = 0; l < TAM; l++) {
        printf("%2d |", l);
        for (int c = 0; c < TAM; c++) {
            printf(" %c ", tabuleiro[l][c]);
        }
        printf("\n");
    }
}

// Função para verificar se há sobreposição
int podeColocar(char tabuleiro[TAM][TAM], int l[], int c[]) {
    for (int i = 0; i < NAVIO; i++) {
        if (l[i] < 0 || l[i] >= TAM || c[i] < 0 || c[i] >= TAM)
            return 0;
        if (tabuleiro[l[i]][c[i]] != AGUA)
            return 0;
    }
    return 1;
}

// Função para posicionar um navio
void posicionarNavio(char tabuleiro[TAM][TAM], int l[], int c[]) {
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[l[i]][c[i]] = NAVIO_MAR;
    }
}

int main() {
    char tabuleiro[TAM][TAM];

    // Inicializar o tabuleiro com '0' (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 1º navio - horizontal
    int l1[] = {1, 1, 1};
    int c1[] = {2, 3, 4};
    if (podeColocar(tabuleiro, l1, c1))
        posicionarNavio(tabuleiro, l1, c1);

    // 2º navio - vertical
    int l2[] = {4, 5, 6};
    int c2[] = {7, 7, 7};
    if (podeColocar(tabuleiro, l2, c2))
        posicionarNavio(tabuleiro, l2, c2);

    // 3º navio - diagonal ↘
    int l3[] = {0, 1, 2};
    int c3[] = {0, 1, 2};
    if (podeColocar(tabuleiro, l3, c3))
        posicionarNavio(tabuleiro, l3, c3);

    // 4º navio - diagonal ↙
    int l4[] = {0, 1, 2};
    int c4[] = {9, 8, 7};
    if (podeColocar(tabuleiro, l4, c4))
        posicionarNavio(tabuleiro, l4, c4);

    // Exibir o tabuleiro
    printf("Tabuleiro Final:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}

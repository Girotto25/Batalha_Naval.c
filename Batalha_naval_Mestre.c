#include <stdio.h>

#define TAM 10
#define HABSZ 5 // Tamanho das matrizes de habilidades (5x5)
#define AGUA '0'
#define NAVIO '3'
#define HABILIDADE '5'

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n    ");
    for (int c = 0; c < TAM; c++) printf("%2d ", c);
    printf("\n");

    for (int l = 0; l < TAM; l++) {
        printf("%2d |", l);
        for (int c = 0; c < TAM; c++) {
            printf(" %c ", tabuleiro[l][c]);
        }
        printf("\n");
    }
}

// Verifica se pode colocar navio
int podeColocar(char tabuleiro[TAM][TAM], int l[], int c[]) {
    for (int i = 0; i < 3; i++) {
        if (l[i] < 0 || l[i] >= TAM || c[i] < 0 || c[i] >= TAM)
            return 0;
        if (tabuleiro[l[i]][c[i]] != AGUA)
            return 0;
    }
    return 1;
}

// Posiciona navio
void posicionarNavio(char tabuleiro[TAM][TAM], int l[], int c[]) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[l[i]][c[i]] = NAVIO;
    }
}

// Cria matriz Cone (1 no centro e expandindo para baixo)
void criarCone(int habilidade[HABSZ][HABSZ]) {
    for (int i = 0; i < HABSZ; i++) {
        for (int j = 0; j < HABSZ; j++) {
            habilidade[i][j] = 0;
        }
    }
    for (int i = 0; i < HABSZ; i++) {
        for (int j = HABSZ/2 - i; j <= HABSZ/2 + i; j++) {
            if (j >= 0 && j < HABSZ)
                habilidade[i][j] = 1;
        }
    }
}

// Cria matriz Cruz (linha e coluna centrais com 1)
void criarCruz(int habilidade[HABSZ][HABSZ]) {
    for (int i = 0; i < HABSZ; i++) {
        for (int j = 0; j < HABSZ; j++) {
            habilidade[i][j] = (i == HABSZ/2 || j == HABSZ/2) ? 1 : 0;
        }
    }
}

// Cria matriz Octaedro (formato de losango)
void criarOctaedro(int habilidade[HABSZ][HABSZ]) {
    for (int i = 0; i < HABSZ; i++) {
        for (int j = 0; j < HABSZ; j++) {
            int dist = abs(i - HABSZ/2) + abs(j - HABSZ/2);
            habilidade[i][j] = (dist <= HABSZ/2) ? 1 : 0;
        }
    }
}

// Aplica a matriz de habilidade no tabuleiro
void aplicarHabilidade(char tabuleiro[TAM][TAM], int origem_l, int origem_c, int habilidade[HABSZ][HABSZ]) {
    for (int i = 0; i < HABSZ; i++) {
        for (int j = 0; j < HABSZ; j++) {
            int lin = origem_l - HABSZ/2 + i;
            int col = origem_c - HABSZ/2 + j;

            if (lin >= 0 && lin < TAM && col >= 0 && col < TAM && habilidade[i][j] == 1) {
                if (tabuleiro[lin][col] == AGUA)
                    tabuleiro[lin][col] = HABILIDADE;
            }
        }
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    int habilidade[HABSZ][HABSZ];

    // Inicializar tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // Posicionar navios
    int l1[] = {1, 1, 1}; int c1[] = {2, 3, 4}; // horizontal
    int l2[] = {4, 5, 6}; int c2[] = {7, 7, 7}; // vertical
    int l3[] = {0, 1, 2}; int c3[] = {0, 1, 2}; // diagonal ↘
    int l4[] = {0, 1, 2}; int c4[] = {9, 8, 7}; // diagonal ↙

    if (podeColocar(tabuleiro, l1, c1)) posicionarNavio(tabuleiro, l1, c1);
    if (podeColocar(tabuleiro, l2, c2)) posicionarNavio(tabuleiro, l2, c2);
    if (podeColocar(tabuleiro, l3, c3)) posicionarNavio(tabuleiro, l3, c3);
    if (podeColocar(tabuleiro, l4, c4)) posicionarNavio(tabuleiro, l4, c4);

    // Criar habilidade e aplicar
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, 5, 5, habilidade); // ponto de origem do cone

    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, 2, 2, habilidade); // ponto de origem da cruz

    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, 7, 2, habilidade); // ponto de origem do octaedro

    // Mostrar resultado
    printf("\nTABULEIRO FINAL COM HABILIDADES:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}

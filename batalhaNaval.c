#include <stdio.h>

#define TAM 10

void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf(". ");
            else if (tabuleiro[i][j] == 3) printf("N ");
            else if (tabuleiro[i][j] == 5) printf("* ");
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[5][5], int origem_linha, int origem_coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int lin = origem_linha - 2 + i;
                int col = origem_coluna - 2 + j;
                if (lin >= 0 && lin < TAM && col >= 0 && col < TAM && tabuleiro[lin][col] == 0) {
                    tabuleiro[lin][col] = 5;
                }
            }
        }
    }
}

void criarCone(int habilidade[5][5]) {
    int centro = 2;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = (abs(j - centro) <= i) ? 1 : 0;
}

void criarCruz(int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        habilidade[i][2] = 1;
        habilidade[2][i] = 1;
    }
}

void criarOctaedro(int habilidade[5][5]) {
    int centro = 2;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = (abs(i - centro) + abs(j - centro) <= centro) ? 1 : 0;
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Navio horizontal exemplo
    for (int i = 0; i < 3; i++)
        tabuleiro[2][3 + i] = 3;

    int cone[5][5], cruz[5][5], octaedro[5][5];
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 6, 5);
    aplicarHabilidade(tabuleiro, cruz, 3, 3);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    imprimirTabuleiro(tabuleiro);
    return 0;
}

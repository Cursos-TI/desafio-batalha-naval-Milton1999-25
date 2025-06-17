#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define MAR 0
#define NAVIO 3

// Função para verificar se é possível posicionar o navio sem sair dos limites e sem sobreposição
bool pode_posicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (diagonal == 1) {        // Diagonal principal ↘
            l += i;
            c += i;
        } else if (diagonal == 2) { // Diagonal secundária ↙
            l += i;
            c -= i;
        } else if (direcao == 0) {  // Horizontal →
            c += i;
        } else if (direcao == 1) {  // Vertical ↓
            l += i;
        }

        // Verificação de limites
        if (l >= TAMANHO_TABULEIRO || l < 0 || c >= TAMANHO_TABULEIRO || c < 0) {
            return false;
        }

        // Verificação de sobreposição
        if (tabuleiro[l][c] != MAR) {
            return false;
        }
    }
    return true;
}

// Função para posicionar o navio no tabuleiro
void posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == 2) {
            l += i;
            c -= i;
        } else if (direcao == 0) {
            c += i;
        } else if (direcao == 1) {
            l += i;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Cabeçalho de colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Cabeçalho de linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa tudo com 0

    // Coordenadas e direções dos navios
    // Navios retos
    int navios_retos[2][3] = {
        {2, 1, 0}, // linha, coluna, direção (0 = horizontal)
        {0, 5, 1}  // linha, coluna, direção (1 = vertical)
    };

    // Navios diagonais
    int navios_diagonais[2][2] = {
        {5, 0}, // linha, coluna para diagonal principal ↘
        {4, 9}  // linha, coluna para diagonal secundária ↙
    };

    // Posiciona navios retos
    for (int i = 0; i < 2; i++) {
        int linha = navios_retos[i][0];
        int coluna = navios_retos[i][1];
        int direcao = navios_retos[i][2];

        if (pode_posicionar(tabuleiro, linha, coluna, direcao, 0)) {
            posicionar_navio(tabuleiro, linha, coluna, direcao, 0);
        } else {
            printf("Não foi possível posicionar o navio reto %d\n", i + 1);
        }
    }

    // Posiciona navios diagonais
    for (int i = 0; i < 2; i++) {
        int linha = navios_diagonais[i][0];
        int coluna = navios_diagonais[i][1];
        int diagonal = (i == 0) ? 1 : 2; // 1 = ↘, 2 = ↙

        if (pode_posicionar(tabuleiro, linha, coluna, -1, diagonal)) {
            posicionar_navio(tabuleiro, linha, coluna, -1, diagonal);
        } else {
            printf("Não foi possível posicionar o navio diagonal %d\n", i + 1);
        }
    }

    // Exibe o tabuleiro final
    exibir_tabuleiro(tabuleiro);

    return 0;
}

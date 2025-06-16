c

#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define OCUPADO 3
#define LIVRE 0

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se um navio pode ser posicionado sem sair do tabuleiro e sem sobreposição
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, char tipo) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (tipo == 'H') c += i;
        else if (tipo == 'V') l += i;
        else if (tipo == 'D') { l += i; c += i; }
        else if (tipo == 'A') { l += i; c -= i; }

        if (l < 0 || l >= TAM || c < 0 || c >= TAM) return 0;
        if (tabuleiro[l][c] != LIVRE) return 0;
    }
    return 1;
}

// Posiciona o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char tipo) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (tipo == 'H') c += i;
        else if (tipo == 'V') l += i;
        else if (tipo == 'D') { l += i; c += i; }
        else if (tipo == 'A') { l += i; c -= i; }

        tabuleiro[l][c] = OCUPADO;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Navio 1 - Horizontal
    int l1 = 2, c1 = 1;
    if (podePosicionar(tabuleiro, l1, c1, 0, 'H')) {
        posicionarNavio(tabuleiro, l1, c1, 'H');
    }

    // Navio 2 - Vertical
    int l2 = 0, c2 = 7;
    if (podePosicionar(tabuleiro, l2, c2, 0, 'V')) {
        posicionarNavio(tabuleiro, l2, c2, 'V');
    }

    // Navio 3 - Diagonal Principal ↘️ (tipo 'D')
    int l3 = 4, c3 = 0;
    if (podePosicionar(tabuleiro, l3, c3, 0, 'D')) {
        posicionarNavio(tabuleiro, l3, c3, 'D');
    }

    // Navio 4 - Diagonal Secundária ↙️ (tipo 'A')
    int l4 = 1, c4 = 9;
    if (podePosicionar(tabuleiro, l4, c4, 0, 'A')) {
        posicionarNavio(tabuleiro, l4, c4, 'A');
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}

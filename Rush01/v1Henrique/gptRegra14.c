#include <stdio.h>
#include <unistd.h> // Para usar a função write

#define N 4  // Tamanho do grid

// Matriz para armazenar o tabuleiro
int matriz[N][N];

// Dicas nas bordas
int top[N], bottom[N], left[N], right[N];

// Função para inicializar a matriz
void inicializarMatriz() {
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            matriz[i][j] = 0;  // Inicializa todas as posições com 0
}

// Função para preencher uma linha de forma crescente (de 1 a N)
void preencherLinhaCrescente(int linha) {
    for(int j = 0; j < N; j++) {
        matriz[linha][j] = j + 1; // Preenche com 1, 2, 3, ..., N
    }
}

// Função para preencher uma coluna de forma crescente (de 1 a N)
void preencherColunaCrescente(int col) {
    for(int i = 0; i < N; i++) {
        matriz[i][col] = i + 1; // Preenche com 1, 2, 3, ..., N
    }
}

// Função para aplicar as regras e preencher a matriz
void aplicarRegras() {
    // Verifica e aplica as regras para as bordas (top, bottom, left, right)
    
    // Se a dica de cima for igual ao tamanho do grid, preenche a linha superior
    for(int col = 0; col < N; col++) {
        if(top[col] == N) {
            preencherColunaCrescente(col); // Preenche coluna com valores crescentes
        }
    }
    
    // Se a dica de baixo for igual ao tamanho do grid, preenche a linha inferior
    for(int col = 0; col < N; col++) {
        if(bottom[col] == N) {
            preencherColunaCrescente(col); // Preenche coluna com valores crescentes
        }
    }
    
    // Se a dica de esquerda for igual ao tamanho do grid, preenche a linha esquerda
    for(int row = 0; row < N; row++) {
        if(left[row] == N) {
            preencherLinhaCrescente(row); // Preenche linha com valores crescentes
        }
    }
    
    // Se a dica de direita for igual ao tamanho do grid, preenche a linha direita
    for(int row = 0; row < N; row++) {
        if(right[row] == N) {
            preencherLinhaCrescente(row); // Preenche linha com valores crescentes
        }
    }
}

// Função para imprimir a matriz usando write
void imprimirMatriz() {
    char buffer[20]; // Buffer para armazenar a saída como string temporária
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // Cria a string de números para cada valor na matriz
            int len = snprintf(buffer, sizeof(buffer), "%2d ", matriz[i][j]);
            write(1, buffer, len);  // Escreve o número no terminal (descritor 1 -> stdout)
        }
        write(1, "\n", 1);  // Nova linha após cada linha da matriz
    }
}

// Função para ler as dicas do usuário
void lerDicas() {
    // Lê as dicas das bordas superior e inferior
    write(1, "Digite as dicas para a borda superior (top):\n", 43);
    for (int i = 0; i < N; i++) {
        char buffer[10];
        write(1, "top[", 4);
        snprintf(buffer, sizeof(buffer), "%d", i);
        write(1, buffer, strlen(buffer));
        write(1, "]: ", 3);
        scanf("%d", &top[i]);
    }

    write(1, "Digite as dicas para a borda inferior (bottom):\n", 48);
    for (int i = 0; i < N; i++) {
        char buffer[10];
        write(1, "bottom[", 7);
        snprintf(buffer, sizeof(buffer), "%d", i);
        write(1, buffer, strlen(buffer));
        write(1, "]: ", 3);
        scanf("%d", &bottom[i]);
    }

    // Lê as dicas para as bordas esquerda e direita
    write(1, "Digite as dicas para a borda esquerda (left):\n", 47);
    for (int i = 0; i < N; i++) {
        char buffer[10];
        write(1, "left[", 5);
        snprintf(buffer, sizeof(buffer), "%d", i);
        write(1, buffer, strlen(buffer));
        write(1, "]: ", 3);
        scanf("%d", &left[i]);
    }

    write(1, "Digite as dicas para a borda direita (right):\n", 48);
    for (int i = 0; i < N; i++) {
        char buffer[10];
        write(1, "right[", 6);
        snprintf(buffer, sizeof(buffer), "%d", i);
        write(1, buffer, strlen(buffer));
        write(1, "]: ", 3);
        scanf("%d", &right[i]);
    }
}

int main() {
    // Inicializa a matriz com valores 0
    inicializarMatriz();

    // Lê as dicas do usuário
    lerDicas();

    // Aplica as regras e preenche a matriz com base nas dicas
    aplicarRegras();

    // Imprime a matriz resultante
    imprimirMatriz();

    return 0;
}

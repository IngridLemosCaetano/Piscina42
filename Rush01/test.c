#include <unistd.h>
#include <stdio.h>

int is_valid(char grid[], int n, int row, int col, int num) {
    // Verifica se o número já existe na linha
    int i = 0;
    while (i < n) {
        if (grid[row * n + i] == num + '0') {
            return 0; // Já existe na linha
        }
        i++;
    }
    // Verifica se o número já existe na coluna
    i = 0;
    while (i < n) {
        if (grid[i * n + col] == num + '0') {
            return 0; // Já existe na coluna
        }
        i++;
    }
    return 1;
}

int backtrack(char grid[], int n, int index) {
    if (index == n * n) {
        return 1; // Solução encontrada
    }

    int row = index / n;
    int col = index % n;

    if (grid[index] != '0') {
        return backtrack(grid, n, index + 1); // Pular as posições já preenchidas
    }

    int num = 1;
    while (num <= n) {
        if (is_valid(grid, n, row, col, num)) {
            grid[index] = num + '0'; // Preencher a posição com o número
            if (backtrack(grid, n, index + 1)) {
                return 1; // Recursão bem-sucedida
            }
            grid[index] = '0'; // Desfazer o preenchimento (backtrack)
        }
        num++;
    }

    return 0; // Não encontrou solução
}

void printgrid(char grid[], int n) {
    int i = 0;
    while (i < n * n) {
        write(1, &grid[i], 1);
        write(1, " ", 1);
        if ((i + 1) % n == 0) {
            write(1, "\n", 1);
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    char tips[37]; // Array para armazenar as dicas
    char grid[82]; // Grid para armazenar a matriz
    int i, n;

    if (argc < 17 || argc > 37 || ((argc - 1) % 4 != 0)) {
        write(1, "Número de argumentos inválido\n", 31);
        return 0;
    }

    i = 0;
    while (i++ < argc - 1) {
        tips[i - 1] = *argv[i]; // Copiar as dicas da entrada
    }
    tips[i] = '\0';
    n = (argc - 1) / 4; // Determina o tamanho da matriz (n x n)

    i = 0;
    while (i < (n * n)) {
        grid[i] = '0'; // Inicializar o grid com '0'
        i++;
    }
    grid[i] = '\0';

    // Preencher as posições fornecidas (dicas)
    int idx = 0;
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            grid[i * n + j] = tips[idx++] + '0'; // Preencher as dicas
        }
    }

    if (backtrack(grid, n, 0)) {
        printgrid(grid, n); // Imprimir a solução
    } else {
        write(1, "Não foi possível resolver o quebra-cabeça.\n", 42);
    }

    return 0;
}

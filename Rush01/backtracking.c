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
    // Verifica se a soma da linha e da coluna não ultrapassa o valor desejado
    int row_sum = 0, col_sum = 0;
    i = 0;
    while (i < n) {
        if (grid[row * n + i] != '0') {
            row_sum += grid[row * n + i] - '0';
        }
        if (grid[i * n + col] != '0') {
            col_sum += grid[i * n + col] - '0';
        }
        i++;
    }
    if (row_sum + num > 10 || col_sum + num > 10) {
        return 0; // Soma ultrapassa o limite
    }
    return 1;
}

int backtrack(char grid[], int n, int index) {
    if (index == (n + 1) * (n -1)) {
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
    char tips[37];
    char grid[82];
    int i, n;

    if (argc < 17 || argc > 37 || ((argc - 1) % 4 != 0)) {
        write(1, "Número de argumentos inválido\n", 31);
        return 0;
    }

    i = 0;
    while (i++ < argc - 1) {
        tips[i - 1] = *argv[i];
    }
    tips[i] = '\0';
    n = (argc - 1) / 4;

    i = 0;
    while (i < (n * n)) {
        grid[i] = '0'; // Inicializar o grid com '0'
        i++;
    }
    grid[i] = '\0';

    // Preencher as posições fornecidas (da variável tips)
    // Aqui o preenchimento de dicas (tips) será feito conforme a lógica específica do problema.

    if (backtrack(grid, n, 0)) {
        printgrid(grid, n);
    } else {
        write(1, "Não foi possível resolver o quebra-cabeça.\n", 42);
    }

    return 0;
}

#include <unistd.h>
#include <stdbool.h>

int ft_tip_to_position(int tip_index, int N) {
    if (tip_index < N) {
        return tip_index;  // Borda superior
    } else if (tip_index < 2 * N) {
        return (N - 1) * N + (tip_index - N);  // Borda inferior
    } else if (tip_index < 3 * N) {
        return (tip_index - 2 * N) * N;  // Borda esquerda
    } else {
        return (tip_index - 3 * N) * N + (N - 1);  // Borda direita
    }
}

// Função para eliminar um número das possibilidades de uma célula
void eliminar_possibilidade(char grid[], int i, int j, int n) {
    // Aqui estamos considerando que a célula é um número e que '0' representa uma célula sem valor
    if (grid[i * n + j] != '0') {
        grid[i * n + j] = '0';  // Elimina a possibilidade (marca como '0')
    }
}

// Função para preencher as células com base nas dicas
void fillexact(char grid[], char tips[], int n) {
    int i = 0, j = 0, k = 0, num;

    // Inicializa o grid com '0' para todas as células
    while (i < n * n) {
        grid[i] = '0';  // Marca todas as células como não preenchidas
        i++;
    }

    // Processar as dicas e preencher as células
    i = 0;
    while (i < n * 4) {
        num = tips[i] - '0';  // Converte a dica em número
        k = ft_tip_to_position(i, n);  // Calcula a posição no grid

        // Processamento das dicas
        if (i < n) {  // Borda superior
            j = 0;
            while (j < n) {
                // Se a célula estiver vazia, preenche com o valor da dica
                if (grid[k] == '0') {
                    grid[k] = '0' + num;  // Preenche com o número da dica
                }
                k++;  // Avança para a próxima célula
                j++;
            }
        } else if (i >= n && i < 2 * n) {  // Borda inferior
            j = 0;
            while (j < n) {
                // Se a célula estiver vazia, preenche com o valor da dica
                if (grid[k] == '0') {
                    grid[k] = '0' + num;  // Preenche com o número da dica
                }
                k++;  // Avança para a próxima célula
                j++;
            }
        }
        // Adicione outras condições para as bordas esquerda e direita, se necessário.
        i++;
    }
}

// Função para imprimir o grid
void printgrid(char grid[], int n) {
    int i = 0;

    // Imprime o grid linha por linha
    while (i < n * n) {
        write(1, &grid[i], 1);
        write(1, " ", 1);

        // Quebra linha a cada `n` elementos
        if ((i + 1) % n == 0) {
            write(1, "\n", 1);
        }

        i++;
    }
}

int main(int argc, char *argv[]) {
    char tips[37];
    char grid[82];  // Matriz do grid, de acordo com o tamanho máximo
    int i = 0, n;

    // Verificação dos argumentos
    if (argc < 17 || argc > 37 || ((argc - 1) % 4 != 0)) {
        write(1, "Número de argumentos inválido\n", 31);
        return 0;
    }

    // Copia as dicas (tips) para o array tips
    while (i < argc - 1) {
        tips[i] = *argv[i + 1];
        i++;
    }
    tips[i] = '\0';

    // Define o tamanho do grid baseado no número de argumentos
    n = (argc - 1) / 4;

    // Inicializa o grid com valores '0'
    i = 0;
    while (i < n * n) {
        grid[i] = '0';  // Inicializa todas as células com '0' (sem valor definido)
        i++;
    }

    // Preenche o grid com as dicas e restrições
    fillexact(grid, tips, n);

    // Imprime o grid final
    printgrid(grid, n);

    return 0;
}

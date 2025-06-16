#include <unistd.h>

void fillexact (char grid[], char tips[], int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while(tips[i] != '\0')
	{
		if (i < n) // tratamento vertical de cima pra baixo
		{
			if (tips[i] == '1' && (tips[i + n] == '0' + n))
			{
				k = i; // posicao no grid
				j = 0;
				while (k < (i + (n * n)))
				{ 
					grid[k] = '0' + n - j;
					k += 4;
					j++;
				}
			}
			if ((tips[i] == '0' + n) && (tips[i + n] == '1'))
			{
				k = i; // posicao no grid
				j = n - 1;
				while (k < (i + (n * (n - 1))))
				{ 
					grid[k] = '0' + n - j;
					k += 4;
					j--;
				}
			}
		}
		i++;
	}
}

void printgrid(char grid[], int n)
{
	int	i;

	i = 0;
	while (grid[i] != '\0')
	{
		write (1, &grid[i], 1);
		write (1, " ", 1);
		i++;
		if (i % n == 0)
		{
			write (1, "\n", 1);
		}
	}
}

int main(int argc, char *argv[])
{
	char	tips[37];
	char	grid[82];
	int	i;
	int	n;

	if (argc < 17 || argc > 37 || ((argc - 1) % 4 != 0))  // define, se acordo com as dicas, matrizes de ordem 4 a 9
	{
		write(1, "Número de argumentos inválido\n", 31);
		return (0);
	}
	i = 0;
	while (i++ < argc - 1)
	{
		tips [i - 1] = *argv[i];
	}
	tips [i] = '\0';
	n = (argc - 1) / 4;
	i = 0;
	while (i < (n*n))
	{
		grid[i] = '0';
		i++;
	}
	grid[i] = '\0';
	fillexact(grid, tips, n);
	printgrid(grid, n);
	return (0);
}

#include <unistd.h>

void printgrid(char grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &grid[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

void	fillexact(char grid[4][4], char tips[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 16) 
	{
		if (tips[i] == '4' && tips[i + 4] == '1' && i < 4)
		{
			grid[0][i] = '1';
			grid[1][i] = '2';
			grid[2][i] = '3';
			grid[3][i] = '4';
		}
		else if (tips[i] == '4' && tips[i + 4] == '1' && (i  > 7 && i < 12))
		{
			grid[i-8][0] = '1';
			grid[i-8][1] = '2';
			grid[i-8][2] = '3';
			grid[i-8][3] = '4';
		}
		i++;
	}
}

int main(int argc, char *argv[])
{

	char	tips[16];
	int	i;

char	 grid[4][4] = {
        {'0', '1', '2', '3'},
        {'4', '5', '6', '7'},
        {'8', '9', 'a', 'b'},
        {'c', 'd', 'e', 'f'}
    };
    
	i = 0;
	while ( i++ < argc - 1)
	{
		tips[i - 1] = *argv[i];
	}
	fillexact(grid, tips);
	printgrid(grid) ;
	return (0);
}

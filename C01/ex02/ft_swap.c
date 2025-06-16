/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:58:21 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/06/05 12:58:09 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int	*a, int	*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	x;
	int	y;

	x = 8;
	y = 2;
	printf("Valor inicial: x: %d, y: %d\n", x, y);
	ft_swap(&x, &y);
	printf("Apos função: x: %d, y: %d\n", x, y);
	return (0);
}

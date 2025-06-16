/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:17:10 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/06/05 13:07:41 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	x;
	int	y;
	int	div1;
	int	mod1;

	x = 9;
	y = 2;
	ft_div_mod(x, y, &div1, &mod1);
	printf("divisão = %d, módulo = %d", div1, mod1);
	return (0);
}

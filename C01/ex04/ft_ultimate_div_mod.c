/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:39:43 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/06/05 13:18:35 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int	*a, int	*b)
{
	int	div;
	int	mod;

	div = (*a) / (*b);
	mod = (*a) % (*b);
	*a = div;
	*b = mod;
}

int	main(void)
{
	int	a;
	int	b;

	a = 8;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("a (divisão)= %d, b(resto) %d", a, b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:04:50 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/06/05 12:21:47 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	char	*str;

	str = "Hello";
	ft_strlen(str);
	printf("lenght: %d\n", ft_strlen(str));
	printf("ou\n");
	int	n = ft_strlen(str);
	char	c = n + '0';
	write(1, &c, 1);
	return (0);
}

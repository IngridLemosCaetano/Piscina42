/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:18:47 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/06/19 14:56:43 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char	*s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n -1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}
/*
int	main(int argc, char	**argv)
{
	char	num;

	num = argv[3][0] - '1';
	if (argc == 4)
	{
		printf("%d\n", ft_strncmp(argv[1], argv[2], num));
	}
	return (0);
}*/

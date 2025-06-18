/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:36:29 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/06/18 16:46:26 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i +j] == to_find[j])
		{
			if (to_find[j +1] == '\0')
				return (&str [i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str = "The rain in Spain falls mainly on the plains.";
	char	*to_find = "ii";
	// ft_strstr(str, to_find);
	printf("%s", ft_strstr(str, to_find));
	return (0);
}*/

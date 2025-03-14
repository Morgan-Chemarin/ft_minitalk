/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:42:46 by dev               #+#    #+#             */
/*   Updated: 2025/03/14 00:40:59 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(const char *s)
{
	int				i;
	int				neg;
	unsigned long	result;

	i = 0;
	result = 0;
	neg = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > 9223372036854775807 && neg == 1)
			return (-1);
		if (result > 9223372036854775807 && neg == -1)
			return (0);
		result = result * 10 + (s[i] - 48);
		i++;
	}
	return (result * neg);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *source)
{
	char	*array;
	size_t	i;

	array = malloc(sizeof(char) * (ft_strlen(source) + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (source[i])
	{
		array[i] = source[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

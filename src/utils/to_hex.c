/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:16:04 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:44:55 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static char	converse(int n)
{
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return (n + '0');
}

static char	*reverse_str(char *old_str)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(old_str);
	new_str = malloc(len + 1);
	new_str[len] = '\0';
	i = 0;
	j = len - 1;
	while (i < len)
		new_str[i++] = old_str[j--];
	free(old_str);
	return (new_str);
}

static char	*concate(char *old_str, int remainder)
{
	char	*new_str;
	int		i;

	new_str = malloc(ft_strlen(old_str) + 2);
	if (old_str)
	{
		i = 0;
		while (old_str[i])
		{
			new_str[i] = old_str[i];
			i++;
		}
		new_str[i++] = converse(remainder);
		new_str[i] = '\0';
		free(old_str);
		return (new_str);
	}
	new_str[0] = converse(remainder);
	new_str[1] = '\0';
	return (new_str);
}

char	*to_hex(unsigned int n, int precision)
{
	char			*str;
	unsigned int	remainder;

	if (n == 0)
	{
		if (precision == 0)
		{
			str = malloc(1);
			str[0] = '\0';
			return (str);
		}
		str = malloc(2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = 0;
	while (n > 0)
	{
		remainder = n % 16;
		n = n / 16;
		str = concate(str, remainder);
	}
	str = reverse_str(str);
	return (str);
}

char	*to_hex_long(unsigned long int p)
{
	char				*str;
	unsigned long int	remainder;
	unsigned long int	n;

	n = p;
	if (n == 0)
	{
		str = malloc(2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = 0;
	while (n > 0)
	{
		remainder = n % 16;
		n = n / 16;
		str = concate(str, remainder);
	}
	str = reverse_str(str);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:26:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 16:20:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	find_count(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	get_digit(long int *n)
{
	long int	res;

	res = *n % 10 + '0';
	*n = *n / 10;
	return (res);
}

char	*ft_itoa(long int n, int precision)
{
	int				count;
	char			*str;
	int				i;
	long int		num;

	if (n == 0 && precision == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	num = (long int) n;
	if (n < 0)
		num = -num;
	count = find_count(n);
	str = malloc(count + 1);
	if (!str)
		return (0);
	i = count;
	str[i--] = '\0';
	while (count-- > 0)
		str[i--] = get_digit(&num);
	return (str);
}

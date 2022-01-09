/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:42:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:43:49 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static char	*str_toupper(char *str, char c)
{
	int	i;

	if (c != 'X')
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

void	print_x(t_flags *flags, va_list *args, int *count)
{
	int		len;
	int		value;
	char	*str;

	value = va_arg(*args, unsigned int);
	str = to_hex(value, flags->precision);
	len = ft_strlen(str);
	if (flags->precision > len)
		str = adjast_by_precision(str, &len, flags->precision);
	if (value != 0)
		str = adjast_by_sharp(str, &len, flags);
	*count += find_max(flags->width, len);
	str = str_toupper(str, flags->type);
	print_on_screen(str, len, flags);
	free(str);
}

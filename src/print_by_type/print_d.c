/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:40:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:44:09 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	print_d(t_flags *flags, va_list *args, int *count)
{
	int		len;
	int		value;
	char	*str;

	value = va_arg(*args, int);
	str = ft_itoa(value, flags->precision);
	len = ft_strlen(str);
	if (flags->precision > len)
		str = adjast_by_precision(str, &len, flags->precision);
	flags->base_len = len;
	str = adjast_by_width_z(str, &len, flags);
	str = adjast_by_sign(str, &len, value, flags);
	*count += find_max(flags->width, len);
	extra_space_condition(flags, value, count, len);
	print_on_screen(str, len, flags);
	free(str);
}

int	find_max(int width, int len)
{
	if (width > len)
		return (width);
	return (len);
}

void	extra_space_condition(t_flags *f, int value, int *count, int len)
{
	if (!f->width && !f->zero && f->space && value >= 0)
	{
		f->width = len + 1;
		*count = *count + 1;
	}
}

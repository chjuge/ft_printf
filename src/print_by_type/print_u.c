/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:41:23 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:43:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	print_u(t_flags *flags, va_list *args, int *count)
{
	int			len;
	long int	value;
	char		*str;

	value = va_arg(*args, unsigned int);
	str = ft_itoa(value, flags->precision);
	len = ft_strlen(str);
	if (flags->precision > len)
		str = adjast_by_precision(str, &len, flags->precision);
	*count += find_max(flags->width, len);
	print_on_screen(str, len, flags);
	free(str);
}

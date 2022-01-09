/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:43:05 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:43:27 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	print_s(t_flags *flags, va_list *args, int *count)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	if (len >= flags->width)
	{
		*count += len;
		while (len-- > 0)
			write(1, str++, 1);
		return ;
	}
	print_on_screen(str, len, flags);
	*count += flags->width;
}

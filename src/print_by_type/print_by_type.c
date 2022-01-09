/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:14:54 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 16:23:18 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	print_percent(void)
{
	char	p;

	p = '%';
	write (1, &p, 1);
	return (1);
}

void	print_by_type(t_flags *flags, va_list *args, int *count)
{
	char	c;

	c = flags->type;
	if (c == 'c')
		print_c(flags, args, count);
	if (c == 's')
		print_s(flags, args, count);
	if (c == 'd')
		print_d(flags, args, count);
	if (c == 'u')
		print_u(flags, args, count);
	if (c == 'x' || c == 'X')
		print_x(flags, args, count);
	if (c == 'p')
		print_p(flags, va_arg(*args, unsigned long), count);
	if (c == '%')
		*count += print_percent();
}

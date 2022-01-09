/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:37:35 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:43:09 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	print_c(t_flags *flags, va_list *args, int *count)
{
	int		width;
	char	c;

	c = va_arg(*args, int);
	width = 1;
	if (flags->width > 1)
		width = flags->width;
	*count += width;
	if (flags->minus)
	{
		write(1, &c, 1);
		while (width-- > 1)
			write(1, &(flags->current_space), 1);
		return ;
	}
	while (width-- > 1)
		write(1, &(flags->current_space), 1);
	write(1, &c, 1);
}

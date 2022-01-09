/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_on_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:32:38 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:24:17 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	print_on_screen(char *str, int len, t_flags *flags)
{
	int	diff;
	int	width;

	width = flags->width;
	diff = flags->width - len;
	if (flags->minus > 0)
	{
		while (width-- > diff)
			write(1, str++, 1);
		while (width-- >= 0)
			write(1, &(flags->current_space), 1);
	}
	else
	{
		while (diff-- > 0)
			write(1, &(flags->current_space), 1);
		while (len-- > 0)
			write(1, str++, 1);
	}
}

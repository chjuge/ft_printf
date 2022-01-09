/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:11:02 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:45:34 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static t_flags	init_struct(void)
{
	t_flags	flags;

	flags.sharp = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.type = '0';
	flags.current_space = ' ';
	flags.base_len = 0;
	return (flags);
}

t_flags	fill_struct(int *ind, const char *str)
{
	t_flags	flags;

	flags = init_struct();
	*ind += define_flags(str + *ind, &flags);
	*ind += define_width(str + *ind, &flags);
	*ind += define_precision(str + *ind, &flags);
	*ind += define_type(str + *ind, &flags);
	define_current_space(&flags);
	return (flags);
}

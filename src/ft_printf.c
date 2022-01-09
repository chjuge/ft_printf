/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:03:55 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 15:41:32 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		ind;
	int		len;
	int		count;

	if (!str)
		return (0);
	len = ft_strlen(str);
	va_start(args, str);
	ind = 0;
	count = 0;
	while (1)
	{
		ind += write_while(str + ind, &count);
		if (ind >= len)
			return (count);
		flags = fill_struct(&ind, str);
		if (flags.type == '0')
			return (ind);
		print_by_type(&flags, &args, &count);
	}
	va_end(args);
}

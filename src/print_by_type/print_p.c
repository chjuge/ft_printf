/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:44:04 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:43:17 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	print_p(t_flags *flags, unsigned long p, int *count)
{
	int					len;
	char				*str;

	str = to_hex_long(p);
	len = ft_strlen(str);
	flags->sharp = 1;
	if (flags->precision > len)
		str = adjast_by_precision(str, &len, flags->precision);
	str = adjast_by_sharp(str, &len, flags);
	*count += find_max(flags->width, len);
	print_on_screen(str, len, flags);
	free(str);
}

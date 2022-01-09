/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_for_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:05:56 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 16:19:41 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	check_for_flags(char c)
{
	if (c == '-')
		return (1);
	if (c == '+')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '0')
		return (1);
	if (c == '#')
		return (1);
	return (0);
}

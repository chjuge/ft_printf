/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_by_sharp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:04:30 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 16:19:34 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*adjast_by_sharp(char *old_str, int *len, t_flags *f)
{
	char	*new_str;
	int		width;

	if (!f->sharp)
		return (old_str);
	width = *len + 2;
	if (f->width >= width && f->current_space == '0')
		width = f->width;
	new_str = malloc(width + 1);
	copy_from_back(old_str, *len, new_str, width);
	new_str[width] = '\0';
	new_str[0] = '0';
	new_str[1] = 'x';
	*len = width;
	free(old_str);
	return (new_str);
}

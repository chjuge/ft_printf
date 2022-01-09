/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:21:33 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:23:56 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*adjast_by_precision(char *old_str, int *len, int precision)
{
	char	*new_str;
	int		diff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	diff = precision - *len;
	new_str = malloc(precision + 1);
	while (diff-- > 0)
		new_str[i++] = '0';
	while (j < *len)
		new_str[i++] = old_str[j++];
	new_str[i] = '\0';
	free(old_str);
	*len = precision;
	return (new_str);
}

char	*adjast_by_width_z(char *old_str, int *len, t_flags *f)
{
	char	*new_str;
	int		i;

	if (f->precision < 0 && !f->minus && f->width > *len && f->zero)
	{
		i = f->width - *len - 1;
		new_str = malloc(f->width + 1);
		copy_from_back(old_str, *len, new_str, f->width);
		while (i >= 0)
			new_str[i--] = '0';
		free(old_str);
		*len = f->width;
		return (new_str);
	}
	return (old_str);
}

static int	check_for_sign(t_flags *f)
{
	if (f->width <= f->base_len)
		return (1);
	if (!f->zero && f->precision < 0)
		return (1);
	if (f->current_space == ' ')
		return (1);
	return (0);
}

char	*adjast_by_sign(char *old_str, int *len, int value, t_flags *f)
{
	char	*new_str;

	if (value < 0 || f->plus > 0)
	{
		if (check_for_sign(f))
		{
			*len = *len + 1;
			new_str = malloc(*len + 1);
			new_str[0] = '+';
			if (value < 0)
				new_str[0] = '-';
			copy_from_back(old_str, *len - 1, new_str, *len);
			free(old_str);
			return (new_str);
		}
		old_str[0] = '+';
		if (value < 0)
			old_str[0] = '-';
	}
	return (old_str);
}

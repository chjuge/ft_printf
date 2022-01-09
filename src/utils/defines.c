/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:08:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 16:19:53 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	define_flags(const char *str, t_flags *flags)
{
	int		n;
	char	*s;

	s = ft_strdup(str);
	n = 0;
	while (check_for_flags(s[n]))
	{
		if (s[n] == '-')
			flags->minus++;
		if (s[n] == '+')
			flags->plus++;
		if (s[n] == ' ')
			flags->space++;
		if (s[n] == '0')
			flags->zero++;
		if (s[n] == '#')
			flags->sharp++;
		n++;
	}
	free(s);
	return (n);
}

int	define_width(const char *s, t_flags *flags)
{
	int		count;

	count = 0;
	flags->width = ft_atoi(s);
	while (ft_isdigit(s[count]))
		count++;
	return (count);
}

int	define_precision(const char *str, t_flags *flags)
{
	int		count;
	char	*s;

	s = ft_strdup(str);
	count = 0;
	if (s[count] == '.')
	{
		count++;
		flags->precision = ft_atoi(s + count);
		while (ft_isdigit(s[count]))
			count++;
	}
	free(s);
	return (count);
}

int	define_type(const char *s, t_flags *flags)
{
	if (s[0] == 'c')
		flags->type = 'c';
	if (s[0] == 's')
		flags->type = 's';
	if (s[0] == 'p')
		flags->type = 'p';
	if (s[0] == 'u')
		flags->type = 'u';
	if (*s == 'x')
		flags->type = 'x';
	if (s[0] == 'X')
		flags->type = 'X';
	if (s[0] == 'i' || s[0] == 'd')
		flags->type = 'd';
	if (s[0] == '%')
		flags->type = '%';
	if (flags->type == '0')
		return (0);
	return (1);
}

void	define_current_space(t_flags *flags)
{
	if (flags->type != 's' && flags->type != 'c')
		if (flags->precision >= 0)
			return ;
	if (flags->minus > 0)
		return ;
	if (flags->zero > 0)
		flags->current_space = '0';
}

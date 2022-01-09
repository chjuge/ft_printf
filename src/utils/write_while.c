/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_while.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:13:41 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 16:20:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	write_while(const char *str, int *count)
{
	int		i;
	char	*s;

	s = ft_strdup(str);
	i = 0;
	while (s[i] && s[i] != '%')
	{
		write(1, &s[i], 1);
		i++;
	}
	*count += i;
	if (s[i] != '\0')
		i++;
	if (s)
		free(s);
	return (i);
}

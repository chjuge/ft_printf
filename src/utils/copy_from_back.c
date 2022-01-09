/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_from_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:05:52 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 16:19:48 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*copy_from_back(char *old_str, int len1, char *new_str, int len2)
{
	int	i;
	int	j;

	j = len1 - 1;
	i = len2 - 1;
	while (j >= 0)
		new_str[i--] = old_str[j--];
	while (i > 1)
		new_str[i--] = '0';
	return (new_str);
}

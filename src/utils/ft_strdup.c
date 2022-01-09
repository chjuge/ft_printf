/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:37:58 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 16:20:25 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

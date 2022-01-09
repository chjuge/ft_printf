/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:30:56 by mproveme          #+#    #+#             */
/*   Updated: 2022/01/09 17:41:51 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_flags
{
	int		sharp;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		width;
	int		precision;
	char	type;
	char	current_space;
	int		base_len;
}	t_flags;

int		ft_printf(const char *str, ...);
int		write_while(const char *str, int *count);
t_flags	fill_struct(int *ind, const char *str);
void	print_by_type(t_flags *flags, va_list *args, int *count);
void	print_c(t_flags *flags, va_list *args, int *count);
void	print_s(t_flags *flags, va_list *args, int *count);
void	print_d(t_flags *flags, va_list *args, int *count);
void	print_u(t_flags *flags, va_list *args, int *count);
void	print_x(t_flags *flags, va_list *args, int *count);
void	print_p(t_flags *flags, unsigned long p, int *count);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
char	*ft_itoa(long int n, int precision);
int		ft_atoi(const char *str);
int		check_for_flags(char c);
int		define_flags(const char *str, t_flags *flags);
int		define_width(const char *s, t_flags *flags);
int		define_precision(const char *str, t_flags *flags);
int		define_type(const char *s, t_flags *flags);
void	define_current_space(t_flags *flags);
char	*copy_from_back(char *old_str, int len1, char *new_str, int len2);
char	*adjast_by_sharp(char *old_str, int *len, t_flags *f);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*adjast_by_precision(char *old_str, int *len, int precision);
char	*adjast_by_width_z(char *old_str, int *len, t_flags *f);
char	*adjast_by_sign(char *old_str, int *len, int value, t_flags *f);
void	print_on_screen(char *str, int len, t_flags *flags);
int		find_max(int width, int len);
void	extra_space_condition(t_flags *f, int value, int *count, int len);
char	*to_hex(unsigned int n, int precision);
char	*to_hex_long(unsigned long int p);
#endif

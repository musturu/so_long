/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:08:33 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 16:21:09 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct s_format
{
	char	*flags;
	int		width;
	int		precision;
	int		pflag;
	char	conversion;
}	t_format;

int			countdig(long int num, int base);
int			ft_printf(const char *str, ...);
char		*get_format(const char *str);
t_format	read_format(char *format);
int			is_accepted_flag(int c);
int			is_accepted_conv(int c);
int			is_signed(int c, t_format fmt);
int			need_space(int c, t_format ftm);
void		str_c(t_format format, int c, int *count);
void		str_perc(int *count);
void		str_unsnum(t_format format, unsigned int num, int *count);
void		str_s(t_format format, char *str, int *count);
void		ft_putstr_count(char *str, int *count, int len);
void		str_ptrnum(t_format format, void *ptr, int *count);
void		str_num(t_format format, int num, int *count);
void		str_hexnum(t_format format, unsigned int num, int *count);
int			countd(unsigned long int num, int base);
void		ft_putchar_count(char c, int *count);
char		*ft_itoa_base(unsigned long int number, char *base);
char		*need_sign(t_format fmt, int c);
char		needed_pad(t_format fmt);
int			get_base(t_format fmt);
void		put_sign(char *fmt, int num, char *dest);
void		write_num(t_format fmt, int in, unsigned long int num, char *dest);
#endif

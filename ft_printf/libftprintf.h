/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 14:36:07 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/17 13:08:24 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct	s_stats
{
	char	conversion;
	int		is_minus;
	int		is_zero;
	int		is_precision;
	int		width;
	int		precision;
	int		len;
	int		error;
}				t_stats;

int				ft_printf(const char *str, ...);

void			ft_putchar(t_stats *data, unsigned char c);
void			ft_putstr(t_stats *data, const char *str);
void			ft_putc_len(t_stats *data, unsigned char c, int sign, int len);
void			ft_putnbr(t_stats *data, int n, int arg_len, int min_int);
int				check_zero_arg(t_stats *data, int n);

void			ft_putnbr_u(t_stats *data, unsigned int n);
void			ft_puthex(t_stats *data, unsigned int n, char *hex_table);
void			ft_putstrl(t_stats *data, char *str, int len);
void			ft_puthex_u(t_stats *data, unsigned long n, char *hex_table);
void			ft_putptr(t_stats *data, void *ptr);

void			init_struct(t_stats *data);
int				get_data(t_stats *data, const char *str, va_list args);

int				get_str_len(char *argument);
int				get_int_len(int argument);
int				get_u_int_len(unsigned int argument);
int				get_hex_len(unsigned int argument);
int				get_ptr_len(t_stats *data, void *argument);

void			get_width_precision
				(t_stats *data, va_list args, const char *str, int *i);
void			get_asterisk(t_stats *data, va_list args, int *i);
void			get_number(t_stats *data, const char *str, int *i);
void			get_other_flags(t_stats *data, char c, int *i);

int				is_conversion(char c);
void			get_conversion(t_stats *data, va_list args);

void			print_d_i(t_stats *data, va_list args);
void			print_d_i_minus
				(t_stats *data, int argument, int arg_len, int negative);
void			print_d_i_zero
				(t_stats *data, int argument, int arg_len, int negative);
void			print_d_i_width_precision
				(t_stats *data, int argument, int arg_len, int negative);

void			print_u(t_stats *data, va_list args);
void			print_u_minus(t_stats *data, int argument, int arg_len);
void			print_u_zero(t_stats *data, int argument, int arg_len);
void			print_u_width_precision
				(t_stats *data, int argument, int arg_len);

void			print_x(t_stats *data, va_list args);
void			print_x_minus(t_stats *data, int argument, int arg_len);
void			print_x_zero(t_stats *data, int argument, int arg_len);
void			print_x_width_precision
				(t_stats *data, int argument, int arg_len);

void			print_p(t_stats *data, va_list args);
void			print_p_minus(t_stats *data, void *argument, int arg_len);
void			print_p_zero(t_stats *data, void *argument, int arg_len);
void			print_p_width(t_stats *data, void *argument, int arg_len);

void			print_c(t_stats *data, va_list args);
void			print_percentage(t_stats *data);
void			print_s(t_stats *data, va_list args);
void			print_s_flags(t_stats *data, char *argument, int len);

#endif

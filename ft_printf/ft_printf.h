/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:56:30 by ahaidour          #+#    #+#             */
/*   Updated: 2023/01/11 23:58:03 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		handle_conversion(int i, const char *s, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(const char *s);
int		ft_putnbr_hex(unsigned long n, char *base);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr(long n, char *base);

#endif

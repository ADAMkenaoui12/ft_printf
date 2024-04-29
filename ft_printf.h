/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:55:14 by kadam             #+#    #+#             */
/*   Updated: 2024/01/08 11:38:16 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
size_t	ft_strlen(const char *s);
int		check_len_int(int n);
size_t	check_len_hexa(size_t n, int base);
void	ft_hexa_lower(unsigned int n);
void	ft_hexa_upper(unsigned int n);
void	ft_hexa_ptr(size_t n);
int		ft_printf(const char *format, ...);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:55:11 by kadam             #+#    #+#             */
/*   Updated: 2024/01/08 11:37:34 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_reverse_hexa(char *buffer, int len)
{
	len--;
	while (len >= 0)
	{
		ft_putchar(buffer[len]);
		len--;
	}
}

void	ft_hexa_lower(unsigned int n)
{
	int		digit;
	char	buffer[10];
	int		i;

	digit = 0;
	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (n > 0)
	{
		digit = n % 16;
		if (digit <= 9)
			buffer[i] = digit + '0';
		else if (digit >= 10)
		{
			buffer[i] = (digit - 10) + 'a';
		}
		i++;
		n = n / 16;
	}
	ft_reverse_hexa(buffer, i);
}

void	ft_hexa_upper(unsigned int n)
{
	int		digit;
	char	buffer[10];
	int		i;

	digit = 0;
	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
	}
	while (n > 0)
	{
		digit = n % 16;
		if (digit <= 9)
		{
			buffer[i] = digit + '0';
		}
		else if (digit >= 10)
		{
			buffer[i] = (digit - 10) + 'A';
		}
		i++;
		n = n / 16;
	}
	ft_reverse_hexa(buffer, i);
}

void	ft_hexa_ptr(size_t n)
{
	char	*buffer;

	buffer = "0123456789abcdef";
	if (n >= 16)
	{
		ft_hexa_ptr(n / 16);
		ft_putchar(buffer[n % 16]);
	}
	else
	{
		ft_putchar(buffer[n]);
	}
}

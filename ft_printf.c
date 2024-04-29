/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:33:47 by kadam             #+#    #+#             */
/*   Updated: 2024/01/11 14:51:24 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_string(va_list args, char format)
{
	char	*str;
	char	c;

	if (format == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		else
		{
			ft_putstr(str);
			return (ft_strlen(str));
		}
	}
	else if (format == 'c')
	{
		c = va_arg(args, int);
		ft_putchar(c);
	}
	else if (format == '%')
		ft_putchar('%');
	return (1);
}

static int	ft_number(va_list args, char format)
{
	int				n;
	unsigned int	nb;

	if (format == 'd' || format == 'i')
	{
		n = va_arg(args, int);
		ft_putnbr(n);
		return (check_len_int(n));
	}
	else if (format == 'u')
	{
		nb = va_arg(args, unsigned int);
		ft_putunbr(nb);
		return (check_len_hexa(nb, 10));
	}
	return (0);
}

static int	hexa_upper_lower(va_list args, char format)
{
	unsigned int	num;
	unsigned int	nub;
	void			*ptr;
	size_t			number;

	if (format == 'x')
	{
		num = va_arg(args, unsigned int);
		return (ft_hexa_lower(num), check_len_hexa(num, 16));
	}
	else if (format == 'X')
	{
		nub = va_arg(args, unsigned int);
		ft_hexa_upper(nub);
		return (check_len_hexa(nub, 16));
	}
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		ft_putstr("0x");
		number = (size_t)ptr;
		ft_hexa_ptr(number);
		return (2 + check_len_hexa(number, 16));
	}
	return (0);
}

static int	ft_function(const char *format, va_list args, int *counter)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (*counter);
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
				*counter += ft_string(args, format[i]);
			else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
				*counter += ft_number(args, format[i]);
			else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
				*counter += hexa_upper_lower(args, format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			(*counter)++;
		}
		i++;
	}
	return (*counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		c;
	int		counter;

	counter = 0;
	va_start(args, format);
	if (write(1, "", 0) == -1)
		return (-1);
	c = ft_function(format, args, &counter);
	va_end(args);
	return (c);
}

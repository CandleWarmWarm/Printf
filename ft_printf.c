/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 10:57:22 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/09/06 05:56:27 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_after(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args,void *), 1));
	else if (c == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_print_unsigned_dec(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_print_hex_lower(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_print_hex_upper(va_arg(args, unsigned int), 1));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		count;

	len = 0;
	count = 0;
	va_start(args, str);
	while (str[len])
	{
		if (str[len] == '%')
		{
			len++;
			count += check_after(str[len], args);
		}
		else
			ft_putchar_fd(str[len], 1);
		len++;
		count++;
	}
	va_end(args);
	return (len);
}

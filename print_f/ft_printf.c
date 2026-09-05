/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 10:57:22 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/09/06 01:03:12 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	check_after(char c, va)
{
	if (c == 'c')
		ft_putchar_fd(c, 1);
	else if (c == 's')
		print_string();
	else if (c == 'p')
		prinr_pointer();
	else if (c == 'd')
		print_decimal();
	else if (c == 'i')
		print_decimal();
	else if (c == 'u')
		print_unsigned_dec();
	else if (c == 'x')
		print_hex_lower();
	else if (c == 'X')
		print_hex_upper();
	else if (c == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (str[len])
	{
		if (str[len] == '%')
		{
			len++;
			va_list(args,)
			check_after();
		}
		else
			ft_putchar_fd(str[len], 1);
		len++;
	}
	va_end(args);
	return (len);
}

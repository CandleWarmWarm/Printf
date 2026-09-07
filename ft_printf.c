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

#include "libft/libft.h"
#include "ft_printf.h"

void	check_after(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, (char *)), 1);
	else if (c == 'p')
		// print_pointer(va_arg(args,(void *)), 1);
	else if (c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_print_unsigned_dec(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		ft_print_hex_lower(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		ft_print_hex_upper(va_arg(args, unsigned int), 1);
	else if (c == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		count;

	len = 0;
	va_start(args, str);
	while (str[len])
	{
		if (str[len] == '%')
		{
			len++;
			check_after(str[len], args);
		}
		else
			ft_putchar_fd(str[len], 1);
		len++;
	}
	va_end(args);
	return (len);
}

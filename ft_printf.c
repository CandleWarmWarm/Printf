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

static int	check_after(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(*args, void *), 1));
	else if (c == 'd')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	else if (c == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	else if (c == 'u')
		return (ft_print_unsigned_dec(va_arg(*args, unsigned int), 1));
	else if (c == 'x')
		return (ft_print_hex_lower(va_arg(*args, unsigned int), 1));
	else if (c == 'X')
		return (ft_print_hex_upper(va_arg(*args, unsigned int), 1));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

//dont need check_before and cant_found_case function just 
// put it cuz might need it in future can let it be undefined behaviour

static int	check_before(const char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	s = "cspdiuxX%";
	while (str[i])
	{
		j = 0;
		if (str[i] == '%')
		{
			while (s[j])
			{
				if (str[i + 1] == s[j])
					return (1);
				j++;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

static int	cant_found_case(void)
{
	write(2, "\n", 1);
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (check_before(str) == 0)
		return (cant_found_case());
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += check_after(*str, &args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}

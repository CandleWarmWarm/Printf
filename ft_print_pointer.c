/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 02:50:31 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/09/08 02:50:31 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(unsigned long long adr, int fd)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (adr >= 16)
		count += print_hex(adr / 16, fd);
	ft_putchar_fd(base[adr % 16], fd);
	count++;
	return (count);
}

int	ft_print_pointer(void *ptr, int fd)
{
	unsigned long long	address;
	int					count;

	count = 0;
	if (ptr == NULL)
	{
		write(fd,"(nil)",5);
		return (5);
	}
	address = (unsigned long long)ptr;
	count += ft_putstr_fd("0x",fd);
	count += print_hex(address, fd);
	return (count);
}

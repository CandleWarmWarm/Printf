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

#include "libft/libft.h"

static void	print_hex(unsigned long long adr, int fd)
{
	char *base;

	base = "0123456789abcdef"
	if (nbr >= 16)
		print_hex(nbr / 16, fd);
	ft_putchar_fd(base[nbr % 16], fd);
}

void	ft_pirnt_pointer(void *ptr, int fd)
{
	unsigned long long	address;

	address = (unsigned long long)ptr;
	ft_putstr_fd("0x",fd);
	print_hex(address, fd);
}

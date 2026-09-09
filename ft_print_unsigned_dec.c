/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_dec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 00:00:51 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/09/08 00:00:51 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_dec(unsigned int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_print_unsigned_dec(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
	count++;
	return (count);
}

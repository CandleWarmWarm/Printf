/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 00:19:23 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/09/08 00:19:23 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_print_hex_upper(unsigned int nbr, int fd)
{
	char *base;

	base = "0123456789ABCDEF"
	if (nbr >= 16)
		ft_print_hex_upper(nbr / 16, fd)
	ft_putchar_fd(base[nbr % 16], fd);
}

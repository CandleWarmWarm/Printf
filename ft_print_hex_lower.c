/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 00:19:26 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/09/08 00:19:26 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_print_hex_lower(unsigned int nbr, int fd)
{
	char *base;

	base = "0123456789abcdef"
	if (nbr >= 16)
		ft_print_hex_lower(nbr / 16, fd)
	ft_putchar_fd(base[nbr % 16], fd);
}

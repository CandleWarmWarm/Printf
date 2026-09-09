/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 10:59:42 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/09/05 11:19:07 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_hex_lower(unsigned int nbr, int fd);
int	ft_print_hex_upper(unsigned int nbr, int fd);
int	ft_print_pointer(void *ptr, int fd);
int	ft_print_unsigned_dec(unsigned int nbr, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_printf(const char *str, ...);

#endif
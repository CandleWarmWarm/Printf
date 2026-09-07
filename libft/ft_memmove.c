/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:37:31 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/08/30 20:10:41 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_forward(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void	copy_backward(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		i--;
		d[i] = s[i];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL || src == NULL)
		return (NULL);
	d = dst;
	s = src;
	if (d < s)
		copy_forward(d, s, n);
	else
		copy_backward(d, s, n);
	return (dst);
}

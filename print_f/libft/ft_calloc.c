/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:54:51 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/08/29 21:42:51 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > SIZE_MAX / size)
		return (NULL);
	cal = malloc(count * size);
	if (cal == NULL)
		return (NULL);
	ft_bzero(cal, (size * count));
	return (cal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 11:20:27 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/08/29 18:47:16 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c_check;

	i = 0;
	c_check = c;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == c_check)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

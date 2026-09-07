/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 09:54:16 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/08/29 18:46:33 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c_check;

	i = 0;
	c_check = c;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char)s[i] == c_check)
			return ((char *)&s[i]);
		i++;
	}
	if (c_check == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

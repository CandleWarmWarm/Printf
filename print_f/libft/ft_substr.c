/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:49:30 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/08/25 15:49:30 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[i + (size_t)start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

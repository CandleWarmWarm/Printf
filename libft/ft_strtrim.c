/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:15:59 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/08/26 13:15:59 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (s1[start] && check_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (start < end && check_set(s1[end - 1], set))
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (trimmed == NULL)
		return (NULL);
	while (start + i < end)
	{
		trimmed[i] = s1[i + start];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

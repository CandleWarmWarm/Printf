/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:42:43 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/08/29 23:12:21 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char limit)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == limit)
		i++;
	while (s[i])
	{
		if (s[i] != limit && (i == 0 || s[i - 1] == limit))
			count++;
		i++;
	}
	return (count);
}

static int	fill_box(char **box, const char *s, char c)
{
	int	end;
	int	i;

	i = 0;
	end = 0;
	while (s[end] && s[end] != c)
		end++;
	*box = malloc(sizeof(char) * (end + 1));
	if (*box == NULL)
		return (-1);
	while (i < end)
	{
		(*box)[i] = s[i];
		i++;
	}
	(*box)[i] = '\0';
	return (i);
}

static void	free_box(char **box, int n_box)
{
	int	i;

	i = 0;
	while (i < n_box)
	{
		free(box[i]);
		i++;
	}
	free(box);
}

static int	fill_words(char **box, char const *s, char c)
{
	int	i;
	int	n_box;
	int	len;

	i = 0;
	n_box = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			len = fill_box(&box[n_box], &s[i], c);
			if (len == -1)
			{
				free_box(box, n_box);
				return (-1);
			}
			n_box++;
			i += len;
		}
	}
	box[n_box] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**box;

	if (s == NULL)
		return (NULL);
	box = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (box == NULL)
		return (NULL);
	if (fill_words(box, s, c) == -1)
		return (NULL);
	return (box);
}

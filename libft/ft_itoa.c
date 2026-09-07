/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:12:33 by nsomjaip          #+#    #+#             */
/*   Updated: 2026/08/26 22:12:33 by nsomjaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long n)
{
	int		digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

static void	rev_itoa_str(char **str, long n, int sign, int end)
{
	int		i;
	char	temp;

	i = 0;
	while (n > 0)
	{
		(*str)[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (sign < 0)
	{
		(*str)[i] = '-';
		i++;
	}
	(*str)[i] = '\0';
	i = 0;
	while (i < end)
	{
		temp = (*str)[i];
		(*str)[i] = (*str)[end];
		(*str)[end] = temp;
		i++;
		end--;
	}
}

static void	zero_case(char **str)
{
	(*str)[0] = '0';
	(*str)[1] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	int		sign;
	long	numb;

	sign = 1;
	numb = n;
	if (numb < 0)
	{
		sign *= -1;
		numb *= -1;
	}
	digit = count_digit(numb);
	if (sign == -1)
		digit++;
	str = malloc(sizeof(char) * (digit + 1));
	if (str == NULL)
		return (NULL);
	if (numb == 0)
		zero_case(&str);
	else
		rev_itoa_str(&str, numb, sign, digit - 1);
	return (str);
}

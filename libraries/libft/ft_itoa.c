/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytanis <ytanis@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:14:54 by ytanis            #+#    #+#             */
/*   Updated: 2022/08/05 19:15:02 by ytanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char	*array(char *str, int n, int len)
{
	while (n)
	{
		*(str + len--) = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		*str = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(str, "-2147483648", len + 1);
			return (str);
		}
		str[0] = '-';
		n *= -1;
	}
	*(str + len--) = '\0';
	return (array(str, n, len));
}

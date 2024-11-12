/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:44 by mfahmi            #+#    #+#             */
/*   Updated: 2024/10/31 11:45:37 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nm(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nm)
{
	char	*str;
	int		i;
	int		is_neg;
	long	n;

	n = nm;
	i = count_nm(n) - 1;
	is_neg = 0;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	if (n < 0)
	{
		str[is_neg++] = '-';
		n = -n;
	}
	while (i >= is_neg)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (str);
}
/*int main ()
{
  printf("%s", ft_itoa(-2147483648));
}*/

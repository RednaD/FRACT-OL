/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flotoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:43:25 by arusso            #+#    #+#             */
/*   Updated: 2018/09/27 18:30:47 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

char		*ft_flotoa(long double dbl)
{
	int		i;
	int		dc;
	char	*dest;
	char	*tmp;
	char	*dec;

	i = dbl;
	dc = (dbl - i) * 1000;
	if (dbl < 0 && dbl > -1)
		dest = ft_strdup("-");
	else
		dest = ft_strnew(0);
	dbl = fabs((float)dbl);
	tmp = dest;
	dec = ft_itoa(i);
	dest = ft_strjoin(dest, dec);
	free(tmp);
	tmp = dest;
	dest = ft_strjoin(dest, ",");
	ft_free(tmp, dec);
	tmp = dest;
	dec = ft_itoa(fabs((float)(dc)));
	dest = ft_strjoin(dest, dec);
	ft_free(tmp, dec);
	return (dest);
}

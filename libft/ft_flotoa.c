/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flotoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:43:25 by arusso            #+#    #+#             */
/*   Updated: 2018/09/17 17:29:25 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flotoa(long double dbl)
{
	int		i;
	int		dc;
	char	*dest;
	char	*tmp;

	i = dbl;
	dc = (dbl - i) * 1000;
	if (dbl < 0)
		dest = ft_strdup("-");
	else
		dest = ft_strnew(0);
	tmp = dest;
	dest = ft_strjoin(dest, ft_itoa(i));
	free(tmp);
	tmp = dest;
	dest = ft_strjoin(dest, ",");
	free(tmp);
	tmp = dest;
	dest = ft_strjoin(dest, ft_itoa(fabs((float)dc)));
	free(tmp);
	return (dest);
}

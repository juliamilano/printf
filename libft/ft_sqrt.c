/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrubach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:56:40 by ytrubach          #+#    #+#             */
/*   Updated: 2018/11/01 16:56:42 by ytrubach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;
	int res;

	if (nb < 0)
		return (0);
	i = 1;
	while (i < nb)
	{
		res = nb / i;
		if (nb == (res * res))
		{
			return (res);
		}
		i++;
	}
	return (0);
}

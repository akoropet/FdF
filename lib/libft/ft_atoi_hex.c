/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:30:41 by akoropet          #+#    #+#             */
/*   Updated: 2019/03/25 21:57:51 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_hex(char *s)
{
	int		len;
	int		res;
	int		ex;

	res = 0;
	ex = 1;
	len = ft_strlen(s) - 1;
	while (s[len] != 'x')
	{
		if (s[len] <= 'f' && s[len] >= 'a')
			res += ex * (s[len] - 'a' + 10);
		else if (s[len] <= 'F' && s[len] >= 'A')
			res += ex * (s[len] - 'A' + 10);
		else if (s[len] <= '9' && s[len] >= '0')
			res += ex * (s[len] - '0');
		else
			return (-1);
		ex *= 16;
		len--;
	}
	return (res);
}

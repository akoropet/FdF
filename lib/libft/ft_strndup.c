/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:29:44 by akoropet          #+#    #+#             */
/*   Updated: 2019/03/22 16:40:10 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*q;

	i = 0;
	while (str[i] && str[i] != n)
		i++;
	q = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != n)
	{
		q[i] = str[i];
		i++;
	}
	q[i] = '\0';
	return (q);
}

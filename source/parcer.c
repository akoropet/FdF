/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:51:08 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:30:36 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*join_to_buf(char *buf, char *str)
{
	char	*tmp;

	tmp = buf;
	buf = ft_strjoin(tmp, str);
	ft_strdel(&tmp);
	tmp = buf;
	buf = ft_strjoin(tmp, "!");
	ft_strdel(&tmp);
	return (buf);
}

int		valid_color(char *str, int *i)
{
	int		n;

	n = 0;
	if (str[(*i)++] == '0' && str[(*i)++] == 'x')
	{
		if (str[(*i)] == ' ' || str[(*i)] == '\t' || str[(*i)] == '\0')
			return (0);
		while (str[(*i)] && (ft_isdigit(str[(*i)]) || (str[(*i)] >= 65 &&
			str[(*i)] <= 70) || (str[(*i)] >= 97 && str[(*i)] <= 102)))
		{
			n++;
			(*i)++;
		}
		return (n <= 6 && (str[(*i)] == ' ' || str[(*i)] == '\t' ||
			str[(*i)] == '\0'));
	}
	return (0);
}

int		valid_line(t_fdf *fdf, char *str, int count)
{
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (str[i] == ',' && ++i && !valid_color(str, &i))
			return (0);
		if (!str[i] || (str[i] == ' '))
			count++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] && (str[i] != '-' && !ft_isdigit(str[i]) && str[i] != '+'))
			return (0);
	}
	fdf->size_x = !fdf->size_x ? count : fdf->size_x;
	return (fdf->size_x == count);
}

int		parcer(t_fdf *fdf, char *file)
{
	char	*str;
	char	*buf;
	int		fd;

	str = NULL;
	buf = ft_memalloc(1);
	if ((fd = open(file, O_RDONLY)) <= 0)
		return (0);
	while (get_next_line(fd, &str) > 0)
	{
		if (!valid_line(fdf, str, 0))
		{
			ft_strdel(&buf);
			break ;
		}
		fdf->size_y++;
		buf = join_to_buf(buf, str);
		ft_strdel(&str);
	}
	close(fd);
	ft_strdel(&str);
	if (buf == NULL || !ft_strlen(buf))
		return (0);
	fdf->map = buf;
	return (1);
}

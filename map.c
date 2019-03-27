/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:15:49 by akoropet          #+#    #+#             */
/*   Updated: 2019/03/27 18:26:22 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(t_fdf *fdf, int j, int i, char *str)
{
	int		k;
	char	*color;

	k = 0;
	while (str[k] && (str[k] != ' ' && str[k] != '\t'))
		k++;
	if (str[k] == ' ')
		color = ft_strndup(str, ' ');
	else if (str[k] == '\t')
		color = ft_strndup(str, '\t');
	else
		color = ft_strdup(str);
	fdf->coord[j][i].color = ft_atoi_hex(color);
	ft_strdel(&color);
}

void	add_coord(t_fdf *fdf, char **str, int i, int j)
{
	int		count;
	int		k;

	count = 0;
	k = 0;
	fdf->coord[j][i].x = i;
	fdf->coord[j][i].y = j;
	while (str[j][k] && count < i)
	{
		if (str[j][k] == '-' || str[j][k] == '+' || ft_isdigit(str[j][k]))
			count++;
		while (str[j][k] && (str[j][k] != ' ' && str[j][k] != '\t'))
			k++;
		k++;
	}
	fdf->coord[j][i].z = ft_atoi(str[j] + k);
	while (str[j][k] && (str[j][k] != ' ' && str[j][k] != '\t') &&
		str[j][k] != ',')
		k++;
	if (str[j][k] == ',')
		color(fdf, j, i, str[j] + k);
	else if (!fdf->coord[j][i].color)
		fdf->coord[j][i].color = 0xFFFFFF;
}

void	reset_coord(t_fdf *fdf, int i, int j)
{
	fdf->coord[j][i].x = 0;
	fdf->coord[j][i].y = 0;
	fdf->coord[j][i].z = 0;
	fdf->coord[j][i].color = 0;
}

void	recreate_map(t_fdf *fdf)
{
	char	**str;
	int		i;
	int		j;

	j = 0;
	str = ft_strsplit(fdf->map, '!');
	while (j < fdf->size_y)
	{
		i = 0;
		while (i < fdf->size_x)
		{
			add_coord(fdf, str, i, j);
			i++;
		}
		j++;
	}
	i = 0;
	while (i < fdf->size_y)
		ft_strdel(&str[i++]);
	free(str);
}

void	create_map(t_fdf *fdf)
{
	char	**str;
	int		i;
	int		j;

	j = 0;
	str = ft_strsplit(fdf->map, '!');
	fdf->coord = (t_coord **)malloc(sizeof(t_coord *) * fdf->size_y);
	while (j < fdf->size_y)
	{
		i = 0;
		fdf->coord[j] = (t_coord *)malloc(sizeof(t_coord) * fdf->size_x);
		while (i < fdf->size_x)
		{
			reset_coord(fdf, i, j);
			add_coord(fdf, str, i, j);
			i++;
		}
		j++;
	}
	i = 0;
	while (i < fdf->size_y)
		ft_strdel(&str[i++]);
	free(str);
}
